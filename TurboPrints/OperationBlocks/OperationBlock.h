#pragma once

#include "Connector.h"
#include "../InputBox.h"
#include "../RenderText.h"

const int TYPES_COUNT = 3;

class OperationBlock
{
public:
	Vector2 Position;
	Vector2 MoveOffset;
	Vector2 Size;
	bool IsMove;
	SDL_Texture *TitleText;


	Connector *BaseInputConnector;
	Connector *BaseOutputConnector;

	OperationBlock();
	void BaseHandler(SDL_Event &e);
	void BaseDraw();
	virtual void CompileBlock(std::ofstream &out) = 0;
	virtual void Handler(SDL_Event &e) = 0;
	virtual void Draw() = 0;
};

void create_opeartion_block(int id);