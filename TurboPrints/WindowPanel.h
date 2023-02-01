#pragma once
#include "DrawableObject.h"

extern const int WIDTH;
extern const int HEIGHT;
extern SDL_Renderer* gRenderer;
extern std::vector<SDL_Texture*>* textures;
extern std::vector<DrawableObject*>* objects;

class WindowPanel : public DrawableObject
{
public:
	WindowPanel();

	std::vector<DrawableObject*>* objects_copy;

	// mode 0 - cheme 1- data
	int mode = 0;
	void DataWorktop();
	void SchemeWorktop();

	void Event_Handle(SDL_Event& e);

	void Dispose();
};