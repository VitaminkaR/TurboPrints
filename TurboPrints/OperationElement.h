#pragma once

#include "platform.h"
#include "RenderText.h"
#include "Button.h"
#include "Connector.h"

class OperationElement
{
public:
	Vector2 Position;
	Vector2 MoveOffset;
	bool IsMove;
	SDL_Texture *OENameText;
	std::vector<Connector*> Connectors;
	std::string Function;

	OperationElement(int x, int y);
	void BaseHandler(SDL_Event &e);
	virtual void Handler(SDL_Event &e);
	void BaseDraw();
	virtual void Draw();
};