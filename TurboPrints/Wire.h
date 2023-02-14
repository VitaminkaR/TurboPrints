#pragma once

#include "platform.h"

class Wire
{
public:
	std::vector<Vector2> Points;

	void Draw();
	void CreatePoint(Vector2 vec);
	void UpdatePos(Vector2 vec1, Vector2 vec2);
};

Wire* create_wire(Vector2 vec1, Vector2 vec2);