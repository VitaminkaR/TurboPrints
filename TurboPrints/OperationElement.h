#pragma once

#include "platform.h"
#include "RenderText.h"
#include "Button.h"

class OperationElement
{
public:
	Vector2 Position;
	Vector2 MoveOffset;
	bool IsMove;
	SDL_Texture *OENameText;

	OperationElement(int x, int y);
	void Handler(SDL_Event &e);
	virtual void Draw();
};

// ���������� ����������� ��������� (��� ���������� ������ ��������, ��������� ��� �����)
// ����� ��������, ��� �� �� ������ � ControlPanel, ������� ��� ������ ���� ������ �����������
OperationElement* create_operation_element(int x, int y, int type);