#include "WindowPanel.h"
#include "Button.h"

WindowPanel::WindowPanel()
{
	position.x = WIDTH / 5 + 32;
	position.y = 0;
	texture = textures->at(3);
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	tsize.x = w; tsize.y = h;
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