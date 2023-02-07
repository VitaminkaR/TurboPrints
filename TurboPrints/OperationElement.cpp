#include "OperationElement.h"

extern SDL_Texture* textures[];
extern SDL_Renderer* gRenderer;

std::vector<OperationElement*> oelements;

OperationElement* create_operation_element(int x, int y, int type)
{
	switch (type)
	{
	case 0:
		return 0;
		break;
	}
}

OperationElement::OperationElement(int x, int y)
{
	Position = { x, y };
	oelements.push_back(this);
}

void OperationElement::BaseHandler(SDL_Event& e)
{
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

void OperationElement::BaseDraw()
{
	render_texture(textures[5], gRenderer, Position.x, Position.y);
	draw_text(Position.x + 8, Position.y + 8, OENameText, 0, 0, 0);
}

void OperationElement::Handler(SDL_Event &e)
{

}

void OperationElement::Draw()
{

}