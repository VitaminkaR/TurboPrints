#pragma once

#include "OperationBlock.h"

class OperationBlockWrite : public OperationBlock
{
public:
	OperationBlockWrite() : OperationBlock()
	{
		TitleText = create_text("WRITE", 0.15);
		InputsOperands->push_back(new InputBox(Position.x + 16, Position.y + Size.y - 64, 32, 32, "var", 225, 0, 0));
	}
	void CompileBlock(std::ofstream& out);
};