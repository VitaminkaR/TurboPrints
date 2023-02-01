#include "WindowPanel.h"

WindowPanel::WindowPanel()
{
	mode = 1;
	tag = "winpan";
	position.x = WIDTH / 5 + 32;
	position.y = 0;
	Set_Texture(*textures->at(3));

	objects_copy = new std::vector<DrawableObject*>();
}

void WindowPanel::DataWorktop()
{
	if(objects_copy->size() == 0) objects_copy->push_back(Find<DrawableObject>("winpan"));
	std::vector<DrawableObject*>* temp = objects;
	objects = objects_copy;
	objects_copy = temp;

	mode = 0;
}
void WindowPanel::SchemeWorktop()
{
	std::vector<DrawableObject*>* temp = objects;
	objects = objects_copy;
	objects_copy = temp;

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
	for (int i = 0; i < objects_copy->size(); i++)
	{
		objects_copy->at(i)->Dispose();
		delete objects_copy->at(i);
	}
	delete objects_copy;
}