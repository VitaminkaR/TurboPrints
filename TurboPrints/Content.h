#pragma once

#include "platform.h"

SDL_Texture* load_image(SDL_Renderer *_renderer, const char *path);
void render_texture(SDL_Texture* _texture, SDL_Renderer* _renderer, int x, int y, int w, int h);


void load_content();
void unload_content();
