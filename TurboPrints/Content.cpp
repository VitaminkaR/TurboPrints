#include "Content.h"
#include "RenderText.h"

const int TEXTURE_COUNT = 64;
SDL_Texture* textures[TEXTURE_COUNT];
extern SDL_Renderer* gRenderer;

void load_content()
{
	init_font("Volkswagen medium.ttf");

	textures[0] = load_image(gRenderer, "./Resource/images/menu_button.png");
	textures[1] = load_image(gRenderer, "./Resource/images/control_panel.png");
	textures[2] = load_image(gRenderer, "./Resource/images/compile_button.png");
	textures[3] = load_image(gRenderer, "./Resource/images/window_panel.png");
	textures[4] = load_image(gRenderer, "./Resource/images/add_var_button.png");
}

void unload_content()
{
	for (int i = 0; i < TEXTURE_COUNT; i++)
	{
		SDL_DestroyTexture(textures[i]);
	}
}

SDL_Texture* load_image(SDL_Renderer *_renderer, const char *path)
{
	SDL_Texture *texture = IMG_LoadTexture(_renderer, path);
	if (texture == NULL)
	{
		std::cout << "Loading image error " << path << " " << IMG_GetError() << std::endl;
	}

	return texture;
}

void render_texture(SDL_Texture* _texture, SDL_Renderer* _renderer, int x, int y)
{
	SDL_Rect dst;
	dst.x = x; 
	dst.y = y;
	SDL_QueryTexture(_texture, 0, 0, &dst.w, &dst.h);
	SDL_RenderCopy(_renderer, _texture, NULL, &dst);
}
