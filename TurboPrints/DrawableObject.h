#pragma once

#include "platform.h"

class DrawableObject
{
public:
	Vector2 position;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	Vector2 tsize;

	DrawableObject();
	DrawableObject(Vector2 _position, SDL_Renderer &_renderer);
	DrawableObject(Vector2 _position, SDL_Renderer& _renderer, SDL_Texture &_texture);

	void Set_Texture(SDL_Texture &_texture);

	virtual void Update();

	virtual void Draw();

	virtual void Event_Handle(SDL_Event &_event);
};

