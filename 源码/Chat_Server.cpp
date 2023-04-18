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

const int max_len = 10000;  //�������˽��ܵ������Ϣ����
//char* recvBuf = new char[max_len];  //���ջ�����
//int msg_len;  //���յ�����Ϣ����
int client_num = 0;
vector<SOCKET> clients;

//��ȡ��ǰϵͳ���ں�ʱ��
char* get_time()
{
	time_t now = time(0); // �� now ת��Ϊ�ַ�����ʽ 
	char* dt = ctime(&now);
	return dt;
}

//��ͻ��˽���
DWORD WINAPI Server_Handle(LPVOID lparam)
{
	SOCKET Client_Socket = (SOCKET)(LPVOID)lparam;
	//��������
	//���û��������ӳɹ���ʾ
	string success_flag = "Connect Success!";
	send(Client_Socket, success_flag.c_str(), success_flag.length(), 0);  //c_str()��������ָ��

	char* recvBuf = new char[max_len];  //�½����ջ�����
	int recv_len;  //������Ϣ�ĳ���
	//���տͻ������ӳɹ�����Ϣ
	recv_len = recv(Client_Socket, recvBuf, max_len, 0);
	//���յ��ַ������ӽ��������������
	recvBuf[recv_len] = 0x00;
	cout << recvBuf << endl;

	//ת���׶�,����user����Ϣ����ת����Ⱥ�ĵ������û�
	while (1)
	{
		//������Ϣ
		recv_len = recv(Client_Socket, recvBuf, max_len, 0);
		if (recv_len > 0)
		{
			recvBuf[recv_len] = 0x00;
			//�����û�����Ϣ
			string message;
			for (int i = 0; i < recv_len; i++)
				message = message + recvBuf[i];

			//����
			message = Decode(message);

			//�û�������Ϣ�ڷ���˵���־��¼
			//��������Ϣ
			if (message != "exit")
			{
				cout <<"Forward message: "<< message;
				cout << endl;
				//ת����Ϣ
				message = Encode(message);
				for (int i = 0; i < client_num; i++)
					if (Client_Socket != clients[i])
					{
						send(clients[i], message.c_str(), message.length(), 0);
					}
			}
			//user�˳�
			else
			{
				//�رյ�ǰ�߳�
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
	int state1, state2, state3;  //�����������ֵ

	WORD wVersionRequested = MAKEWORD(2, 2); //������ϣ��ʹ�õ�socket����߰汾
	WSADATA wsaData;  //���õ�Socket����ϸ��Ϣ��ͨ��WSAStartup������ֵ
	//��ʼ��Socket DLL��Э��ʹ�õ�Socket�汾����ʼ���ɹ��򷵻�0������Ϊ�����int������
	state1 = WSAStartup(wVersionRequested, &wsaData);

	//����һ��Socket�����󶨵�һ���ض��Ĵ�������
	//���� AF_INET��IPv4��ַ���ͣ�SOCK_STREAM����ʽ�׽��֣�IPPROTO_TCP��ʹ��TCP�����Э��
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addrSrv;  //ָ�򱾵ؽ�����ʼ��ַ��ָ�룬��߰���IP��ַ�Ͷ˿ںţ���תΪSOCKETADDR���͵�ָ�룬SOCKETADDR����SOCKETADDR_IN�ķ�װ���ѳ���ip��ַ����֮��ĳ�Ա��������װ��һ���ˣ�
	addrSrv.sin_family = AF_INET;  //IPv4��ַ����
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //���ñ���ipΪ������ip
	addrSrv.sin_port = htons(1234);   //�˿ں�Ϊ1234
	//��һ�����ص�ַ�󶨵�ָ����Socket����ȷ�򷵻�0�����򷵻�SOCKET_ERROR
	//���� sockSrv��socket�����������Ｔ���������׽��ֶ˿ڣ�namelen����ַ���ȣ�Ϊsockaddr�ṹ�ĳ���
	state2 = bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	//ʹsocket�������״̬������Զ�������Ƿ���
	//���� socketSrv��socket��������backlog�����ӵȴ����е���󳤶ȣ�����Ϊ20
	state3 = listen(sockSrv, 20);
	if (state3 == 0)
	{
		cout << "[log]" << get_time() << ">>>" << "Listening..." << endl;
	}
	else
	{
		cout << "[error]" << get_time() << ">>>" << "Error��" << endl;
	}

	while (1)
	{
		SOCKADDR_IN addrClient;   //�ͻ��˵�ַ
		int len = sizeof(SOCKADDR);   //��ַ����
		//����һ���ض�socket����ȴ������е��������󣬴˺������к��������״̬��ֱ�����������������ӳɹ����������ӵ�socket�����������󷵻�INVALID_SOCKET
		//���� sockSrv��������socket��������addrClient���ͻ��˵�ַ��ʼλ��ָ�룺len����ַ����
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
		//���û������
		clients.push_back(sockConn);
		client_num++;

		//��־��Ϣ
		cout << "[log]" << get_time() << ">>>" << "server: got connection from " << addrClient.sin_addr.S_un.S_addr << ", port " << addrClient.sin_port << ", socket " << client_num << endl;

		//�����̣߳����ڴ�����Ϣ
		DWORD handleThreadId;
		HANDLE handleThread = CreateThread(NULL, NULL, Server_Handle, LPVOID(sockConn), 0, &handleThreadId);
	}

	closesocket(sockSrv);  //�رշ�����socket
	WSACleanup();  //����ʹ��Socket���ͷ�Socket DLL��Դ
	return 0;
}