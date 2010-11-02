#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define RIGHT 1
#define LEFT 0

const SDL_Color textColor = { 0, 0, 0 };

using namespace std;

class Fish
{

private:
	SDL_Rect position;
	string name;
	int direction;
	int tur;
	int velocity;
	SDL_Surface *surface;
	SDL_Rect frame;
	int score;

	
	void setFrame();

public:
	bool alive;
	Fish(string , int , int , int, int );
	~Fish();
	void setPos(int , int );
	SDL_Rect getPos();
	void move(int , int );
	int getDirection();
	void show(SDL_Surface * );
	string getName();
	void kill();
	void addScore(int );
	int getScore();
	SDL_Rect getFrame();
};

string int2string(int );