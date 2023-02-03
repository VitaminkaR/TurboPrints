#include "platform.h"
#include "Content.h"
#include "Menu.h"
#include "ControlPanel.h"
#include "WindowPanel.h"
#include "DataWindowManager.h"
#include "RenderText.h"

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = NULL;				// основной рендер
std::vector<SDL_Texture*>* textures;		// хранит загруженные текстуры
std::vector<DrawableObject*>* objects;		// хранит объекты 
WindowPanel *wp = NULL;							// управляет окнами(не ОС, а внутрипрограммными)

const int WIDTH = 1280;
const int HEIGHT = 720;
// кол-во миллисекунд ожидания межу обновлениями
// сильно замедляет приложение (заметно только на слабых устр-вах)
// снимает огромную нагрузку на ядро процессора (цикл без замедления выполняется крайне часто, вызывая кучу отрисовок(и прочего),
// поэтому насильно замедляем цикл, т к over-много-fps нам не нужно, достаточно и 30
// стандарт 15 ms - около 60 fps
const int FRAMES = 15;

bool init();													// инициализация программы
void close();													// отчистка данных (это может и ОС делать)
void create_scene();										// создание основного интерфейса и объектов

int SDL_main(int argc, char* argv[])
{
	if (!init())
		return -1;

	load_content();
	wp = new WindowPanel();
	create_scene();

	bool quit = false;
	SDL_Event e;

	// главный цикл
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			wp->Event_Handle(e);

			for (int i = 0; i < objects->size(); i++)
			{
				if (objects->at(i) == nullptr) 
				{
					objects->erase(objects->begin() + i);
					continue;
				}
				objects->at(i)->Event_Handle(e);
			}
		}

		SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 0xFF);
		SDL_RenderClear(gRenderer);

		wp->Draw();
		wp->Update();

		// обновление и отрисовка объектов
		for (int i = 0; i < objects->size(); i++)
		{
			objects->at(i)->Update();
			objects->at(i)->Draw();
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

	objects = new std::vector<DrawableObject*>();
	
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
	//выгрузка конента
	unload_content();
	delete  textures;

	// выгрузка объектов
	wp->Dispose();

	// удаление окна
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

void create_scene()
{
	std::vector<DrawableObject*>** scheme_window = wp->GetScene(0);
	*scheme_window = new std::vector<DrawableObject*>();
	objects = *scheme_window;

	// tag = menu
	(* scheme_window)->push_back(new Menu);
	// tag = conpan
	(*scheme_window)->push_back(new ControlPanel());


	std::vector<DrawableObject*>** data_window = wp->GetScene(1);
	*data_window = new std::vector<DrawableObject*>();

	(*data_window)->push_back(new DataWindowManager);
}
