#pragma once

#include "OperationBlock.h"

class OperationBlockNewLine : public OperationBlock
{
public:
	OperationBlockNewLine() : OperationBlock()
	{
		TitleText = create_text("NEWLINE", 0.15);
	}
	void CompileBlock(std::ofstream& out);
};