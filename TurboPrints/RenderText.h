#pragma once

#include "platform.h"
#include "Content.h"
#include "ft2build.h"
#include FT_FREETYPE_H

extern SDL_Renderer* gRenderer;

int FT_Init();
int init_font(const char* path);
void draw_text(int x, int y, std::string text);

struct Sym
{
	SDL_Texture *texture;
	int w, h;
};