#include "Fish.h"
#include "Graphic.h"
#include <string>

using namespace std;

const string BACKGROUND = "underwater.jpg";
//const string FISHSRC = "fishstrips.bmp";

const int LIMIT = 20;

bool check_collision( SDL_Rect , SDL_Rect );

class Game
{
private:
	SDL_Surface *screen;
	SDL_Surface *background;
	SDL_Surface *score;
	SDL_Surface *message;
	Fish *objects[LIMIT];
	TTF_Font *font;
	int number;
	//int points;
	int playerCount;
public:
	Game(string );
	~Game();
	//void gelenVeriIsle(string );
	bool addObject(int , string, int, int, int);
	void komut2arr(string , string * );
	void updateScreen();
	Fish& find(string );
	void moveObject(string , int , int);
};
