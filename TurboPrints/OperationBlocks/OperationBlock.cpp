#include "OperationBlock.h"

extern SDL_Texture* textures[];
extern SDL_Renderer* gRenderer;

std::vector<OperationBlock*> oelements;
std::string operation_types[TYPES_COUNT]
{
	"ADD",
	"SUB"
};

// true когда пользователь перетаскивает один из блоков
bool once_move;

OperationBlock::OperationBlock()
{
	Position = { 0, 0 };
	Size = {256, 128};
	oelements.push_back(this);

	input = new Connector((OperationBlock*)this);
	output = new Connector((OperationBlock*)this);
}

void OperationBlock::Handler(SDL_Event& e)
{
	if (!once_move && check_button(e, Position.x, Position.y, Size.x, Size.y) && e.button.button == SDL_BUTTON_LEFT)
	{
		once_move = true;
		IsMove = true;
		MoveOffset = { e.button.x - Position.x, e.button.y - Position.y };
	}
	if (IsMove && e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
	{
		IsMove = false;
		once_move = false;
	}
	if (IsMove)
	{
		Position = {e.button.x - MoveOffset.x, e.button.y - MoveOffset.y};
	}

	input->Handler(e, {Position.x + Size.x / 2 - 8, Position.y - 8});
	output->Handler(e, { Position.x + Size.x / 2 - 8, Position.y  + Size.y - 8});
}

void OperationBlock::Draw()
{
	SDL_Rect outlineRect = { Position.x, Position.y, Size.x, Size.y };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawRect(gRenderer, &outlineRect);
	SDL_RenderFillRect(gRenderer, &outlineRect);
	draw_text(Position.x + 8, Position.y + 8, TitleText, 0, 0, 0);

	input->Draw();
	output->Draw();
}

void create_opeartion_block(int id)
{
	switch (id)
	{
	case 0:
		OperationBlock *b = new OperationBlock();
		b->IsMove = true;
		break;
	}
}