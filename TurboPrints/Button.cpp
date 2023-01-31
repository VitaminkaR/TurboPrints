#include "Button.h"

Button::Button(Vector2 _position, SDL_Renderer& _renderer, SDL_Texture *_texture)
{
	position = _position;
	renderer = &_renderer;
	texture = _texture;
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	tsize.x = w; tsize.y = h;
}

Button::Button(Vector2 _position, SDL_Renderer& _renderer, int w, int h)
{
	position = _position;
	renderer = &_renderer;
	this->tsize.x = w;
	this->tsize.y = h;
}

bool Button::Request(SDL_Event& _event)
{
	if (_event.type == SDL_MOUSEBUTTONDOWN)
	{
		Vector2 mpos; mpos.x = _event.button.x; mpos.y = _event.button.y;
		return IntersectRectPoint(position.x, position.y, mpos.x, mpos.y, tsize.x, tsize.y);
	}
	return false;
}
