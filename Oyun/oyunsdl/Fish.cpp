#include "Fish.h"
#include <sstream>
using namespace std;

Fish::Fish(string in, int x, int y, int z, int yon)
{
	name = in;
	tur = z;
	direction = yon;
	position.x = x;
	position.y = y;
	string s = int2string(tur) + ".bmp";
	if(tur == 6) velocity = 3;
	else velocity = 0;
	alive = true;
	score = 0;
	
	
	surface = IMG_Load( s.c_str() );
    
	Uint32 colorkey = SDL_MapRGB( surface->format, 0x00, 0x00, 0x00 );
	SDL_SetColorKey( surface, SDL_SRCCOLORKEY, colorkey );

	frame.x = 0;
	frame.y = 0;
	frame.w = surface->w;
	frame.h = surface->h/2;
}

Fish::~Fish()
{
	SDL_FreeSurface(surface);
}

void Fish::setPos(int x, int y)
{
	if(position.x < x) direction = 1;
	if(position.x > x) direction = 0;

	position.x = x;
	position.y = y;
}

SDL_Rect Fish::getPos()
{
	return position;
}

void Fish::move(int xrel, int yrel)
{
	position.x += xrel;
	position.y += yrel;
}

int Fish::getDirection()
{
	return direction;
}

void Fish::show(SDL_Surface *dest)
{	
	if( (position.x + surface->w) >= 800 )
	{
		direction = 0;
		velocity = -1*velocity;
	}

	if( position.x <= 0)
	{
		direction = 1;
		velocity = -1*velocity;
	}
	position.x += velocity;

	setFrame();
	SDL_BlitSurface( surface, &frame, dest, &position );
}

void Fish::setFrame()
{
		if(direction == LEFT)
			frame.y = (surface->h)/2;
		else
			frame.y = 0;
}

string int2string(int i)
{
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	return s;

}

string Fish::getName(){
	return name;
}

void Fish::kill(){
	alive=false;
	
	int xnew =3;
	int ynew = 0 + rand() % (600 - 0);
	setPos(xnew,ynew);
	alive=true;
}

void Fish::addScore(int newScore){
	score+=newScore;
}

int Fish::getScore(){
	return score;
}

SDL_Rect Fish::getFrame(){
	return frame;
}
