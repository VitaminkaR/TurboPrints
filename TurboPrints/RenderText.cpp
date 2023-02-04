#include "RenderText.h"

FT_Library ft_lib;
FT_Face font;

std::vector<Sym> symbols;

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

	for (int i = 0; i < 255; i++)
	{
		FT_Error err = FT_Load_Char(font, (char)(i), FT_LOAD_RENDER);
		SDL_Surface* s = SDL_CreateRGBSurfaceFrom(slot->bitmap.buffer, slot->bitmap.width / 4, slot->bitmap.rows, 32, slot->bitmap.pitch, 0xff000000, 0x00ff0000, 0x0000ff00, 255);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, s);
		int w, h;
		SDL_QueryTexture(texture, 0, 0, &w, &h);
		Sym sym; sym.texture = texture; sym.w = w; sym.h = h; 
		sym.gw = font->glyph->advance.x >> 6; sym.gh = font->glyph->metrics.horiBearingY >> 6;
		symbols.push_back(sym);
		SDL_FreeSurface(s);
	}
}

void draw_text(int x, int y, std::string text)
{
	int xoffset = x;
	for (int i = 0; i < text.size(); i++)
	{
		Sym sym = symbols.at(int(text[i]));
		render_texture(sym.texture, gRenderer, xoffset, y - sym.gh,sym.w, sym.h);
		xoffset += sym.gw / 4;
	}
}

void draw_text(int x, int y, std::string text, float size)
{
	int xoffset = x;
	for (int i = 0; i < text.size(); i++)
	{
		Sym sym = symbols.at(int(text[i]));
		render_texture(sym.texture, gRenderer, xoffset, y - sym.gh / size, sym.w / size, sym.h / size);
		xoffset += sym.gw / 4 / size;
	}
}

void draw_text(int x, int y, std::string text, int r, int g, int b)
{
	int xoffset = x;
	for (int i = 0; i < text.size(); i++)
	{
		Sym sym = symbols.at(int(text[i]));
		SDL_SetTextureColorMod(sym.texture, r, g, b);
		render_texture(sym.texture, gRenderer, xoffset, y - sym.gh, sym.w, sym.h);
		SDL_SetTextureColorMod(sym.texture, 255, 255, 255);
		xoffset += sym.gw / 4;
	}
}

void draw_text(int x, int y, std::string text, int r, int g, int b, float size)
{
	int xoffset = x;
	for (int i = 0; i < text.size(); i++)
	{
		Sym sym = symbols.at(int(text[i]));
		SDL_SetTextureColorMod(sym.texture, r, g, b);
		render_texture(sym.texture, gRenderer, xoffset, y - sym.gh / size, sym.w / size, sym.h / size);
		SDL_SetTextureColorMod(sym.texture, 255, 255, 255);
		xoffset += sym.gw / 4 / size;
	}
}