#include "Game.h"

int strr2int(string strConvert)
{
	int intReturn;

	intReturn = atoi(strConvert.c_str());

	return(intReturn);
}


Game::Game(string bgrnd)
{
	number = 0;
	playerCount = 1;
	//points = 0;
	// screen initialization
	screen = init();
	// load background
	background = IMG_Load( bgrnd.c_str() );
	font = TTF_OpenFont( "x.ttf", 32 );

	for(int i=0; i<LIMIT; i++)
		objects[i] = NULL;
}

Game::~Game()
{
	for(int i=0; i<number; i++)
	{
		if(objects[i]!= NULL)
			delete objects[i];
	}
	
	SDL_FreeSurface( background );
	SDL_FreeSurface( screen );
	SDL_FreeSurface( score );
	
	SDL_Quit();
}

bool Game::addObject(int tur, string name, int x, int y, int yon)
{
	if(number == LIMIT)
		return false;
	objects[number] = new Fish(name, x, y, tur, yon);
	number++;
	return true;
}

void Game::updateScreen()
{
	
	score = TTF_RenderText_Solid( font, int2string(objects[0]->getScore()).c_str(), textColor);
	message = TTF_RenderText_Solid( font, objects[0]->getName().c_str(), textColor);

	SDL_Rect temp2 = objects[0]->getPos();
	temp2.y +=(objects[0]->getFrame().h);

	SDL_Rect temp;
	temp.x = 720;
	temp.y = 0;
	SDL_BlitSurface( background, NULL, screen, NULL );
	SDL_BlitSurface( score, NULL, screen, &temp);
	SDL_BlitSurface( message, NULL, screen, &temp2 );
	
	for(int i=0; i<20; i++)
	{
		if((objects[i] != NULL) && objects[i]->alive)
			objects[i]->show(screen);
		else break;
	}
	SDL_Flip(screen);
}
//void Game::gelenVeriIsle(string gelenVeri){
//	//TODO: Burada son gelen verinin tekrar tekrar iþlenmesi muhtemel, kontrol etmek lazým
//	string *sonuc;
//	sonuc =new string[100];
//	komut2arr(gelenVeri,sonuc);
//	
//	
//	
//	if(sonuc[0]=="server")
//	{
//		
//		
//		//veri sunucudan gelmiþ, bonus falan yaratmak için muhtemelen
//		if(sonuc[1]=="kbalik")
//		{
//			//Sunucu yeni bir küçük balýk yaratmýþ
//			//id'si: sonuc[2]
//			//konum  x:sonuc[4]   y:[6]
//			//yön: sonuc[7]
//			addObject(6,sonuc[2],strr2int(sonuc[4]),strr2int(sonuc[6]),strr2int(sonuc[7]));
//		}
//		if(sonuc[1]=="mesaj")
//		{
//			//Tüm kullanýcýlara mesaj, öylesine koydum
//			//mesaj sonuc[2]
//		}
//	}
//	else
//	{
//		
//		//Veri bir baþka kullanýcýdan gelmiþ
//		if(sonuc[1]=="yenibaglanti")
//		{
//			//yeni baðlantý kurulmuþ, arkadaþýn objesi yaratýlacak
//			//kullanýcý adý: sonuc[0]
//			//çýkacaðý yer:  x:sonuc[3]   y:sonuc[5]
//			
//			addObject(playerCount,sonuc[0],strr2int(sonuc[3]),strr2int(sonuc[5]),0);
//		}
//
//		if(sonuc[1]=="baglantikes")
//		{
//			//kullanýcý oyundan ayrýlmýþ
//			//kullanýcý adý: sonuc[0]
//			find(sonuc[0]).kill();
//
//
//		}
//
//		if(sonuc[1]=="hareket")
//		{
//			//kullanýcý hareket etmiþ
//			//kullanýcý adý: sonuc[0]
//			//çýkacaðý yer:  x:sonuc[3]   y:sonuc[5]
//			//me->move(strr2int(sonuc[3]),strr2int(sonuc[5]));
//			if( exists(sonuc[0]) )
//				find(sonuc[0]).move(strr2int(sonuc[3]),strr2int(sonuc[5]));
//			else
//			{
//				addObject(2,sonuc[0],strr2int(sonuc[3]),strr2int(sonuc[5]),0);
//			}
//
//		}
//
//		if(sonuc[1]=="yedi")
//		{
//			if(sonuc[2]=="kbalik")
//			{
//				//küçük balýk yemiþ
//				//kullanýcý adý: sonuc[0]
//				//kbalik id si : sonuc[3]
//				find(sonuc[0]).addScore(find(sonuc[3]).getScore());
//				find(sonuc[3]).kill();
//
//			}
//
//			if(sonuc[2]=="kullanici")
//			{
//				//baþka bir kullanýcýyý yemiþ
//				// sonuc[0] isimli kullanýcý, sonuc[3] isimli kullanýcýyý yemiþ
//				find(sonuc[0]).addScore(find(sonuc[3]).getScore()/2);
//				find(sonuc[3]).kill();
//			}
//		}
//	}
//
//
//	return;
//}
//void Game::komut2arr(string line, string *thread){
//	int strBegin=0, strLocale=0, i=0, strCount=0, strLngth ;
//	string str;
//	str = line;
// 
//	while(strLocale != string::npos)
//	{
//		strLocale = str.find(">",strBegin);
//		strLngth = strLocale-strBegin;
//		thread[i] = str.substr(strBegin,strLngth);
//		strBegin = strLocale + 1;
//		strCount++;
//		i++;
//	};
// 
//	return;
//}

Fish & Game::find(string searchName){
	for(int i=0; i<20; i++)
	{
		if(objects[i]->getName() == searchName)
			return *objects[i];
		
	}
	
}

void Game::moveObject(string in, int x, int y)
{
	SDL_Rect temp1, temp2;
	temp2 = objects[0]->getPos();
	temp2.w = objects[0]->getFrame().w;
	temp2.h = objects[0]->getFrame().h;
	find(in).setPos(x, y);
	for(int i = 1; i < 20; i++)
	{
		if(objects[i] == NULL) break;
		else{
			temp1 = objects[i]->getPos();
			temp1.w = objects[i]->getFrame().w;
			temp1.h = objects[i]->getFrame().h;
			if(check_collision(temp1, temp2))
			{
				objects[0]->addScore(5);
				objects[i]->kill();
			}
		}

	}
	return;
}

bool check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
        
    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    
    //If none of the sides from A are outside B
    return true;
}