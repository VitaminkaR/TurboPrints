#include "AddOE.h"

void AddOE::Handler(SDL_Event& e)
{
	BaseHandler(e);
	Connectors.at(0)->Position = { Position.x + 200, Position.y + 32 };
	Connectors.at(0)->Handler(e);
	Connectors.at(1)->Position = { Position.x + 200, Position.y + 64 };
	Connectors.at(1)->Handler(e);
}

void AddOE::Draw()
{
	BaseDraw();
	Connectors.at(0)->Draw();
	Connectors.at(1)->Draw();
}