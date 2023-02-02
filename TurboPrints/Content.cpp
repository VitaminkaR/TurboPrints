#include "Content.h"

extern std::vector<SDL_Texture*>* textures;
extern SDL_Renderer* gRenderer;

void load_content()
{
	textures = new std::vector<SDL_Texture*>();
	textures->push_back(load_image(gRenderer, "./Resource/images/menu_button.png"));
	textures->push_back(load_image(gRenderer, "./Resource/images/control_panel.png"));
	textures->push_back(load_image(gRenderer, "./Resource/images/compile_button.png"));
	textures->push_back(load_image(gRenderer, "./Resource/images/window_panel.png"));
	textures->push_back(load_image(gRenderer, "./Resource/images/add_var_button.png"));
}

void unload_content()
{
	for (int i = 0; i < textures->size(); i++)
	{
		SDL_DestroyTexture(textures->at(i));
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

void render_texture(SDL_Texture* _texture, SDL_Renderer* _renderer, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x; dst.y = y; dst.w = w; dst.h = h;
	SDL_RenderCopy(_renderer, _texture, NULL, &dst);
}
