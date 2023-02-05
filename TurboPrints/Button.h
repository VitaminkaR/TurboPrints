#pragma once

#include "platform.h"

bool check_button(SDL_Event &e, int x, int y, int w, int h);
bool check_button(SDL_Event& e, int x, int y, SDL_Texture *texture);

