#pragma once

#include "Button.h"
#include "Compile.h"
#include "RenderText.h";
#include "Content.h"
#include "KeyboardHandler.h"

namespace DataWindowManager
{
	void Draw();
	void Event_Handle(SDL_Event &e);
	void UpdateTextVar(Var *var);

	void AddVar();
};