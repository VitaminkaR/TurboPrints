#pragma once

#include "Connector.h"
#include "../InputBox.h"
#include "../RenderText.h"
#include "../Camera.h"

const int TYPES_COUNT = 7;

class OperationBlock
{
public:
	Vector2 Position;
	Vector2 MoveOffset;
	Vector2 Size;
	bool IsMove;
	SDL_Texture *TitleText;
	Vector2 *CamPos;

	std::vector<Connector*> *Connectors;
	std::vector<InputBox*> *InputsOperands;

	OperationBlock();
	void Handler(SDL_Event &e);
	void Draw();
	void Delete();
	virtual void CompileBlock(std::ofstream &out) = 0;
};

void create_opeartion_block(int id);