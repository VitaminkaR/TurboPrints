#pragma once

#include "OperationBlock.h"

class OperationBlockDiv : public OperationBlock
{
public:
	InputBox *FirstOperand;
	InputBox *SecondOperand;

	OperationBlockDiv() : OperationBlock()
	{
		TitleText = create_text("DIV", 0.15);
		FirstOperand = new InputBox(Position.x + 16, Position.y + Size.y - 64, 32, 32, "var", 225, 0, 0);
		SecondOperand = new InputBox(Position.x - 80 + Size.x, Position.y + Size.y - 64, 32, 32, "number", 225, 0, 0);
	}
	void CompileBlock(std::ofstream& out);
	void Handler(SDL_Event& e);
	void Draw();
};