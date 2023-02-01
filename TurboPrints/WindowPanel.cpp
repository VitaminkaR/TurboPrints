#include "WindowPanel.h"

WindowPanel::WindowPanel()
{
	mode = 1;
	tag = "winpan";
	position.x = WIDTH / 5 + 32;
	position.y = 0;
	Set_Texture(*textures->at(3));
}

void WindowPanel::DataWorktop()
{
	objects = windows[1];

	mode = 0;
}
void WindowPanel::SchemeWorktop()
{
	objects = windows[0];

	mode = 1;
}

void WindowPanel::Event_Handle(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (!mode && IntersectRectPoint(position.x, 0, e.button.x, e.button.y, 86, 16))
		{
			std::cout << "WP:SCHEME" << std::endl;
			SchemeWorktop();
		}
		if (mode == 1 && IntersectRectPoint(position.x + 92, 0, e.button.x, e.button.y, 58, 16))
		{
			std::cout << "WP:DATA" << std::endl;
			DataWorktop();
		}
	}
}

void WindowPanel::Dispose()
{
	for (int i = 0; i < WINDOW_COUNT; i++)
	{
		if (windows[i] != 0)
		{
			for (int j = 0; j < windows[i]->size(); j++)
			{
				windows[i]->at(j)->Dispose();
				delete windows[i]->at(j);
			}
			delete windows[i];
		}
	}
}

std::vector<DrawableObject*>** WindowPanel::GetScene(int id)
{
	return windows+id;
}