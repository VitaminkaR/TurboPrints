#pragma once

#include "DrawableObject.h"

class Button : public DrawableObject
{
public:
	Button(Vector2 _position, SDL_Renderer& _renderer, SDL_Texture *_texture);
	Button(Vector2 _position, SDL_Renderer& _renderer, int w, int h);

	bool Request(SDL_Event& _event);
};

