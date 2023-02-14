#pragma once

#include "platform.h"

void wires_draw();
void wires_handle(SDL_Event &e);

class Wire
{
public:
	std::vector<Vector2> Points;

	void Draw();
	void CreatePoint(int x, int y);
};

Wire* create_wire();