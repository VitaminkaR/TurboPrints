#pragma once

#include "../platform.h"
#include "../Button.h"

class Connector
{
public:
	Vector2 Position;
	void *ParentObject;
	std::vector<Connector*> OtherConnectors;
	bool IsParent;
	bool IsConnected;
	
	Connector(void *parent_object);

	void Handler(SDL_Event &e, Vector2 position);
	void Draw();

	// ��������� ������ ��������� �� �������
	void UnConnect(Connector *other_connector);
};