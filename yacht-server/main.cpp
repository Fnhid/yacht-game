
#include "main.h"

WSADATA wsaData;
SOCKET serverSock;
SOCKET clientSock[MAX_CLIENT];

SOCKADDR_IN serverAddr;
SOCKADDR_IN clientAddr[MAX_CLIENT];
int clientSize[MAX_CLIENT];

char username[2][BUFSIZE];
int main()
{
	char buf[BUFSIZE];
	ZeroMemory((void*)&buf, BUFSIZE);
	int checkByte;
	
	

	

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		errorHandling("WSAStartup() error!");

	serverSock = socket(PF_INET, SOCK_STREAM, 0);

	if (serverSock == INVALID_SOCKET)
		errorHandling("socket() error");

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serverSock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		errorHandling("bind() error");

	if (listen(serverSock, 1) == SOCKET_ERROR)
		errorHandling("socket() error");
	cout << "Waiting clients.." << endl;
	thread tca0(acceptClients, 0);
	thread tca1(acceptClients, 1);
	tca0.join();
	tca1.join();

	thread tcp0(prepareClients, 0);
	thread tcp1(prepareClients, 1);
	tcp0.join();
	tcp1.join();

	thread tcg0(gameClients, 0);
	thread tcg1(gameClients, 1);
	tcg0.join();
	tcg1.join();
	initServer();
	return 0;
}

void acceptClients(int i) {
	clientSize[i] = sizeof(clientAddr[i]);
	clientSock[i] = accept(serverSock, (SOCKADDR*)&clientAddr[i], &clientSize[i]);
	if (clientSock[i] == INVALID_SOCKET)
		errorHandling("accept() error");

	
}

void prepareClients(int i) { // set index of client, get username of client
	char buf[BUFSIZE];
	ZeroMemory((void*)&buf, BUFSIZE);
	int checkByte;
	buf[0] = (char)(i + 1);

	checkByte = send(clientSock[i], buf, BUFSIZE - 1, 0);
	if (checkByte == SOCKET_ERROR)
		errorHandling("send() error");
	checkByte = recv(clientSock[i], username[i], BUFSIZE - 1, 0);
	if (checkByte >= 0)
		buf[checkByte] = '\0'; // end of buf
}

void gameClients(int i) {
	char buf[BUFSIZE];
	ZeroMemory((void*)&buf, BUFSIZE);
	int checkByte;
	
	if (i == 0) {
		checkByte = send(clientSock[0], username[1], BUFSIZE - 1, 0);
		if (checkByte == SOCKET_ERROR)
			errorHandling("send() error");
	}
	else {
		checkByte = send(clientSock[1], username[0], BUFSIZE - 1, 0);
		if (checkByte == SOCKET_ERROR)
			errorHandling("send() error");
	}
	while (true) {
		ZeroMemory((void*)&buf, BUFSIZE - 1);
		checkByte = recv(clientSock[i], buf, BUFSIZE - 1, 0);
		if (checkByte >= 0)
			buf[checkByte] = '\0'; // end of buf
		else break;
		cout << "[" << i << "] : ";
		for(int i=0;i<10;i++)
			cout << static_cast<int>(buf[i]);
		cout << endl;
		if (i == 0) {
			checkByte = send(clientSock[1], buf, BUFSIZE - 1, 0);
			if (checkByte == SOCKET_ERROR)
				errorHandling("send() error");
		}
		else {
			checkByte = send(clientSock[0], buf, BUFSIZE - 1, 0);
			if (checkByte == SOCKET_ERROR)
				errorHandling("send() error");
		}
	}

}
void initServer() {
	for (int i = 0; i < 2; i++) closesocket(clientSock[i]);
	closesocket(serverSock);
	WSACleanup();
}

void errorHandling(const char* e)
{
	std::cerr << e << std::endl;
	exit(1);
}