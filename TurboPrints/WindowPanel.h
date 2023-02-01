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

	void Event_Handle(SDL_Event& e);
};