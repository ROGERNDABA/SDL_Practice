#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <unistd.h>

void	drawCube(SDL_Renderer *ren, int in_x, int in_y, int size)
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			SDL_RenderDrawPoint(ren, in_x + x, in_y + y);
		}
		//SDL_RenderPresent(ren);
	}
}

SDL_Renderer	*init(char *title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win = SDL_CreateWindow(title,  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 0);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	return (ren);
}

int	main(void)
{
	SDL_Renderer	*ren = init("My world");
	SDL_Event		event;
	int				quit;
	int				x;
	int				y;

	//SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	// SDL_RenderClear(ren);
	// SDL_SetRenderDrawColor(ren,35,141,250, 255);
	// int i =0;
	// int j = 10;
	// while (i < 400 && j < 480)
	// {
	// 	drawCube(ren, i, j, 20);
	// 	// SDL_Delay(200);
	// 	i = i + 40;
	// 	if (i >= 200)
	// 	{
	// 		j += 30;
	// 		i = 0;
	// 	}
	// 	SDL_RenderPresent(ren);
	// }
	int i =0;
	int j = 10;
	quit = 0;
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	while (quit == 0)
	{
		SDL_Delay(200);
		//SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		//SDL_RenderClear(ren);
		if (i < 640 && j < 400)
		{
			//SDL_RenderClear(ren);
			SDL_RenderPresent(ren);
			SDL_SetRenderDrawColor(ren,35,141,250, 255);
			drawCube(ren, i, j, 20);
			//SDL_RenderPresent(ren);
			//usleep(5000);
			
		}
		 //SDL_RenderPresent(ren);
		 /*Check for new events */
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
				//SDL_RenderClear(ren);
				//SDL_GetMouseState(&x, &y);
				//SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
				////draw_line(ren, 320, 240, x, y);
				//SDL_RenderPresent(ren);
			}
			/* If a quit event has been sent */
			if (event.type == SDL_QUIT)
			{
				/* Quit the application */
				quit = 1;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit = 1;
			}
		}
		i = i + 40;
		if (i >= 200)
		{
			j += 30;
			i = 0;
		}
		
	//SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	//SDL_RenderClear(ren);
	}
	SDL_Quit();
	return (0);
}
