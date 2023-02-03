#include "RenderText.h"

FT_Library ft_lib;
FT_Face font;

int FT_Init() 
{
	FT_Error error = FT_Init_FreeType(&ft_lib);
	if (error)
		return error;
}

int load_font(const char* path)
{
	FT_Error error = FT_New_Face(ft_lib, path, 0, &font);
	if (error)
		return error;
}

int set_font_size(int size)
{
	FT_Error error = FT_Set_Pixel_Sizes(font, 0, size);
	if (error)
		return error;
}

void draw_text(int x, int y, std::string text)
{
	FT_GlyphSlot slot = font->glyph;

	for (int i = 0; i < text.size(); i++)
	{
		FT_Load_Char(font, text[i], FT_LOAD_RENDER);
	}
	render_text(x, y, slot->bitmap);
}

void render_text(int x, int y, FT_Bitmap& bitmap)
{
	SDL_Surface *s = SDL_CreateRGBSurfaceFrom(bitmap.buffer, bitmap.width, bitmap.rows, 1, bitmap.pitch, 0, 0, 0, 0);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, s);
	int w, h;
	SDL_QueryTexture(texture, 0, 0, &w, &h);
	render_texture(texture, gRenderer, x, y, w, h);
	std::string error = SDL_GetError();
}