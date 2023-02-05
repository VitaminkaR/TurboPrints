#pragma once

#include "Button.h"
#include "Content.h"

extern const int WIDTH;

namespace ControlPanel
{
	void Draw();
	void Event_Handle(SDL_Event& e);
};