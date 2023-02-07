#include "BeginOE.h"

void BeginOE::Handler(SDL_Event& e)
{
	BaseHandler(e);
	Connectors.at(0)->Position = { Position.x + 200, Position.y + 40 };
	Connectors.at(0)->Handler(e);
}

void BeginOE::Draw()
{
	BaseDraw();
	Connectors.at(0)->Draw();
}