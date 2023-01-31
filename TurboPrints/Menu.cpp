#include "Menu.h"

void Menu::Call_Button()
{
	if(isShow)
		call_button->position = {0, 0};
	else 
		call_button->position = { WIDTH / 5, 0 };
	isShow = !isShow;
}

void Menu::Init(std::vector<DrawableObject*>* _objects, std::vector<SDL_Texture*>* _textures)
{
	isShow = false;
	Vector2 pos; pos.x = 0; pos.y = 0;
	Button* b = new Button(pos, *gRenderer, _textures->at(0));
	call_button = b;
	_objects->push_back(b);
}

void Menu::Show()
{
	isShow = true;
}

void Menu::Close()
{
	isShow = false;
}

void Menu::Draw()
{
	if (isShow)
	{
		SDL_Rect fillRect = { 0, 0, WIDTH / 5, HEIGHT };
		SDL_SetRenderDrawColor(gRenderer, 225, 225, 225, 0xFF);
		SDL_RenderFillRect(gRenderer, &fillRect);
	}
}

void Menu::Event_Handle(SDL_Event& e)
{
	if (call_button->Request(e))
	{
		Call_Button();
	}
}
