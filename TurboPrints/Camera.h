#pragma once

#include "platform.h"

extern const int WIDTH;
extern const int HEIGHT;

void camera_get_position(Vector2 *vec);
// входит ли область в отрисовываемую
bool camera_on_screen(Vector2 pos, Vector2 size);
void camera_handle(SDL_Event &e);