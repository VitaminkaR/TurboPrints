#include "Button.h"

Button::Button(Vector2 _position, SDL_Renderer& _renderer, SDL_Texture *_texture, void(*action)(Vector2 mpos, int button_type, int clicks))
{
	position = _position;
	renderer = &_renderer;
	texture = _texture;
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	tsize.x = w; tsize.y = h;
	this->action = action;
}

Button::Button(Vector2 _position, SDL_Renderer& _renderer, int w, int h, void(*action)(Vector2 mpos, int button_type, int clicks))
{
	position = _position;
	renderer = &_renderer;
	this->action = action;
	this->tsize.x = w;
	this->tsize.y = h;
}

void Button::Event_Handle(SDL_Event& _event)
{
	if (_event.type == SDL_MOUSEBUTTONDOWN)
	{
		Vector2 mpos; mpos.x = _event.button.x; mpos.y = _event.button.y;
		if (position.x < mpos.x && position.y < mpos.y && position.x + tsize.x > mpos.x && position.y + tsize.y > mpos.y)
		{
			action(mpos, _event.button.button, _event.button.clicks);
		}
	}
}
