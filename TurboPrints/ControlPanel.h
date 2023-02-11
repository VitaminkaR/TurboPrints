#pragma once

#include "Button.h"
#include "Content.h"
#include "OperationBlock.h"

extern const int WIDTH;

namespace ControlPanel
{
	void Init();
	void Draw();
	void Event_Handle(SDL_Event& e);
};