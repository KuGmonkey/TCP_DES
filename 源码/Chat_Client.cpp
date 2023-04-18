#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
#include<winsock2.h>
#include "DES.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//���ջ����������ڷ���ʱҪ���Э�����ݣ����Է�����Ϣ��string����
const int max_len = 10000;
char* recvBuf = new char[max_len];
string user;  //�û���

//��ȡ��ǰϵͳ���ں�ʱ��
char* get_time()
{
	time_t now = time(0); // �� now ת��Ϊ�ַ�����ʽ 
	char* dt = ctime(&now);
	return dt;
}

//�û���¼�������������
void WINAPI Client_Login(LPVOID lparam)
{
	//��������Socket
	SOCKET Server_Socket = (SOCKET)(LPVOID)lparam;

	//���շ��������ӳɹ���ʾ
	int recv_len = recv(Server_Socket, recvBuf, max_len, 0);
	if (recv_len > 0) {
		recvBuf[recv_len] = 0x00;
		string message;
		for (int i = 0; i < recv_len; i++)
			message = message + recvBuf[i];
		cout << message << endl << "Begin to chat..." << endl;
	}

	//�ͻ����ӳɹ����֪������
	string success_flag = "Client connect succesfully";
	send(Server_Socket, success_flag.c_str(), success_flag.length(), 0);
	return;
}

//�������������Ϣ
DWORD WINAPI client_send(LPVOID lparam)
{
	SOCKET Server_Socket = (SOCKET)(LPVOID)lparam;

	//�û�����
	while (1)
	{
		cout << ">>>";
		string message;
		getline(cin, message);

		//�û��˳�
		if (message == "exit")
		{
			cout << "bye!" << endl;
			//DES����
			message = Encode(message);
			send(Server_Socket, message.c_str(), message.length(), 0);
			break;
		}

		//�û�����Ϣ
		message = Encode(message);
		send(Server_Socket, message.c_str(), message.length(), 0);
	}
	return 0;
}

//���շ����ת������Ϣ
DWORD WINAPI client_recv(LPVOID lparam)
{
	SOCKET Server_Socket = (SOCKET)(LPVOID)lparam;

	//����ת��
	while (1)
	{
		int recv_len = recv(Server_Socket, recvBuf, max_len, 0);
		if (recv_len > 0)
		{
			recvBuf[recv_len] = 0x00;
			string message;
			for (int i = 0; i < recv_len; i++)
				message = message + recvBuf[i];
			//DES����
			message = Decode(message);
			cout <<"Receive message: "<< message;
		}
		cout << endl << ">>>";
	}
	return 0;
}

int main()
{
	int state1, state2;  //����ֺ����ķ���ֵ

	WORD wVersionRequested = MAKEWORD(2, 2); //������ϣ��ʹ�õ�socket����߰汾
	WSADATA wsaData;  //���õ�Socket����ϸ��Ϣ��ͨ��WSAStartup������ֵ
	//��ʼ��Socket DLL��Э��ʹ�õ�Socket�汾����ʼ���ɹ��򷵻�0������Ϊ�����int������
	state1 = WSAStartup(wVersionRequested, &wsaData);

	//���������׽��֣�һ�������
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addrSrv;  //����������˵�ַ
	addrSrv.sin_family = AF_INET;  //IPv4��ַ����
	cout << "server address:127.0.0.1" << endl;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //��������ַΪ�����Ĺ���ip������ֱ����127.0.0.1��ʶ������
	addrSrv.sin_port = htons(1234);   //�������Ķ˿ں�Ϊ1234

	//��һ���ض���socket�����������󣬳ɹ�����0�����򷵻�SOCKET_ERROR
	//���� ��������socket����������������ַ����ַ����
	state2 = connect(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	//�û���¼�������������
	Client_Login((LPVOID)sockSrv);


	//�û����������̣߳�һ��������Ϣ��һ��������Ϣ
	DWORD sendThreadId;
	HANDLE sendThread = CreateThread(NULL, NULL, client_send, LPVOID(sockSrv), 0, &sendThreadId);

	DWORD recvThreadId;
	HANDLE recvThread = CreateThread(NULL, NULL, client_recv, LPVOID(sockSrv), 0, &recvThreadId);

	//һ���߳̽������򶼽���
	WaitForSingleObject(sendThread, INFINITE);

	//����ʹ��Socket���ͷ�Socket��Դ
	closesocket(sockSrv);
	WSACleanup();
	return 0;
}