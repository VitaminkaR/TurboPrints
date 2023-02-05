#include "Button.h"

bool check_button(SDL_Event& e, int x, int y, SDL_Texture* texture)
{
	int w, h;
	SDL_QueryTexture(texture, 0, 0, &w, &h);
	return check_button(e, x, y, w, h);
}

bool check_button(SDL_Event& e, int x, int y, int w, int h)
{
	return e.type == SDL_MOUSEBUTTONDOWN && IntersectRectPoint(x, y, e.button.x, e.button.y, w, h);
}
