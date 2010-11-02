#include "MultiClient.h"

string gelenVeri;
string gidecekVeri;

char *str2char(string s)
{
	char *a=new char[s.size()+1];
	a[s.size()]=0;
	memcpy(a,s.c_str(),s.size());
	return a;
}

string char2string(const char * str)
{
	stringstream ss;
	string s;
	
	ss << str;
	ss >> s;
	return s;
}

int str2int(string strConvert) 
{
  int intReturn;

  intReturn = atoi(strConvert.c_str());

  return(intReturn);
}



DWORD WINAPI baglanti( LPVOID /* lpData */ )
{
    
	
	//char *server_name="160.75.137.90";
	//unsigned short port=2000;
	char Buffer[128];
    
    
    int retval, loopflag=0;
    int loopcount, maxloop = 100;
    unsigned int addr;
    int socket_type = DEFAULT_PROTO;
    struct sockaddr_in server;
    struct hostent *hp;
    WSADATA wsaData;
    SOCKET  conn_socket;

    
    if ((retval = WSAStartup(0x202,&wsaData)) != 0) {
        fprintf(stderr,"WSAStartup failed with error %d\n",retval);
        WSACleanup();
        return NULL;
    }
    
    

    //
    // Attempt to detect if we should call gethostbyname() or
    // gethostbyaddr()

    if (isalpha(server_name[0])) {   /* server address is a name */
        hp = gethostbyname(server_name);
    }
    else  { /* Convert nnn.nnn address to a usable one */
        addr = inet_addr(server_name);
        hp = gethostbyaddr((char *)&addr,4,AF_INET);
    }
    if (hp == NULL ) {
        fprintf(stderr,"Client: Cannot resolve address [%s]: Error %d\n",
            server_name,WSAGetLastError());
        WSACleanup();
        exit(1);
    }

    //
    // Copy the resolved information into the sockaddr_in structure
    //
    memset(&server,0,sizeof(server));
    memcpy(&(server.sin_addr),hp->h_addr,hp->h_length);
    server.sin_family = hp->h_addrtype;
    server.sin_port = htons(port);

    conn_socket = socket(AF_INET,socket_type,0); /* Open a socket */
    if (conn_socket <0 ) {
        fprintf(stderr,"Client: Error Opening socket: Error %d\n",
            WSAGetLastError());
        WSACleanup();
        return NULL;
    }

    //
    // Notice that nothing in this code is specific to whether we 
    // are using UDP or TCP.
    // We achieve this by using a simple trick.
    //    When connect() is called on a datagram socket, it does not 
    //    actually establish the connection as a stream (TCP) socket
    //    would. Instead, TCP/IP establishes the remote half of the
    //    ( LocalIPAddress, LocalPort, RemoteIP, RemotePort) mapping.
    //    This enables us to use send() and recv() on datagram sockets,
    //    instead of recvfrom() and sendto()


    printf("Client connecting to: %s\n",hp->h_name);
    if (connect(conn_socket,(struct sockaddr*)&server,sizeof(server))
        == SOCKET_ERROR) {
        fprintf(stderr,"connect() failed: %d\n",WSAGetLastError());
        WSACleanup();
        return NULL;
    }

    // cook up a string to send
    //
	string sonGidenVeri="";
	
    loopcount =0;
    while(1) {
		
		
		
			sprintf_s(Buffer,sizeof(Buffer), str2char(kullaniciAdi+">"+gidecekVeri));
			retval = send(conn_socket,Buffer,sizeof(Buffer),0);
			if (retval == SOCKET_ERROR) {
				fprintf(stderr,"gönderilemedi: %d\n",WSAGetLastError());
				WSACleanup();
				return NULL;
			}
			else
			{
				sonGidenVeri=gidecekVeri;
			}

			
		retval = recv(conn_socket,Buffer,sizeof (Buffer),0 );
        if (retval == SOCKET_ERROR) {
            fprintf(stderr,"recv() failed: error %d\n",WSAGetLastError());
            closesocket(conn_socket);
            WSACleanup();
            return NULL;
        }
		else
		{
			gelenVeri=char2string(Buffer);
			

			
			
		}
		
        //
        // We are not likely to see this with UDP, since there is no
        // 'connection' established. 
        //
        if (retval == 0) {
            printf("Server closed connection\n");
            closesocket(conn_socket);
            WSACleanup();
            return NULL;
        }
		
		
		
        /*if (!loopflag){
            printf("Terminating connection\n");
            break;
        }
        else {
            if ( (loopcount >= maxloop) && (maxloop >0) )
                break;
        }*/
    }
    closesocket(conn_socket);
    WSACleanup();

}


void setKullaniciAdi(string yeniKullaniciAdi)
{
	kullaniciAdi=yeniKullaniciAdi;
}

void setGidecekVeri(string yeniGidecekVeri){
	gidecekVeri=yeniGidecekVeri;
}

string getGelenVeri(){
	return gelenVeri;
}

void setGirisBilgileri(char *newServer,unsigned short newPort, string yeniKullaniciAdi){

	setKullaniciAdi(yeniKullaniciAdi);
	server_name=newServer;
	port=newPort;


}