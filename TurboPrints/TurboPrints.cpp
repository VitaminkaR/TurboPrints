#include <iostream>
#include "platform.h"

struct GV
{
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	SDL_Renderer *gRenderer = NULL;
} global_vars;

const int WIDTH = 1280;
const int HEIGHT = 720;

bool init();
bool loadMedia();
void close();

int SDL_main(int argc, char* argv[])
{
	if (!init())
		return -1;
	if (!loadMedia())
		return -1;

	bool quit = false;
	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(global_vars.gRenderer, 100, 100, 100, 0xFF);
		SDL_RenderClear(global_vars.gRenderer);

		// Drawing

		
		//SDL_UpdateWindowSurface(global_vars.gWindow);
		SDL_RenderPresent(global_vars.gRenderer);
	}
	close();

	return 0;
}

bool init()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		global_vars.gWindow = SDL_CreateWindow("TurboPrints", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (global_vars.gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			global_vars.gScreenSurface = SDL_GetWindowSurface(global_vars.gWindow);
			global_vars.gRenderer = SDL_CreateRenderer(global_vars.gWindow, -1, 0);
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	// Loading media

	return success;
}

void close()
{
	//Deallocate media


	SDL_DestroyWindow(global_vars.gWindow);
	global_vars.gWindow = NULL;

	SDL_Quit();
}