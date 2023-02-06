#include "DataWindowManager.h"

extern SDL_Texture* textures[];
extern std::vector<Var> vars;
extern int stack_size;
extern const int WIDTH;

namespace DataWindowManager
{
	Vector2 add_var_button_pos = {0, 32};
	int list_offset;
	int id_edit_var = -1;
	int el_edit_var; // какой элемент настраивает пользователь (0-2) по структуре переменной соответственно
	std::string str_edit_type; // переменная для ввода типа
}

void DataWindowManager::Draw()
{
	render_texture(textures[4], gRenderer, add_var_button_pos.x, add_var_button_pos.y);
	for (int i = -1 * list_offset; i < 20 - list_offset; i++)
	{
		if (i >= vars.size())
			break;
		draw_text(0, (i + list_offset) * 32 + 64, vars.at(i).texture[0], 225, 0, 0);
		draw_text(512, (i + list_offset) * 32 + 64, vars.at(i).texture[1], 225, 225, 0);
		draw_text(740, (i + list_offset) * 32 + 64, vars.at(i).texture[2], 0, 200, 0);
	}
}

void DataWindowManager::Event_Handle(SDL_Event& e)
{
	if (check_button(e, add_var_button_pos.x, add_var_button_pos.y, textures[4]))
	{
		AddVar();
	}
	// управление скорллом
	if (e.type == SDL_MOUSEWHEEL)
	{
		list_offset += e.wheel.y;
		if(list_offset > 0)
			list_offset = 0;
		if(list_offset * -1 >= vars.size() - 5)
			list_offset = (vars.size() - 5) * -1;
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
			std::cout << id;
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
		// смотрим что конкретно будет настраивать пользователь
		if (e.button.button == SDL_BUTTON_LEFT && id_edit_var > -1)
		{
			if(mpos.x < 512)
				el_edit_var = 0;
			else if (mpos.x > 740)
				el_edit_var = 2;
			else
				el_edit_var = 1;
			std::cout << " - " << el_edit_var << std::endl;
		}
	}

	// само редактирование переменной
	if (e.type == SDL_KEYDOWN && id_edit_var > -1)
	{
		SDL_Keycode kc = e.key.keysym.sym;
		char c;

		// обработка спец клавиш
		if (!get_keyboard_char(c))
		{
			// enter или esc - выход из режима редактирования
			if (kc == 27 || kc == 13)
			{
				id_edit_var = -1;
				str_edit_type = "";
			}
				
			// стирает символ
			if (kc == 8)
			{
				if(el_edit_var == 0)
					vars.at(id_edit_var).name.pop_back();
				else if (el_edit_var == 1)
					str_edit_type = "";
				else
					vars.at(id_edit_var).value.pop_back();
				UpdateTextVar(&vars.at(id_edit_var));
			}

			return;
		}

		std::string* str;
		switch (el_edit_var)
		{
		case 0:
			str = &vars.at(id_edit_var).name;
			if (*str == "VARNAME")
				*str = "";
			*str += c;
			break;
		case 1:
			str_edit_type += c;
			// пытаемся присвоить тип
			vars.at(id_edit_var).var_type = get_vartype_string(str_edit_type);
			break;
		case 2:
			str = &vars.at(id_edit_var).value;
			if(*str == "?")
				*str = "";
			*str += c;
			break;
		}

		UpdateTextVar(&vars.at(id_edit_var));
	}
}

void DataWindowManager::AddVar()
{
	//debug
	Var v;
	v.name = "VARNAME";
	v.value = "?";
	v.var_type = BYTE;
	v.texture[0] = 0;
	v.texture[1] = 0;
	v.texture[2] = 0;
	v.texture[0] = create_text(v.name, 0.2);
	v.texture[1] = create_text(get_string_vartype(v.var_type), 0.2);
	v.texture[2] = create_text(v.value, 0.2);
	vars.push_back(v);
}

void DataWindowManager::UpdateTextVar(Var* var)
{
	if(var->texture[el_edit_var] != 0)
		SDL_DestroyTexture(var->texture[el_edit_var]);
	switch (el_edit_var)
	{
	case 0:
		var->texture[el_edit_var] = create_text(var->name, 0.2);
		break;
	case 1:
		var->texture[el_edit_var] = create_text(get_string_vartype(var->var_type), 0.2);
		break;
	case 2:
		var->texture[el_edit_var] = create_text(var->value, 0.2);
		break;
	}
}