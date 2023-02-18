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

	// ���������� ����������� �����, �� ��� ���� ��������� ��� �� � ������� ���������� �������� �������������
	// ������� ������������� �������� ������ ������, � � (���� ���) ��� ��������� ������ � ������
	// ����� ����� true � false ������������ � ������ ����� (����� ����� �����������, � ������ ��� ������ ��������������� �� ���������)
	OperationBlock* CompileIfBranch(std::ofstream &out, Connector *connector);
};