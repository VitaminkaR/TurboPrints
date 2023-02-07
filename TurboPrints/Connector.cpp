#include "Connector.h"

extern SDL_Texture* textures[];
extern SDL_Renderer* gRenderer;

Connector *parent = 0;

void Connector::Draw()
{
	if(!IsParent)
		render_texture(textures[6], gRenderer, Position.x, Position.y);
	else
		render_texture(textures[6], gRenderer, Position.x, Position.y, 225, 0, 0);
}

void Connector::Handler(SDL_Event& e)
{
	if (check_button(e, Position.x, Position.y, 32, 32) && e.button.button == SDL_BUTTON_LEFT)
	{
		if(parent == 0)
		{
			parent = this;
			IsParent = true;
		}
		else
		{
			// коннектим
			this->Unite = parent;
			parent->Unite = this;
			parent = 0;
			IsParent = false;
		}
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT)
	{
		IsParent = false;
		parent = 0;
	}
}
