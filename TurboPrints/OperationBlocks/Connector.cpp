#include "Connector.h";

extern SDL_Renderer* gRenderer;
Connector *parent = 0;

Connector::Connector(void* parent_object)
{
	ParentObject = parent_object;
}

void Connector::Handler(SDL_Event &e, Vector2 position)
{
	Position = position;
	if (e.type == SDL_MOUSEBUTTONDOWN && check_button(e, Position.x, Position.y, 16, 16) && e.button.button == SDL_BUTTON_LEFT)
	{
		if (parent == 0)
		{
			parent = this;
			IsParent = true;
		}
		else
		{
			if (this != parent)
			{
				parent->IsConnected = true;
				parent->OtherConnector = this;
				OtherConnector = parent;
				parent->IsParent = false;
				parent = 0;
				IsConnected = true;
			}
		}
	}

	if (parent != 0 && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT)
	{
		if (parent->IsConnected)
		{
			parent->OtherConnector->IsConnected = false;
			parent->OtherConnector->OtherConnector = 0;
			parent->OtherConnector = 0;
			parent->IsConnected = false;
		}
		parent->IsParent = false;
		parent = 0;
	}
}

void Connector::Draw()
{
	SDL_Rect outlineRect = { Position.x, Position.y, 16, 16 };
	if (IsParent)
		SDL_SetRenderDrawColor(gRenderer, 225, 0, 0, 255);
	else if (IsConnected)
		SDL_SetRenderDrawColor(gRenderer, 0, 225, 225, 255);
	else
		SDL_SetRenderDrawColor(gRenderer, 0, 225, 0, 255);
	
	SDL_RenderDrawRect(gRenderer, &outlineRect);
	SDL_RenderFillRect(gRenderer, &outlineRect);
}