#pragma once

#include "OperationBlock.h"

class OperationBlockMul : public OperationBlock
{
public:
	OperationBlockMul() : OperationBlock()
	{
		TitleText = create_text("MUL", 0.15);
		InputsOperands->push_back(new InputBox(Position.x + 16, Position.y + Size.y - 64, 32, 32, "var", 225, 0, 0));
		InputsOperands->push_back(new InputBox(Position.x - 80 + Size.x, Position.y + Size.y - 64, 32, 32, "number", 225, 0, 0));
	}
	void CompileBlock(std::ofstream& out);
};