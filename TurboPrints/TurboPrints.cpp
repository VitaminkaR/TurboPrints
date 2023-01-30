﻿#include "platform.h"
#include "Content.h"
#include "Button.h"

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = NULL;
std::vector<SDL_Texture*>* textures;
std::vector<DrawableObject*>* objects;

const int WIDTH = 1280;
const int HEIGHT = 720;

bool init();
void close();
void create_scene();

int SDL_main(int argc, char* argv[])
{
	if (!init())
		return -1;

	load_content();

	create_scene();

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

			for (int i = 0; i < objects->size(); i++)
			{
				objects->at(i)->Event_Handle(e);
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 0xFF);
		SDL_RenderClear(gRenderer);

		for (int i = 0; i < objects->size(); i++)
		{
			objects->at(i)->Update();
			objects->at(i)->Draw();
		}
		
		//SDL_UpdateWindowSurface(global_vars.gWindow);
		SDL_RenderPresent(gRenderer);
	}
	close();

	return 0;
}

bool init()
{
	bool success = true;

	objects = new std::vector<DrawableObject*>();

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) && IMG_Init(IMG_INIT_PNG) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("TurboPrints", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
		}
	}

	return success;
}

void close()
{
	//Deallocate media
	unload_content();
	delete  textures;

	for (int i = 0; i < objects->size(); i++)
	{
		delete objects->at(i);
	}
	delete objects;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

void DebugAction(Vector2 mpos, int button_type, int clicks)
{
	std::cout << "click";
}

void create_scene()
{
	Vector2 pos; pos.x = 0; pos.y = 0;
	Button *b = new Button(pos, *gRenderer, 32, 32, DebugAction);
	objects->push_back(b);
}
