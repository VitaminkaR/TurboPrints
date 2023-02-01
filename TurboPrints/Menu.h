#pragma once
#include "DrawableObject.h"
#include "Button.h"
#include "Compile.h"

extern const int WIDTH;
extern const int HEIGHT;
extern SDL_Renderer *gRenderer;
extern std::vector<SDL_Texture*>* textures;
extern std::vector<DrawableObject*>* objects;

class Menu : public DrawableObject
{
public:

	Button *call_button;
	Button *compile_button;

    Menu();
	void Call_Button();

	void Show();
	void Close();

	void Draw();

	bool isShow;

	void Event_Handle(SDL_Event& e);

	void Dispose();
};
