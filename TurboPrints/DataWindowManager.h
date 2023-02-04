#pragma once

#include "DrawableObject.h"
#include "Button.h"
#include "Compile.h"
#include "RenderText.h";

extern std::vector<SDL_Texture*>* textures;
extern std::vector<Var> vars;

class DataWindowManager : public DrawableObject
{
public:
	Button *add_var_button;
	int list_offset;

	DataWindowManager();

	void Draw();
	void Event_Handle(SDL_Event &e);
	void Dispose();

	void AddVar();
};