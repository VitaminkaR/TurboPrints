#include "WindowPanel.h"

extern const int WIDTH;
extern const int TEXTURE_COUNT = 64;
extern SDL_Texture* textures[TEXTURE_COUNT];
extern SDL_Renderer* gRenderer;

namespace WindowPanel
{
	// mode 0 - cheme 1- data
	int mode = 0;
}

void WindowPanel::Draw()
{
	render_texture(textures[3], gRenderer, WIDTH / 5 + 32, 0);
}

int WindowPanel::Get_Mode()
{
	return mode;
}

void WindowPanel::Event_Handle(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (mode == 1 && IntersectRectPoint(WIDTH / 5 + 32, 0, e.button.x, e.button.y, 86, 16))
		{
			mode = 0;
		}
		if (!mode && IntersectRectPoint(WIDTH / 5 + 32 + 92, 0, e.button.x, e.button.y, 58, 16))
		{
			mode = 1;
		}
	}
}