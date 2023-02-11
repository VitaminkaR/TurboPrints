#pragma once

#include "platform.h"
#include "InputBox.h"
#include "RenderText.h"
#include "Button.h"

const int TYPES_COUNT = 2;

class OperationBlock
{
public:
	Vector2 Position;
	Vector2 MoveOffset;
	Vector2 Size;
	bool IsMove;
	SDL_Texture *TitleText;

	OperationBlock();
	void Handler(SDL_Event &e);
	void Draw();
	//virtual void CompileBlock() = 0;
};

void create_opeartion_block(int id)
{
	switch (id)
	{
	case 0:
		break;
	}
}