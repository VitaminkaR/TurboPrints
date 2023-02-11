#include "OperationBlock.h"

extern SDL_Texture* textures[];
extern SDL_Renderer* gRenderer;

std::vector<OperationBlock*> oelements;
std::string operation_types[TYPES_COUNT]
{
	"ADD",
	"SUB"
};

OperationBlock::OperationBlock()
{
	Position = { 0, 0 };
	Size = {256, 128};
	oelements.push_back(this);
}

void OperationBlock::Handler(SDL_Event& e)
{
	if (check_button(e, Position.x, Position.y, Size.x, Size.y) && e.button.button == SDL_BUTTON_LEFT)
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

void OperationBlock::Draw()
{
	SDL_Rect outlineRect = { Position.x, Position.y, Size.x, Size.y };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawRect(gRenderer, &outlineRect);
	SDL_RenderFillRect(gRenderer, &outlineRect);
	draw_text(Position.x + 8, Position.y + 8, TitleText, 0, 0, 0);
}