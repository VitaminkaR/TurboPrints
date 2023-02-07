﻿#include "platform.h"
#include "Content.h"
#include "Menu.h"
#include "ControlPanel.h"
#include "WindowPanel.h"
#include "DataWindowManager.h"
#include "RenderText.h"
#include "KeyboardHandler.h"
#include "OperationBlocks/RegisterOE.h"

const int WIDTH = 1280;
const int HEIGHT = 720;
// кол-во миллисекунд ожидания межу обновлениями
// сильно замедляет приложение (заметно только на слабых устр-вах)
// снимает огромную нагрузку на ядро процессора (цикл без замедления выполняется крайне часто, вызывая кучу отрисовок(и прочего),
// поэтому насильно замедляем цикл, т к over-много-fps нам не нужно, достаточно и 30
// стандарт 15 ms - около 60 fps
const int FRAMES = 15;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = NULL;												// основной рендер

extern std::vector<OperationElement*> oelements;
extern OperationElement* start_point;

bool init();													// инициализация программы
void close();													// отчистка данных (это может и ОС делать)

int SDL_main(int argc, char* argv[])
{
	if (!init())
		return -1;

	load_content();

	bool quit = false;
	SDL_Event e;

	DataWindowManager::Init();

	// debug
	start_point = new BeginOE(100, 100);

	// главный цикл
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			keyboard_handler(e);

			WindowPanel::Event_Handle(e);
			if (!WindowPanel::Get_Mode())
			{
				ControlPanel::Event_Handle(e);
				Menu::Event_Handle(e);
				for (int i = 0; i < oelements.size(); i++)
				{
					oelements.at(i)->Handler(e);
				}
			}
			if (WindowPanel::Get_Mode() == 1)
			{
				DataWindowManager::Event_Handle(e);
			}
		}

		SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 0xFF);
		SDL_RenderClear(gRenderer);

		WindowPanel::Draw();
		if (!WindowPanel::Get_Mode())
		{
			ControlPanel::Draw();
			Menu::Draw();
			for (int i = 0; i < oelements.size(); i++)
			{
				oelements.at(i)->Draw();
			}
		}
		if (WindowPanel::Get_Mode() == 1)
		{
			DataWindowManager::Draw();
		}

		SDL_RenderPresent(gRenderer);
		SDL_Delay(FRAMES);
	}
	close();

	return 0;
}

bool init()
{
	bool success = true;

	// инициализация компонентов
	if (FT_Init())
	{
		printf("FT could not initialize!");
	}
	if (IMG_Init(IMG_INIT_PNG) < 0)
	{
		printf("IMG could not initialize! IMG_Error: %s\n", IMG_GetError());
		success = false;
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// создание окна
		gWindow = SDL_CreateWindow("TurboPrints", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
		}
	}

	return success;
}

void close()
{
	// тут должна быть выгрузка ресурсов, но ОС справится лучше меня (ничего не забудет)
	unload_content();

	SDL_Quit();
}