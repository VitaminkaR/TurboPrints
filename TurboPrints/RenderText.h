#pragma once

#include "platform.h"
#include "Content.h"
#include "ft2build.h"
#include FT_FREETYPE_H

extern SDL_Renderer* gRenderer;

int FT_Init();
int load_font(const char *path);
int set_font_size(int size);
void draw_text(int x, int y, std::string text);
void render_text(int x, int y, FT_Bitmap& bitmap);