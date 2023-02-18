#pragma once

#include "OperationBlock.h"

class OperationBlockIf : public OperationBlock
{
public:
	OperationBlockIf() : OperationBlock()
	{
		Size = {256, 128};
		TitleText = create_text("IF", 0.15);
		InputsOperands->push_back(new InputBox(0, 0, 32, 32, "var", 225, 0, 0));
		InputsOperands->push_back(new InputBox(0, 0, 32, 32, "number", 225, 0, 0));
		InputsOperands->push_back(new InputBox(0, 0, 32, 32, "?", 225, 0, 0));
		Connectors->push_back(new Connector((OperationBlock*)this));
	}
	void CompileBlock(std::ofstream& out);

	// стандартно компилирует блоки, но при этом проверяет нет ли в будущем коннекторе двойного присоединения
	// двойное присоединение является знаком выхода, т к (пока что) оно возникает только в случае
	// когда ветка true и false присоединены к общему блоку (имеют общее продолжение, а значит код должен компилироваться по стандарту)
	OperationBlock* CompileIfBranch(std::ofstream &out, Connector *connector);
};