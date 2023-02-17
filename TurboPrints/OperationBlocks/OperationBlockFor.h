#pragma once

#include "OperationBlock.h"

class OperationBlockFor : public OperationBlock
{
public:
	InputBox *FirstOperand;
	InputBox *SecondOperand;
	Connector *CycleConnector;

	OperationBlockFor() : OperationBlock()
	{
		Size = {256, 128};
		TitleText = create_text("FOR", 0.15);
		FirstOperand = new InputBox(Position.x + 16, Position.y + Size.y - 64, 32, 32, "var", 225, 0, 0);
		SecondOperand = new InputBox(Position.x - 80 + Size.x, Position.y + Size.y - 64, 32, 32, "value", 225, 0, 0);
		CycleConnector = new Connector((OperationBlock*)this);
	}
	void CompileBlock(std::ofstream& out);
	void Handler(SDL_Event& e);
	void Draw();
};