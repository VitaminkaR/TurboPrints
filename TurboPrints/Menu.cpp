#include "Menu.h"

void Menu::Call_Button()
{
	if (isShow)
		Close();
	else
		Show();
}

Menu::Menu()
{
	tag = "menu";
	isShow = false;
	Vector2 pos; pos.x = 0; pos.y = 0;
	call_button = new Button(pos, textures->at(0));
}

void Menu::Show()
{
	isShow = true;

	call_button->position = { WIDTH / 5, 0 };
	
	// create buttons
	Vector2 pos; pos.x = 64; pos.y = HEIGHT - 64;
	compile_button = new Button(pos, textures->at(2));;
}

void Menu::Close()
{
	isShow = false;
	delete compile_button;
	call_button->position = { 0, 0 };
}

void Menu::Draw()
{
	call_button->Draw();
	if (isShow)
	{
		SDL_Rect fillRect = { 0, 0, WIDTH / 5, HEIGHT };
		SDL_SetRenderDrawColor(gRenderer, 225, 225, 225, 0xFF);
		SDL_RenderFillRect(gRenderer, &fillRect);

		// отрисока кнопок
		compile_button->Draw();
	}
}

void Menu::Event_Handle(SDL_Event& e)
{
	if (call_button->Request(e))
	{
		Call_Button();
	}
	if (isShow)
	{
		// обработка кнопок
	}
}

void Menu::Dispose()
{
	delete call_button;
	if(compile_button != nullptr) delete compile_button;
}