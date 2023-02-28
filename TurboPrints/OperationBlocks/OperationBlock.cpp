#include "OperationBlock.h"

extern SDL_Texture* textures[];
extern SDL_Renderer* gRenderer;

std::vector<OperationBlock*> oelements;

extern Vector2 camera_position;

// true когда пользователь перетаскивает один из блоков
bool once_move;

// счетчик меток для if и cycles operation blocks
int labels_count = 0;

OperationBlock::OperationBlock()
{
	Position = { 0, 0 };
	Size = { 256, 128 };
	oelements.push_back(this);
	CamPos = &camera_position;

	Connectors = new std::vector<Connector*>();
	InputsOperands = new std::vector<InputBox*>();
	Connectors->push_back(new Connector((OperationBlock*)this));
	Connectors->push_back(new Connector((OperationBlock*)this));
}

void OperationBlock::Handler(SDL_Event& e)
{
	if(!camera_on_screen(Position, Size))
		return;

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
		Position = { e.button.x - MoveOffset.x, e.button.y - MoveOffset.y };
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DELETE)
		{
			Delete();
			once_move = false;
			return;
		}
	}

	Connectors->at(0)->Handler(e, { Position.x + Size.x / 2 - 8 - CamPos->x, Position.y - 8 - CamPos->y });
	Connectors->at(1)->Handler(e, { Position.x + Size.x / 2 - 8 - CamPos->x, Position.y + Size.y - 8 - CamPos->y });
	if (Connectors->size() == 3)
		Connectors->at(2)->Handler(e, { Position.x + Size.x - 16 - CamPos->x, Position.y + Size.y - 8 - CamPos->y });

	for (int i = 0; i < InputsOperands->size(); i++)
	{
		InputsOperands->at(i)->Position = { Position.x + 16 - CamPos->x + 64 * (i % 2), Position.y + Size.y - 64 - CamPos->y + 32 * (i / 2) };
		InputsOperands->at(i)->Handler(e);
	}
}

void OperationBlock::Draw()
{
	if (!camera_on_screen(Position, Size))
		return;

	SDL_Rect outlineRect = { Position.x - CamPos->x, Position.y - CamPos->y, Size.x, Size.y };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawRect(gRenderer, &outlineRect);
	SDL_RenderFillRect(gRenderer, &outlineRect);
	draw_text(Position.x + 8 - CamPos->x, Position.y + 8 - CamPos->y, TitleText, 0, 0, 0);

	for (int i = 0; i < Connectors->size(); i++)
	{
		Connectors->at(i)->Draw();
	}
	for (int i = 0; i < InputsOperands->size(); i++)
	{
		InputsOperands->at(i)->Draw();
	}
}

void OperationBlock::Delete()
{
	for (int i = 0; i < Connectors->size(); i++)
	{
		Connector *current_connector = Connectors->at(i);
		for (int j = 0; j < current_connector->OtherConnectors.size(); j++)
		{
			Connector *other_connector = current_connector->OtherConnectors.at(j);
			for (int k = 0; k < other_connector->OtherConnectors.size(); k++)
			{
				if(other_connector->OtherConnectors.at(k) == current_connector)
					other_connector->OtherConnectors.erase(other_connector->OtherConnectors.begin() + k);
			}
		}
		delete Connectors->at(i);
	}
	delete Connectors;
	for (int i = 0; i < InputsOperands->size(); i++)
	{
		delete InputsOperands->at(i);
	}
	delete InputsOperands;
	SDL_DestroyTexture(TitleText);
	for (int i = 0; i < oelements.size(); i++)
	{
		if (oelements.at(i) == this)
		{
			oelements.erase(oelements.begin() + i);
			break;
		}
	}
	delete this;
}