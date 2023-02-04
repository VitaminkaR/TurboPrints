#include "DataWindowManager.h"
#include "InputBox.h"

DataWindowManager::DataWindowManager()
{
	Vector2 v; v.x = 0; v.y = 32;
	add_var_button = new Button(v, textures->at(4));
}

void DataWindowManager::Draw()
{
	add_var_button->Draw();
}

void DataWindowManager::Event_Handle(SDL_Event& e)
{
	if (add_var_button->Request(e))
	{
		AddVar();
	}
}

void DataWindowManager::Dispose()
{
	delete add_var_button;
}

void DataWindowManager::AddVar()
{
	//debug
	Var v;
	v.name = "a";
	v.value = "5";
	v.var_type = BYTE;
	vars.push_back(v);
	v.name = "_str";
	v.value = "Hello!";
	v.var_type = STRING;
	vars.push_back(v);
}