#pragma once

#include "Button.h"
#include "Compile.h"
#include "InputBox.h"

namespace DataWindowManager
{
	void Init();
	void Draw();
	void Event_Handle(SDL_Event &e);

	void AddVar();
};