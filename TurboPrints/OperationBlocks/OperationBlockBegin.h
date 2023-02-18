#pragma once

#include "OperationBlock.h"

class OperationBlockBegin : public OperationBlock
{
public:
	OperationBlockBegin() : OperationBlock()
	{
		TitleText = create_text("BEGIN", 0.35);
	}
	void CompileBlock(std::ofstream& out);
};