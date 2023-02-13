#pragma once

#include "OperationBlock.h"

class OperationBlockIf : public OperationBlock
{
public:
	InputBox *FirstOperand;
	InputBox *SecondOperand;
	InputBox *OperationOperand;
	Connector *TrueConnector;

	OperationBlockIf() : OperationBlock()
	{
		Size = {256, 128};
		TitleText = create_text("IF", 0.15);
		FirstOperand = new InputBox(Position.x + 16, Position.y + Size.y - 64, 32, 32, "var", 225, 0, 0);
		SecondOperand = new InputBox(Position.x - 80 + Size.x, Position.y + Size.y - 64, 32, 32, "number", 225, 0, 0);
		OperationOperand = new InputBox(Position.x - 10 + Size.x / 2, Position.y + Size.y - 64, 32, 32, "=", 225, 0, 0);
		TrueConnector = new Connector((OperationBlock*)this);
	}
	void CompileBlock(std::ofstream& out);
	void Handler(SDL_Event& e);
	void Draw();

	// стандартно компилирует блоки, но при этом проверяет нет ли в будущем коннекторе двойного присоединения
	// двойное присоединение является знаком выхода, т к (пока что) оно возникает только в случае
	// когда ветка true и false присоединены к общему блоку (имеют общее продолжение, а значит код должен компилироваться по стандарту)
	OperationBlock* CompileIfBranch(std::ofstream &out, Connector *connector);
};