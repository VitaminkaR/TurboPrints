#include "RenderText.h"

FT_Library ft_lib;
FT_Face font;

Sym symbols[256];

const int quality = 128;

int FT_Init() 
{
	FT_Error error = FT_Init_FreeType(&ft_lib);
	if (error)
		return error;
}

int init_font(const char* path)
{
	FT_Error error = FT_New_Face(ft_lib, path, 0, &font);
	if (error)
		return error;

	FT_GlyphSlot slot = font->glyph;

	 error = FT_Set_Pixel_Sizes(font, quality * 4, quality);

	for (int i = 0; i < 256; i++)
	{
		FT_Error err = FT_Load_Char(font, (char)(i), FT_LOAD_RENDER);
		SDL_Surface* s = SDL_CreateRGBSurfaceFrom(slot->bitmap.buffer, slot->bitmap.width / 4, slot->bitmap.rows, 32, slot->bitmap.pitch, 0xff000000, 0x00ff0000, 0x0000ff00, 255);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, s);
		int w, h;
		SDL_QueryTexture(texture, 0, 0, &w, &h);
		Sym *sym = &symbols[i];
		sym->texture = texture; sym->w = w; sym->h = h;
		sym->gw = font->glyph->advance.x >> 6; sym->gh = font->glyph->metrics.horiBearingY >> 6;
		
		SDL_FreeSurface(s);
	}
}

void draw_text(int x, int y, SDL_Texture* texture, int r, int g, int b)
{
	SDL_SetTextureColorMod(texture, r, g, b);
	int w, h;
	SDL_QueryTexture(texture, 0, 0, &w, &h);
	render_texture(texture, gRenderer, x, y, w, h);
	SDL_SetTextureColorMod(texture, 255, 255, 255);
}

SDL_Texture* create_text( std::string text, float size)
{
	SDL_Texture *texture = SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, text.size() * quality * size, quality * size);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(gRenderer, texture);

	int xoffset = 0;
	for (int i = 0; i < text.size(); i++)
	{
		Sym sym = symbols[int(text[i])];
		SDL_Rect rect;
		rect.x = xoffset;
		rect.y = 0 - sym.gh * size  + quality * size;
		rect.w = sym.w * size;
		rect.h = sym.h * size;
		SDL_RenderCopy(gRenderer, sym.texture, 0, &rect);
		xoffset += sym.gw / 4 * size;
	}
	SDL_SetRenderTarget(gRenderer, 0);
	return texture;
}