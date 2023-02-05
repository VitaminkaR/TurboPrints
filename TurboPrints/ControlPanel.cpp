#include "ControlPanel.h"

extern const int HEIGHT;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* textures[];

namespace ControlPanel
{
	Vector2 call_button_pos = { WIDTH - 32, 0 };

	int list_offset;
	bool focus; // если курсор внутри области панели
	bool isShow = false;
}

void ControlPanel::Draw()
{
	render_texture(textures[1], gRenderer, call_button_pos.x, call_button_pos.y);
	if (isShow)
	{
		SDL_Rect fillRect = { WIDTH - WIDTH / 5, 0, WIDTH / 5, HEIGHT };
		SDL_SetRenderDrawColor(gRenderer, 225, 225, 225, 0xFF);
		SDL_RenderFillRect(gRenderer, &fillRect);

		// отрисовка кнопок
	}
}

void ControlPanel::Event_Handle(SDL_Event& e)
{
	if (check_button(e, call_button_pos.x, call_button_pos.y, textures[1]))
	{
		if (isShow)
		{
			call_button_pos.x = WIDTH - 32;
			isShow = false;
		}
		else
		{
			call_button_pos.x = WIDTH - WIDTH / 5 - 32;
			isShow = true;
		}
	}

	if (isShow)
	{
		if (IntersectRectPoint(WIDTH - WIDTH / 5, 0, e.button.x, e.button.y, WIDTH / 5, HEIGHT))
		{
			focus = true;
		}
		else
		{
			// если мышка не пересеклась с областью панели именно в момент её(курсора) перемещения
			if(e.type == 1024)
				focus = false;
		}	
		if (e.type == SDL_MOUSEWHEEL && focus)
		{
			list_offset += e.wheel.y;
			std::cout << list_offset << std::endl;
		}

	}
}