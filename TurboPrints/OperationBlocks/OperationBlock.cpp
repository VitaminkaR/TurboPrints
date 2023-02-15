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

extern Vector2 camera_position;

// true когда пользователь перетаскивает один из блоков
bool once_move;

// счетчик меток для if и cycles operation blocks
int labels_count = 0;

OperationBlock::OperationBlock()
{
	Position = { 0, 0 };
	Size = {256, 128};
	oelements.push_back(this);
	CamPos = &camera_position;

	BaseInputConnector = new Connector((OperationBlock*)this);
	BaseOutputConnector = new Connector((OperationBlock*)this);
}

void OperationBlock::BaseHandler(SDL_Event& e)
{
	if (!once_move && check_button(e, Position.x - camera_position.x, Position.y - camera_position.y, Size.x, Size.y) && e.button.button == SDL_BUTTON_LEFT)
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

	BaseInputConnector->Handler(e, {Position.x + Size.x / 2 - 8 - CamPos->x, Position.y - 8 - CamPos->y });
	BaseOutputConnector->Handler(e, { Position.x + Size.x / 2 - 8 - CamPos->x, Position.y  + Size.y - 8 - CamPos->y });

	Handler(e);
}

void OperationBlock::BaseDraw()
{
	SDL_Rect outlineRect = { Position.x - CamPos->x, Position.y - CamPos->y, Size.x, Size.y };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawRect(gRenderer, &outlineRect);
	SDL_RenderFillRect(gRenderer, &outlineRect);
	draw_text(Position.x + 8 - CamPos->x, Position.y + 8 - CamPos->y, TitleText, 0, 0, 0);

	BaseInputConnector->Draw();
	BaseOutputConnector->Draw();

	Draw();
}

