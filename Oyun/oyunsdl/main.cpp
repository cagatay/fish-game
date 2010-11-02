#include "Game.h"
#include "Timer.h"
#include "Multiclient.h"
#include "Threaded.h"
#include <iostream>
#include <string>

bool quit = false;
SDL_Event evnt;
int x, y;

int main(int argc, char **argv)
{
	string yeniIp,yeniKA;
	int yeniPort;
	cout << "Sunucu ip adresi" << endl;
	cin >> yeniIp;
	cout << "Port" << endl;
	cin >> yeniPort;
	cout << "Kullanici adiniz" << endl;
	cin >> yeniKA;
	/*setGirisBilgileri("192.168.2.2",2000,"cagatay");
	CThread yeniBaglanti(baglanti);
	yeniBaglanti.Start();*/

	Game game(BACKGROUND);
	game.addObject(1, "cagatay", 350, 200, 1);
	int rndx, rndy,yon;
	int IMin=0;
	int IMax=600;
	int I = IMin + rand() % (IMax - IMin);
	int I2 = IMin + rand() % (IMax - IMin);
	int I3 = 0 + rand() % (2 - 0);

	for(int i = 1; i < 5; i++)
	{
		I = IMin + rand() % (IMax - IMin);
		I2 = IMin + rand() % (IMax - IMin);
		game.addObject(6, "kbalik", I,I2, I3);
	}
	game.updateScreen();
	
	
	while(quit == false)
	{
		//game.gelenVeriIsle(gelenVeri);
		game.updateScreen();

		//gidecekVeri="hareket>x>2>y>2>";

		SDL_PollEvent( &evnt );
		if( evnt.type == SDL_KEYDOWN )
        {
			if(evnt.key.keysym.sym == SDLK_ESCAPE)
				quit = true;
        }
		if(evnt.type == SDL_MOUSEMOTION)
		{
			x = evnt.motion.x;
			y = evnt.motion.y;
			game.moveObject("cagatay", x, y);
			//gidecekVeri= "hareket>x>" + int2string(x)+ ">y>" + int2string(y) + ">";
		}
		
		if(quit) break;
	}

	return 0;
}