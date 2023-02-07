#pragma once

#include "platform.h"
#include "Button.h"
#include "OperationElement.h"
#include "Content.h"

class Connector
{
public:
	Vector2 Position;
	// ������ � ������� ���� ��������� ��������
	Connector *Unite;
	// ������������ ������� ����� �������� �������� ������� ���������
	OperationElement *OElement;
	// �������� �� ��������� (� � ����� �� ����������) (��� �������)
	bool isParent;
	
	// ������� x � y �������� ������������ ������������� ��������
	Connector(int x, int y, OperationElement *element);
	void Draw();
	void Handler(SDL_Event &e);
};