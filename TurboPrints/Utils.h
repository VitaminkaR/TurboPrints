#pragma once

struct Vector2f
{
	float x, y;
};

struct Vector2
{
	int x, y;
};

bool IntersectRectPoint(int x1, int y1, int x2, int y2, int w1, int h1);
