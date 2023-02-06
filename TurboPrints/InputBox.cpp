#include "InputBox.h"

InputBox::InputBox(int x, int y, int w, int h, std::string start_text, int _r, int _g, int _b)
{
	Position = { x, y };
	Size = { w, h };
	r = _r;
	g = _g;
	b = _b;
	Text_texture = create_text(start_text, h / 32 * 0.2f);
}

void InputBox::Draw()
{
	draw_text(Position.x, Position.y, Text_texture, r, g, b);
}

std::string InputBox::Handler(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && IntersectRectPoint(Position.x, Position.y, e.button.x, e.button.y, Size.x, Size.y))
	{
		Focus = true;
	}

	if (e.type == SDL_KEYDOWN && Focus)
	{
		char c;
		bool non_special = get_keyboard_char(c);
		if (c == SDL_KeyCode::SDLK_RETURN || c == SDL_KeyCode::SDLK_ESCAPE)
		{
			Focus = false;
			return Text;
		}

		if (c == SDL_KeyCode::SDLK_BACKSPACE && Text.size() > 0)
			Text.pop_back();
		if (non_special)
			Text += c;

		Text_texture = create_text(Text, Size.y / 32 * 0.2f);
	}
	return Text;
}