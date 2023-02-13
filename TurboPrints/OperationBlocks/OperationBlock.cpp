#include "OperationBlock.h"

extern SDL_Texture* textures[];
extern SDL_Renderer* gRenderer;

std::vector<OperationBlock*> oelements;
std::string operation_types[TYPES_COUNT]
{
	"ADD",
	"SUB",
	"IF"
};

// true ����� ������������ ������������� ���� �� ������
bool once_move;

// ������� ����� ��� if � cycles operation blocks
int labels_count = 0;

OperationBlock::OperationBlock()
{
	Position = { 0, 0 };
	Size = {256, 128};
	oelements.push_back(this);

	BaseInputConnector = new Connector((OperationBlock*)this);
	BaseOutputConnector = new Connector((OperationBlock*)this);
}

void OperationBlock::BaseHandler(SDL_Event& e)
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

	BaseInputConnector->Handler(e, {Position.x + Size.x / 2 - 8, Position.y - 8});
	BaseOutputConnector->Handler(e, { Position.x + Size.x / 2 - 8, Position.y  + Size.y - 8});

	Handler(e);
}

void OperationBlock::BaseDraw()
{
	SDL_Rect outlineRect = { Position.x, Position.y, Size.x, Size.y };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawRect(gRenderer, &outlineRect);
	SDL_RenderFillRect(gRenderer, &outlineRect);
	draw_text(Position.x + 8, Position.y + 8, TitleText, 0, 0, 0);

	BaseInputConnector->Draw();
	BaseOutputConnector->Draw();

	Draw();
}

