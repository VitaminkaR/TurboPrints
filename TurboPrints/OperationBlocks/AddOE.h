#pragma once

#include "../OperationElement.h"


class AddOE : public OperationElement
{
public:
	AddOE(int x, int y) : OperationElement(x, y)
	{
		OENameText = create_text("BEGIN", 0.1f);
		Connectors.push_back(new Connector());
		Connectors.push_back(new Connector());
		Connectors.at(0)->OElement = (OperationElement*)this;
		Connectors.at(1)->OElement = (OperationElement*)this;
		Function = "ad";
	}

	void Handler(SDL_Event& e);
	void Draw();
};

