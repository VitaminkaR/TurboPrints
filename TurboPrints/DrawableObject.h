#pragma once

#include "platform.h"

class DrawableObject
{
public:
	Vector2 position;
	SDL_Renderer *renderer;

	DrawableObject(Vector2 _position, SDL_Renderer &_renderer);

	virtual void Update();

	virtual void Draw();

	virtual void Event_Handle(SDL_Event &_event);
};

