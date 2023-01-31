#include "ControlPanel.h"

void ControlPanel::Call_Button()
{
	if (isShow)
		Close();
	else
		Show();
}

void ControlPanel::Init()
{
	isShow = false;
	Vector2 pos; pos.x = 0; pos.y = 0;
	Button* b = new Button(pos, *gRenderer, textures->at(1));
	call_button = b;
	call_button->position = { WIDTH - 32, 0 };
}

void ControlPanel::Show()
{
	call_button->position = { WIDTH - WIDTH / 5 - 32, 0 };
	isShow = true;
}

void ControlPanel::Close()
{
	call_button->position = { WIDTH - 32, 0 };
	isShow = false;
}

void ControlPanel::Draw()
{
	call_button->Draw();
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

	if (isShow)
	{
		if (IntersectRectPoint(WIDTH - WIDTH / 5, 0, e.button.x, e.button.y, WIDTH / 5, HEIGHT))
		{
			std::cout << "LOL";
		}
	}
}