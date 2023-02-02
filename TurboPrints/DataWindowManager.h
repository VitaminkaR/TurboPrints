#pragma once

#include "DrawableObject.h"
#include "Button.h"
#include "Compile.h"

extern std::vector<SDL_Texture*>* textures;
extern std::vector<Var> vars;

class DataWindowManager : public DrawableObject
{
public:
	Button *add_var_button;

	DataWindowManager();

	void Show();
	void Event_Handle(SDL_Event &e);
	void Dispose();

	void AddVar();
};