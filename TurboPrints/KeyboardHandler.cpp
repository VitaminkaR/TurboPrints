#include "KeyboardHandler.h"

bool isCapsLock;
bool isShift;
char currentChar;
SDL_Scancode currentScanCode;

bool get_keyboard_char(char &c)
{
    c = currentChar;

	if (currentScanCode == SDL_SCANCODE_LSHIFT ||
		currentScanCode == SDL_SCANCODE_RSHIFT ||
		currentScanCode == SDL_SCANCODE_TAB ||
		currentScanCode == SDL_SCANCODE_RCTRL ||
		currentScanCode == SDL_SCANCODE_LCTRL ||
		currentScanCode == SDL_SCANCODE_CAPSLOCK ||
		currentScanCode == SDL_SCANCODE_ESCAPE ||
		currentScanCode == SDL_SCANCODE_RETURN ||
		currentScanCode == SDL_SCANCODE_BACKSPACE) return false;

	bool isBig = isCapsLock ^ isShift;
	if (isBig) 
	{
		c = (char)std::toupper(c);

		if(currentScanCode == SDL_SCANCODE_0)
			c = ')';
		else if(currentScanCode == SDL_SCANCODE_1)
			c = '!';
		else if (currentScanCode == SDL_SCANCODE_2)
			c = '@';
		else if (currentScanCode == SDL_SCANCODE_3)
			c = '#';
		else if (currentScanCode == SDL_SCANCODE_4)
			c = '$';
		else if (currentScanCode == SDL_SCANCODE_5)
			c = '%';
		else if (currentScanCode == SDL_SCANCODE_6)
			c = '^';
		else if (currentScanCode == SDL_SCANCODE_7)
			c = '&';
		else if (currentScanCode == SDL_SCANCODE_8)
			c = '*';
		else if (currentScanCode == SDL_SCANCODE_9)
			c = '(';
		else if (currentScanCode == SDL_SCANCODE_MINUS)
			c = '_';
		else if (currentScanCode == SDL_SCANCODE_PERIOD)
			c = '>';
		else if (currentScanCode == SDL_SCANCODE_COMMA)
			c = '<';
	}
		
	return true;
}

void keyboard_handler(SDL_Event &e)
{
	if (e.type == SDL_KEYDOWN)
	{
		SDL_Scancode sc = e.key.keysym.scancode;
		SDL_Keycode kc = e.key.keysym.sym;
		currentChar = (char)kc;
		currentScanCode = sc;

		if(sc == SDL_SCANCODE_CAPSLOCK)
			isCapsLock = !isCapsLock;
		if(sc == SDL_SCANCODE_LSHIFT)
			isShift = true;
	}
	if (e.type == SDL_KEYUP)
	{
		SDL_Scancode sc = e.key.keysym.scancode;
		if (sc == SDL_SCANCODE_LSHIFT)
			isShift = false;
		currentScanCode = sc;
	}
}