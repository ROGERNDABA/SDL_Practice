#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <stdio.h>

SDL_Renderer	*init_sdl(char *tittle, SDL_Window *window)
{
	SDL_Renderer	*renderer;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("LEARNING SDL", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, 1600, 1000, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	return (renderer);
}

int main(int argc, char* argv[]){
{
	SDL_Event		e;
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*bgd_txtr = NULL;
	SDL_Surface		*background_surface = NULL;

	renderer = init_sdl("Roger", win);

	SDL_DestroyWindow(win);
	SDL_Quit();
	return EXIT_SUCCESS;

}
