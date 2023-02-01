#include "Utils.h"

bool IntersectRectPoint(int x1, int y1, int x2, int y2, int w1, int h1)
{
	return x1 < x2&& y1 < y2&& x1 + w1 > x2&& y1 + h1 > y2;
}