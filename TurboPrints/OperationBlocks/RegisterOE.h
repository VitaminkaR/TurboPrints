#pragma once

#include "../OperationElement.h"
#include "AddOE.h"

// ���������� ����������� ��������� (��� ���������� ������ ��������, ��������� ��� �����)
// ����� ��������, ��� �� �� ������ � ControlPanel, ������� ��� ������ ���� ������ �����������
OperationElement* create_operation_element(int x, int y, int type);