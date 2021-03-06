// networkclient.cpp

#include "stdafx.h"
#include "networkclient.h"
#include <iostream>
#include <WinSock2.h>

CNetworkClient::CNetworkClient( const CSulString& hostName, sigma::uint32 port )
{
	m_socketClient	= 0;
	m_hostName		= hostName;
	m_port			= port;
	init();
}

void CNetworkClient::init()
{
	m_socketClient = socket(AF_INET, SOCK_STREAM, 0);

    if ( m_socketClient==SOCKET_ERROR )
    {
        std::cout << "Client: Socket Door is stuck.. Wont open.. -.-;\n";
		return;
    }
}

void CNetworkClient::sendString( const CSulString& s )
{
	int bytesSent = send( m_socketClient, s.c_str(), s.size(), 0);
	if ( bytesSent == SOCKET_ERROR)
		printf("Client: send() error %ld.\n", WSAGetLastError());
}

void CNetworkClient::run()
{
	if ( m_socketClient==0 )
		return;

	struct sockaddr_in server; // New! Our network socket structure
	server.sin_family = AF_INET; // Always have ti as this for internet
	server.sin_port = htons(9000); // Dont forget the byte ordering

	hostent* localHost;
	char* localIP;
	localHost = gethostbyname("");
	localIP = inet_ntoa (*(struct in_addr *)*localHost->h_addr_list);

	server.sin_addr.s_addr = inet_addr(localIP);

	std::cout << "Client: connecting...\n";
	int error;
	error = connect(m_socketClient, (sockaddr*)&server, sizeof(server)); // Lets attempt to connect now
	if ( error==SOCKET_ERROR )
	{
		std::cout << "Client: Damn server wont let me connect!\n";
		return;
	}

	std::cout << "Client: connected to the server!\n";

	// If iMode!=0, non-blocking mode is enabled.
	u_long iMode=1;
	ioctlsocket( m_socketClient, FIONBIO, &iMode );

	char recvbuf[200];
	while (1)
	{
		// check for any messages received
		int bytesRecv = SOCKET_ERROR;
		bytesRecv = recv( m_socketClient, recvbuf, 199, 0 );
		if ( bytesRecv!=SOCKET_ERROR )
		{
			recvbuf[bytesRecv] = 0; // we zero terminate
			std::cout << "Client: Received (" << bytesRecv << "): " << recvbuf << std::endl;
		}

		// test we send a little message and wait
		sendString( "quick brown fox" );
		Sleep(1000);
	}
}