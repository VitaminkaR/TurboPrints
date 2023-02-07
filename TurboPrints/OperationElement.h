#pragma once

#include "platform.h"
#include "RenderText.h"
#include "Button.h"
#include "Connector.h"

class OperationElement
{
public:
	Vector2 Position;
	Vector2 MoveOffset;
	bool IsMove;
	SDL_Texture *OENameText;

	OperationElement(int x, int y);
	void BaseHandler(SDL_Event &e);
	virtual void Handler(SDL_Event &e);
	void BaseDraw();
	virtual void Draw();
};

// происходит регистрация элементов (при добавлении нового элемента, прописать его здесь)
// цифра элемента, это ай ди кнопки в ControlPanel, поэтому они должны быть строго согласованы
OperationElement* create_operation_element(int x, int y, int type);