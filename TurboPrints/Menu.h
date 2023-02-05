#pragma once

#include "Button.h"
#include "Compile.h"
#include "Content.h"

extern const int HEIGHT;

namespace Menu
{
	void Draw();
	void Event_Handle(SDL_Event& e);
};
