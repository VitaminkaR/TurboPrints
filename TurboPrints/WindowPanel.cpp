#include "WindowPanel.h"

WindowPanel::WindowPanel()
{
	position.x = WIDTH / 5 + 32;
	position.y = 0;
	Set_Texture(*textures->at(3));
}

void WindowPanel::Event_Handle(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (IntersectRectPoint(position.x, 0, e.button.x, e.button.y, 86, 16))
		{
			std::cout << "WP:SCHEME" << std::endl;
		}
		if (IntersectRectPoint(position.x + 92, 0, e.button.x, e.button.y, 58, 16))
		{
			std::cout << "WP:DATA" << std::endl;
		}
	}
}