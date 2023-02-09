#include "ControlPanel.h"

extern const int HEIGHT;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* textures[];

// ��������� ������������ ���������
extern ElementType element_types[];
extern const int OETYPES_COUNT;
std::vector<SDL_Texture*> oe_text_textures;


namespace ControlPanel
{
	Vector2 call_button_pos = { WIDTH - 32, 0 };

	int list_offset;
	bool focus; // ���� ������ ������ ������� ������
	bool isShow = false;
}

void ControlPanel::Init()
{
	for (int i = 0; i < OETYPES_COUNT; i++)
	{
		oe_text_textures.push_back(create_text(element_types[i].name, 0.2));
	}
}

void ControlPanel::Draw()
{
	render_texture(textures[1], gRenderer, call_button_pos.x, call_button_pos.y);
	if (isShow)
	{
		SDL_Rect fillRect = { WIDTH - WIDTH / 5, 0, WIDTH / 5, HEIGHT };
		SDL_SetRenderDrawColor(gRenderer, 225, 225, 225, 0xFF);
		SDL_RenderFillRect(gRenderer, &fillRect);

		// ��������� ������
		for (int i = 0; i < OETYPES_COUNT; i++)
		{
			draw_text(WIDTH - WIDTH / 5 + 8, (i + list_offset) * 32 + 32, oe_text_textures[i], 225, 0, 0);
		}
	}
}

void ControlPanel::Event_Handle(SDL_Event& e)
{
	if (isShow)
	{
		if (IntersectRectPoint(WIDTH - WIDTH / 5, 0, e.button.x, e.button.y, WIDTH / 5, HEIGHT))
		{
			focus = true;
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				int ofs = e.button.y - 32;
				int id = ofs / 32;
				if(ofs < 0)
					id -= 1;
				id -= list_offset;
				
				// ����� id �� � ������� ���
				create_operation_element(id);
			}
		}
		else
		{
			// ���� ����� �� ����������� � �������� ������ ������ � ������ �(�������) �����������
			if (e.type == 1024)
				focus = false;
		}
		if (e.type == SDL_MOUSEWHEEL && focus)
		{
			list_offset += e.wheel.y;
			if (list_offset > 0)
				list_offset = 0;
			if (list_offset * -1 >= OETYPES_COUNT + 1)
				list_offset = OETYPES_COUNT * -1;
		}
	}

	if (check_button(e, call_button_pos.x, call_button_pos.y, textures[1]))
	{
		if (isShow)
		{
			call_button_pos.x = WIDTH - 32;
			isShow = false;
		}
		else
		{
			call_button_pos.x = WIDTH - WIDTH / 5 - 32;
			isShow = true;
		}
	}
}