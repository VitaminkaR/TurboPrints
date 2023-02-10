#include "OperationElement.h"

extern SDL_Texture* textures[];
extern SDL_Renderer* gRenderer;

std::vector<OperationElement*> oelements;

Connector *parent = 0;

OperationElement::OperationElement(int x, int y)
{
	Position = { x, y };
	oelements.push_back(this);
}

void OperationElement::Handler(SDL_Event& e)
{
	for (int i = 0; i < Connectors.size(); i++)
	{
		Connector *con = Connectors.at(i);
		if (check_button(e, !(con->input) ? Position.x + 256 - 16 : Position.x - 16, Position.y + 8 + i * 32, 32, 32) && e.button.button == SDL_BUTTON_LEFT)
		{
			if (parent == 0)
			{
				parent = con;
				con->IsParent = true;
			}
			else
			{
				// коннектим
				con->next = parent->_this;
				parent->IsParent = false;
				parent = 0;
				con->IsParent = false;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT)
		{
			con->IsParent = false;
			parent = 0;
		}
	}

	if (check_button(e, Position.x, Position.y, 256, 128) && e.button.button == SDL_BUTTON_LEFT)
	{
		IsMove = true;
		MoveOffset = { e.button.x - Position.x, e.button.y - Position.y };
	}
	if (IsMove && e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
		IsMove = false;
	if (IsMove)
	{
		Position = {e.button.x - MoveOffset.x, e.button.y - MoveOffset.y};
	}
}

void OperationElement::Draw()
{
	render_texture(textures[5], gRenderer, Position.x, Position.y);
	draw_text(Position.x + 8, Position.y + 8, OENameText, 0, 0, 0);

	for (int i = 0; i < Connectors.size(); i++)
	{
		render_texture(textures[6], gRenderer, (!Connectors.at(i)->input) ? Position.x + 256 - 16 : Position.x - 16, Position.y + 8 + i * 32, 255, (Connectors.at(i)->IsParent) ? 0 : 255, (Connectors.at(i)->IsParent) ? 0 : 255);
	}
}