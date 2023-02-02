#include "DataWindowManager.h"

DataWindowManager::DataWindowManager()
{
	Vector2 v; v.x = 32, v.y = 32;
	add_var_button = new Button(v, textures->at(4));
}

void DataWindowManager::Show()
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
	
}