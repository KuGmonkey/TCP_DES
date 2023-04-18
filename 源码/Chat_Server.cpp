#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<winsock2.h>
#include "DES.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

const int max_len = 10000;  //服务器端接受的最大消息长度
//char* recvBuf = new char[max_len];  //接收缓冲区
//int msg_len;  //接收到的消息长度
int client_num = 0;
vector<SOCKET> clients;

//获取当前系统日期和时间
char* get_time()
{
	time_t now = time(0); // 把 now 转换为字符串形式 
	char* dt = ctime(&now);
	return dt;
}

//与客户端交互
DWORD WINAPI Server_Handle(LPVOID lparam)
{
	SOCKET Client_Socket = (SOCKET)(LPVOID)lparam;
	//三次握手
	//向用户发送连接成功提示
	string success_flag = "Connect Success!";
	send(Client_Socket, success_flag.c_str(), success_flag.length(), 0);  //c_str()函数返回指针

	char* recvBuf = new char[max_len];  //新建接收缓冲区
	int recv_len;  //接收信息的长度
	//接收客户端连接成功的信息
	recv_len = recv(Client_Socket, recvBuf, max_len, 0);
	//接收的字符串最后加结束符，便于输出
	recvBuf[recv_len] = 0x00;
	cout << recvBuf << endl;

	//转发阶段,接收user的消息，并转发给群聊的其他用户
	while (1)
	{
		//接收消息
		recv_len = recv(Client_Socket, recvBuf, max_len, 0);
		if (recv_len > 0)
		{
			recvBuf[recv_len] = 0x00;
			//保存用户的消息
			string message;
			for (int i = 0; i < recv_len; i++)
				message = message + recvBuf[i];

			//解密
			message = Decode(message);

			//用户发出消息在服务端的日志记录
			//正常发消息
			if (message != "exit")
			{
				cout <<"Forward message: "<< message;
				cout << endl;
				//转发消息
				message = Encode(message);
				for (int i = 0; i < client_num; i++)
					if (Client_Socket != clients[i])
					{
						send(clients[i], message.c_str(), message.length(), 0);
					}
			}
			//user退出
			else
			{
				//关闭当前线程
				break;
			}
		}
		else
			break;
	}
	return 0;
}

int main()
{
	int state1, state2, state3;  //存各函数返回值

	WORD wVersionRequested = MAKEWORD(2, 2); //调用者希望使用的socket的最高版本
	WSADATA wsaData;  //可用的Socket的详细信息，通过WSAStartup函数赋值
	//初始化Socket DLL，协商使用的Socket版本；初始化成功则返回0，否则为错误的int型数字
	state1 = WSAStartup(wVersionRequested, &wsaData);

	//创建一个Socket，并绑定到一个特定的传输层服务
	//参数 AF_INET：IPv4地址类型；SOCK_STREAM：流式套接字；IPPROTO_TCP：使用TCP传输层协议
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addrSrv;  //指向本地进程起始地址的指针，后边包含IP地址和端口号，后转为SOCKETADDR类型的指针，SOCKETADDR像是SOCKETADDR_IN的封装（把除了ip地址类型之外的成员变量都封装到一起了）
	addrSrv.sin_family = AF_INET;  //IPv4地址类型
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //设置本机ip为服务器ip
	addrSrv.sin_port = htons(1234);   //端口号为1234
	//将一个本地地址绑定到指定的Socket，正确则返回0，否则返回SOCKET_ERROR
	//参数 sockSrv：socket描述符，这里即服务器的套接字端口；namelen：地址长度，为sockaddr结构的长度
	state2 = bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	//使socket进入监听状态，监听远程连接是否到来
	//参数 socketSrv：socket描述符；backlog：连接等待队列的最大长度，这里为20
	state3 = listen(sockSrv, 20);
	if (state3 == 0)
	{
		cout << "[log]" << get_time() << ">>>" << "Listening..." << endl;
	}
	else
	{
		cout << "[error]" << get_time() << ">>>" << "Error！" << endl;
	}

	while (1)
	{
		SOCKADDR_IN addrClient;   //客户端地址
		int len = sizeof(SOCKADDR);   //地址长度
		//接受一个特定socket请求等待队列中的连接请求，此函数运行后进入阻塞状态，直到连接请求到来。连接成功返回新连接的socket描述符，错误返回INVALID_SOCKET
		//参数 sockSrv服务器端socket描述符：addrClient：客户端地址起始位置指针：len；地址长度
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
		//新用户入队列
		clients.push_back(sockConn);
		client_num++;

		//日志信息
		cout << "[log]" << get_time() << ">>>" << "server: got connection from " << addrClient.sin_addr.S_un.S_addr << ", port " << addrClient.sin_port << ", socket " << client_num << endl;

		//创建线程，用于处理信息
		DWORD handleThreadId;
		HANDLE handleThread = CreateThread(NULL, NULL, Server_Handle, LPVOID(sockConn), 0, &handleThreadId);
	}

	closesocket(sockSrv);  //关闭服务器socket
	WSACleanup();  //结束使用Socket，释放Socket DLL资源
	return 0;
}