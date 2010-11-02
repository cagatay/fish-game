#include <string>
#include <SDL.h>
#include "Graphic.h"

using namespace std;

struct Position{
	int x, y;
};

class Object{
protected:
	Position position;
	string name;
	int direction;
	SDL_Surface *surface;

public:
	Object(string , int , int , string );
	void setPos(int , int );
	Position getPos();
	void move(int , int );
	int getDirection();
	void show(SDL_Surface * );
};