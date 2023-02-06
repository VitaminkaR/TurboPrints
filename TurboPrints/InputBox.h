#pragma once
#include "platform.h"
#include "RenderText.h";
#include "Content.h"
#include "KeyboardHandler.h"
#include "Button.h"

class InputBox
{
public:
	std::string Text;
	SDL_Texture *Text_texture;
	Vector2 Position;
	Vector2 Size;
	int r, g, b;
	bool Focus;

	 InputBox(int x, int y, int w, int h, std::string start_text, int _r, int _g, int _b);
	 std::string Handler(SDL_Event &e);
	 void Draw();
};