#pragma once

#include "platform.h"
#include "InputBox.h"
#include "RenderText.h"
#include "Button.h"

struct Connector ;

class OperationElement
{
public:
	Vector2 Position;
	Vector2 MoveOffset;
	bool IsMove;
	SDL_Texture *OENameText;
	std::vector<Connector*> Connectors;
	std::vector<InputBox*> Inputs;
	std::string Function;

	OperationElement(int x, int y);
	void Handler(SDL_Event &e);
	void Draw();
};

struct Connector
{
	bool IsParent;
	OperationElement* next;
	OperationElement* _this;
};