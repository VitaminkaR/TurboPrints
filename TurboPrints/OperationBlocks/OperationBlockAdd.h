#pragma once

#include "OperationBlock.h"

class OperationBlockAdd : public OperationBlock
{
public:
	OperationBlockAdd() : OperationBlock()
	{
		TitleText = create_text("ADD", 0.15);
	}
	void CompileBlock(std::ofstream& out);
	void Handler(SDL_Event& e);
	void Draw();
};