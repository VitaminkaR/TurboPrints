#pragma once

#include "../OperationElement.h"


class BeginOE : public OperationElement
{
public:
	BeginOE(int x, int y) : OperationElement(x, y)
	{
		OENameText = create_text("BEGIN", 0.1f);
		Connectors.push_back(new Connector());
		Connectors.at(0)->OElement = (OperationElement*)this;
		Function = "start_point";
	}

	void Handler(SDL_Event &e);
	void Draw();
};