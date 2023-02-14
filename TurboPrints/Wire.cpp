#include "Wire.h"

extern SDL_Renderer* gRenderer;

const int grid = 16;

Wire* create_wire(Vector2 vec1, Vector2 vec2)
{
	Wire* wire = new Wire();
	wire->CreatePoint(vec1);
	Vector2 offset = { vec1.x - vec2.x, vec1.y - vec2.y };
	wire->CreatePoint({ vec1.x, vec1.y - offset.y / 2 });
	wire->CreatePoint({ vec2.x, vec1.y - offset.y / 2 });
	wire->CreatePoint(vec2);
	return wire;
}



void Wire::Draw()
{
	int sp = Points.size();
	if (sp == 0)
		return;
	for (int i = 0; i < sp - 1; i++)
	{
		Vector2 first = Points.at(i);
		Vector2 second = Points.at(i + 1);
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderDrawLine(gRenderer, first.x, first.y, second.x, second.y);
	}
}

void Wire::CreatePoint(Vector2 vec)
{
	Points.push_back({ vec.x + 8, vec.y + 8 });
}

void Wire::UpdatePos(Vector2 vec1, Vector2 vec2)
{
	int ofy = vec1.y - vec2.y;
	Points.at(0) = { vec1.x + 8, vec1.y + 8 };
	Points.at(1) = { vec1.x + 8, vec1.y - ofy / 2 + 8 };
	Points.at(2) = { vec2.x + 8, vec1.y - ofy / 2 + 8 };
	Points.at(3) = { vec2.x + 8, vec2.y + 8 };
}