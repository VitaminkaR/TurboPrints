#pragma once

#include "DrawableObject.h"

class Button : public DrawableObject
{
public:
	// event press button
	void(*action)(Vector2 mpos, int button_type, int clicks);

	Button(Vector2 _position, SDL_Renderer& _renderer, SDL_Texture &_texture, void(*action)(Vector2 mpos, int button_type, int clicks));
	Button(Vector2 _position, SDL_Renderer& _renderer, int w, int h, void(*action)(Vector2 mpos, int button_type, int clicks));

	void Event_Handle(SDL_Event& _event);
};

