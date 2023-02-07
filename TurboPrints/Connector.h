#pragma once

#include "platform.h"
#include "Button.h"
#include "Content.h"

class Connector
{
public:
	Vector2 Position;
	// объект с которым этот коннектор соединен
	Connector *Unite;
	// операционный элемент часть которого является текущий коннектор
	void *OElement;
	// является ли родителем (т е хочет ли соединится) (для графики)
	bool IsParent;
	
	void Draw();
	void Handler(SDL_Event &e);
};