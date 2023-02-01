#pragma once

#include "platform.h"

extern SDL_Renderer* gRenderer;

class DrawableObject
{
public:
	Vector2 position;
	SDL_Texture *texture;
	Vector2 tsize;

	void Set_Texture(SDL_Texture &_texture);

	virtual void Update();

	virtual void Draw();

	virtual void Event_Handle(SDL_Event &_event);

	virtual void Dispose();
};

