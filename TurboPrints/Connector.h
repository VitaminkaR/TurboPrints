#pragma once

#include "platform.h"
#include "Button.h"
#include "Content.h"

class Connector
{
public:
	Vector2 Position;
	// ������ � ������� ���� ��������� ��������
	Connector *Unite;
	// ������������ ������� ����� �������� �������� ������� ���������
	void *OElement;
	// �������� �� ��������� (� � ����� �� ����������) (��� �������)
	bool IsParent;
	
	void Draw();
	void Handler(SDL_Event &e);
};