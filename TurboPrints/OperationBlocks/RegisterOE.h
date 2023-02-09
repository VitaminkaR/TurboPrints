#pragma once

#include "../OperationElement.h"
#include "AddOE.h"

const int OETYPES_COUNT = 2;

struct ElementType
{
	std::string name;
	int id;
};

// ���������� ����������� ��������� (��� ���������� ������ ��������, ��������� ��� �����)
// ����� ��������, ��� �� �� ������ � ControlPanel, ������� ��� ������ ���� ������ �����������
OperationElement* create_operation_element(int type);