#pragma once

#include "OperationBlock.h"

class OperationBlockFor : public OperationBlock
{
public:
	OperationBlockFor() : OperationBlock()
	{
		Size = { 256, 128 };
		TitleText = create_text("FOR", 0.15);
		InputsOperands->push_back(new InputBox(Position.x + 16, Position.y + Size.y - 64, 32, 32, "var", 225, 0, 0));
		InputsOperands->push_back(new  InputBox(Position.x - 80 + Size.x, Position.y + Size.y - 64, 32, 32, "value", 225, 0, 0));
		Connectors->push_back(new Connector((OperationBlock*)this));
	}
	void CompileBlock(std::ofstream& out);
};