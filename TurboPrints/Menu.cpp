#include "Menu.h"

extern const int WIDTH;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* textures[];

namespace Menu
{
	Vector2 call_button_pos;
	Vector2 compile_button_pos = { 64, HEIGHT - 64 };
	bool isShow = false;
}

void Menu::Draw()
{
	render_texture(textures[0], gRenderer, call_button_pos.x, call_button_pos.y);
	if (isShow)
	{
		SDL_Rect fillRect = { 0, 0, WIDTH / 5, HEIGHT };
		SDL_SetRenderDrawColor(gRenderer, 225, 225, 225, 0xFF);
		SDL_RenderFillRect(gRenderer, &fillRect);

		// отрисока кнопок
		render_texture(textures[2], gRenderer, compile_button_pos.x, compile_button_pos.y);
	}
}

void Menu::Event_Handle(SDL_Event& e)
{
	if (check_button(e, call_button_pos.x, call_button_pos.y, textures[0]))
	{
		if (isShow)
		{
			isShow = false;
			call_button_pos.x = 0;
		}
		else
		{
			isShow = true;
			call_button_pos.x = WIDTH / 5;
		}
	}
	if (isShow)
	{
		if(check_button(e, compile_button_pos.x, compile_button_pos.y, textures[2]))
			compile();
	}
}