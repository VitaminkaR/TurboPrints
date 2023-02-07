#pragma once

#include "../OperationElement.h"


class BeginOE : public OperationElement
{
public:
	Connector *StartConnector;

	BeginOE(int x, int y) : OperationElement(x, y)
	{
		OENameText = create_text("BEGIN", 0.1);
		StartConnector = new Connector();
		StartConnector->OElement = (OperationElement*)this;
	}

	void Handler(SDL_Event &e);
	void Draw();
};