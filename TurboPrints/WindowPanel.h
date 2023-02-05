#pragma once

#include "platform.h"
#include "Content.h"

namespace WindowPanel
{
	void Event_Handle(SDL_Event& e);
	int Get_Mode();
	void Draw();
};