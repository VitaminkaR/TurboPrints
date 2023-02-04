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
	for (int i = -1 * list_offset; i < 20 - list_offset; i++)
	{
		if (i >= vars.size())
			break;
		draw_text(0, 96 + (i + list_offset) * 32, vars.at(i).name, 255, 0, 0, 0.2);
		std::string var_type = get_string_vartype(vars.at(i).var_type);
		draw_text(256, 96 + (i + list_offset) * 32, var_type, 200, 200, 50, 0.2);
		draw_text(400, 96 + (i + list_offset) * 32, vars.at(i).value, 0, 250, 0, 0.2);
	}
}

void DataWindowManager::Event_Handle(SDL_Event& e)
{
	if (add_var_button->Request(e))
	{
		AddVar();
	}
	if (e.type == SDL_MOUSEWHEEL)
	{
		list_offset += e.wheel.y;
		if(list_offset > 0)
			list_offset = 0;
		if(list_offset * -1 >= vars.size() - 5)
			list_offset = (vars.size() - 5) * -1;
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
	v.name = "VARNAME";
	v.value = "?";
	v.var_type = BYTE;
	vars.push_back(v);
}