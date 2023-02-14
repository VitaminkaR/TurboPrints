#include "Wire.h"

extern SDL_Renderer* gRenderer;

const int grid = 16;

// редактируемый провод
Wire *current = 0;
// список проводов
std::vector<Wire*> wires;

void wires_draw()
{
	for (int i = 0; i < wires.size(); i++)
	{
		wires.at(i)->Draw();
	}
	// отрисовка во время создания провода
	if (current)
	{
		current->Draw();
		if (current->Points.size() > 0)
		{
			Vector2 last_point = current->Points.at(current->Points.size() - 1);
			int mx, my;
			SDL_GetMouseState(&mx, &my);
			SDL_RenderDrawLine(gRenderer, last_point.x, last_point.y, mx / grid * grid, my / grid * grid);
		}
	}
}

void wires_handle(SDL_Event& e)
{
	if (current && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
	{
		current->CreatePoint(e.button.x, e.button.y);
	}
	if (current && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT)
	{
		delete current;
	}
}

Wire* create_wire()
{
	if (current == 0)
	{
		current = new Wire();
		return current;
	}
	else
	{
		wires.push_back(current);
		current = 0;
	}
}



void Wire::Draw()
{
	int sp = Points.size();
	if(sp == 0)
		return;
	for (int i = 0; i < sp - 1; i++)
	{
		Vector2 first = Points.at(i);
		Vector2 second = Points.at(i+1);
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderDrawLine(gRenderer, first.x, first.y, second.x, second.y);
	}
}

void Wire::CreatePoint(int x, int y)
{
	Points.push_back({x / grid * grid, y / grid * grid });
}