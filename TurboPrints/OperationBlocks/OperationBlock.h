#pragma once

#include "Connector.h"
#include "../InputBox.h"
#include "../RenderText.h"

const int TYPES_COUNT = 2;

class OperationBlock
{
public:
	Vector2 Position;
	Vector2 MoveOffset;
	Vector2 Size;
	bool IsMove;
	SDL_Texture *TitleText;

	Connector *input;
	Connector *output;

	OperationBlock();
	void Handler(SDL_Event &e);
	void Draw();
	//virtual void CompileBlock() = 0;
};

void create_opeartion_block(int id);