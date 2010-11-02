#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

using namespace std;


//Screen attributes
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const string SCREEN_CAPTION = "BALIK++";

//The frame rate
const int FRAMES_PER_SECOND = 30;

// Functions
SDL_Surface *loadImage(std::string );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
void gelenVeriIsle(std::string);
void komut2arr(string, string *);
void clean_up();
void set_clips();
SDL_Surface* init();
