#include "DataWindowManager.h"

extern SDL_Texture* textures[];
extern std::vector<Var> vars;
extern std::string stack_size;
extern const int WIDTH;

namespace DataWindowManager
{
	Vector2 add_var_button_pos = { 0, 32 };
	int list_offset;
	int id_edit_var = -1;
	int el_edit_var; // какой элемент настраивает пользователь (0-2) по структуре переменной соответственно
	std::string str_edit_type; // переменная для ввода типа
	InputBox* stack_input_box;
	SDL_Texture *stack_label;
}

void DataWindowManager::Init()
{
	stack_input_box = new InputBox(WIDTH - 200, 32, 200, 32, "stack size", 225, 0, 0);
	stack_label = create_text("STACK SIZE", 0.25);
}

void DataWindowManager::Draw()
{
	render_texture(textures[4], gRenderer, add_var_button_pos.x, add_var_button_pos.y);
	draw_text(WIDTH - 228, 0, stack_label, 225, 225, 225);
	stack_input_box->Draw();
	for (int i = -1 * list_offset; i < 20 - list_offset; i++)
	{
		if (i >= vars.size())
			break;
		vars.at(i).inputs[0]->Position = { 0, (i + list_offset) * 32 + 64 };
		vars.at(i).inputs[1]->Position = { 512, (i + list_offset) * 32 + 64 };
		vars.at(i).inputs[2]->Position = { 740, (i + list_offset) * 32 + 64 };
		vars.at(i).inputs[0]->Draw();
		vars.at(i).inputs[1]->Draw();
		vars.at(i).inputs[2]->Draw();
	}
}

void DataWindowManager::Event_Handle(SDL_Event& e)
{
	if (id_edit_var == -1)
		stack_size = stack_input_box->Handler(e);
	if (check_button(e, add_var_button_pos.x, add_var_button_pos.y, textures[4]))
	{
		AddVar();
	}
	// управление скорллом
	if (e.type == SDL_MOUSEWHEEL)
	{
		list_offset += e.wheel.y;
		if (list_offset > 0)
			list_offset = 0;
		if (list_offset * -1 >= vars.size() - 5)
			list_offset = ((int)vars.size() - 5) * -1;
	}

	// выбор редактирования переменных и их удаление
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		Vector2 mpos; mpos.x = e.button.x; mpos.y = e.button.y;
		// находим индекс переменной на которую нажал пользователь
		int ofs = mpos.y - 64;
		if(ofs < 0)
			return;
		int id = ofs / 32;
		if (id >= 0 && id <= 20 && id - list_offset < vars.size())
		{
			id -= list_offset;
			id_edit_var = id;
		}
		else
		{
			id_edit_var = -1;
		}

		// удаление переменной
		if (e.button.button == SDL_BUTTON_RIGHT && id_edit_var > -1)
		{
			vars.erase(vars.begin() + id_edit_var);
		}
	}

	if (id_edit_var != -1)
	{
		std::string str = vars.at(id_edit_var).inputs[1]->Handler(e);
		vars.at(id_edit_var).name = (char)(get_vartype_string(str)) + vars.at(id_edit_var).inputs[0]->Handler(e);
		vars.at(id_edit_var).value = vars.at(id_edit_var).inputs[2]->Handler(e);
	}

	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
		id_edit_var = -1;
}

void DataWindowManager::AddVar()
{
	Var v;
	v.name = "VARNAME";
	v.value = "?";
	v.inputs[0] = new InputBox(0, 0, 512, 32, "VARNAME", 225, 0, 0);
	v.inputs[1] = new InputBox(0, 0, 228, 32, "BYTE", 225, 225, 0);
	v.inputs[2] = new InputBox(0, 0, 540, 32, "?", 0, 225, 0);
	vars.push_back(v);
}