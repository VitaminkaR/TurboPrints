#pragma once

#include "platform.h"
#include "Content.h"
#include "ft2build.h"
#include FT_FREETYPE_H

extern SDL_Renderer* gRenderer;

int FT_Init();
int init_font(const char* path);
void draw_text(int x, int y, std::string text);
void draw_text(int x, int y, std::string text, float size);
void draw_text(int x, int y, std::string text, int r, int g, int b);
void draw_text(int x, int y, std::string text, int r, int g, int b, float size);

struct Sym
{
	SDL_Texture *texture;
	int w, h;
	int gw, gh; // glyph metrics (gw - advance size, gh - рассто€ние от базовой линии до высшей точки знака)
};