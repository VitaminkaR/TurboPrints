#include "BeginOE.h"

void BeginOE::Handler(SDL_Event& e)
{
	BaseHandler(e);
	StartConnector->Position = { Position.x + 200, Position.y + 70 };
	StartConnector->Handler(e);
}

void BeginOE::Draw()
{
	BaseDraw();
	StartConnector->Draw();
}