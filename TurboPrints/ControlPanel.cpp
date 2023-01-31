#include "ControlPanel.h"

void ControlPanel::Call_Button()
{
	if (isShow)
		call_button->position = { WIDTH - 32, 0 };
	else
		call_button->position = { WIDTH - WIDTH / 5 - 32, 0 };
	isShow = !isShow;
}

void ControlPanel::Init(std::vector<DrawableObject*>* _objects, std::vector<SDL_Texture*>* _textures)
{
	isShow = false;
	Vector2 pos; pos.x = 0; pos.y = 0;
	Button* b = new Button(pos, *gRenderer, _textures->at(1));
	call_button = b;
	call_button->position = { WIDTH - 32, 0 };
	_objects->push_back(b);
}

void ControlPanel::Show()
{
	isShow = true;
}

void ControlPanel::Close()
{
	isShow = false;
}

void ControlPanel::Draw()
{
	if (isShow)
	{
		SDL_Rect fillRect = { WIDTH - WIDTH / 5, 0, WIDTH / 5, HEIGHT };
		SDL_SetRenderDrawColor(gRenderer, 225, 225, 225, 0xFF);
		SDL_RenderFillRect(gRenderer, &fillRect);
	}
}

void ControlPanel::Event_Handle(SDL_Event& e)
{
	if (call_button->Request(e))
	{
		Call_Button();
	}
}