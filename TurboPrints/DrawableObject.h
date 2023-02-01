#pragma once

#include "platform.h"

extern SDL_Renderer* gRenderer;

class DrawableObject
{
public:
	Vector2 position;
	SDL_Texture *texture;
	Vector2 tsize;
	std::string tag;

	DrawableObject();
	DrawableObject(std::string _tag);

	void Set_Texture(SDL_Texture &_texture);

	virtual void Update();

	virtual void Draw();

	virtual void Event_Handle(SDL_Event &_event);

	virtual void Dispose();
};

extern std::vector<DrawableObject*>* objects;

template<typename T>
T* Find(std::string _tag)
{
	for (int i = 0; i < objects->size(); i++)
	{
		if (objects->at(i)->tag == _tag)
		{
			DrawableObject* _obj = objects->at(i);
			T* obj = (T*)_obj;
			return obj;
		}
	}
	return nullptr;
}