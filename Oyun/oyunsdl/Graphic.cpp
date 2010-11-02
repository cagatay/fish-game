#include "Graphic.h"
#include "SDL_ttf.h"

SDL_Surface *loadImage( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF );

            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

    //Return the optimized image
    return optimizedImage;
}
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, clip, destination, &offset );
}


SDL_Surface* init()
{
	//SDL_Surface *ret;
	SDL_Init( SDL_INIT_EVERYTHING );
	TTF_Init();
	SDL_WM_SetCaption( SCREEN_CAPTION.c_str(), NULL );
	SDL_ShowCursor(SDL_DISABLE);
	return SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_FULLSCREEN | SDL_SWSURFACE );
	
}