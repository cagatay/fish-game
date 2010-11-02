#include <winsock2.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Threaded.h"

using namespace std;

#define DEFAULT_PORT 2000
#define DEFAULT_PROTO SOCK_STREAM // TCP

static string kullaniciAdi;
extern string gidecekVeri;
extern string gelenVeri;
static char *server_name;
static unsigned short port;

char *str2char(string );
string int2string(int );
string char2string(const char *);
int str2int(string);
DWORD WINAPI yeniVeri( LPVOID /* lpData */ );
DWORD WINAPI gelenVeriIsle( LPVOID /* lpData */ );
DWORD WINAPI baglanti( LPVOID /* lpData */ );
void setKullaniciAdi(string );
void setGidecekVeri(string );
string getGelenVeri();
void setGirisBilgileri(char *,unsigned short, string);