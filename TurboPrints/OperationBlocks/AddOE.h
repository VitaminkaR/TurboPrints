#pragma once

#include "../OperationElement.h"


class AddOE : public OperationElement
{
public:
	AddOE(int x, int y) : OperationElement(x, y)
	{
		OENameText = create_text("ADD", 0.1f);
		Connectors.push_back(new Connector());
		Connectors.push_back(new Connector());
		Connectors.at(0)->input = true;
	}

	void Handler(SDL_Event& e);
	void Draw();
	void CompileBlock();
};

