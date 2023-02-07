#pragma once

#include "platform.h"
#include "Button.h"
#include "OperationElement.h"
#include "Content.h"

class Connector
{
public:
	Vector2 Position;
	// объект с которым этот коннектор соединен
	Connector *Unite;
	// операционный элемент часть которого является текущий коннектор
	OperationElement *OElement;
	// является ли родителем (т е хочет ли соединится) (для графики)
	bool isParent;
	
	// позиция x и y задается относительно операционного элемента
	Connector(int x, int y, OperationElement *element);
	void Draw();
	void Handler(SDL_Event &e);
};