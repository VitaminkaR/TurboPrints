#pragma once

#include "DrawableObject.h"
#include "Button.h"
#include "Compile.h"
#include "RenderText.h";
#include "KeyboardHandler.h"

extern std::vector<SDL_Texture*>* textures;
extern std::vector<Var> vars;

class DataWindowManager : public DrawableObject
{
public:
	Button *add_var_button;
	int list_offset;
	int id_edit_var = -1;
	int el_edit_var; // какой элемент настраивает пользователь (0-2) по структуре переменной соответственно
	std::string str_edit_type; // переменная для ввода типа

	DataWindowManager();

	void Draw();
	void Event_Handle(SDL_Event &e);
	void Dispose();
	void UpdateTextVar(Var *var);

	void AddVar();
};