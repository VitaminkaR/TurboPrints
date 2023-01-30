#include "DrawableObject.h"

DrawableObject::DrawableObject()
{
}

DrawableObject::DrawableObject(Vector2 _position, SDL_Renderer& _renderer)
{
	position = _position;
	renderer = &_renderer;
}

DrawableObject::DrawableObject(Vector2 _position, SDL_Renderer& _renderer, SDL_Texture& _texture)
{
	position = _position;
	renderer = &_renderer;
	texture = &_texture;
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	tsize.x = w; tsize.y = h;
}

void DrawableObject::Set_Texture(SDL_Texture& _texture)
{
	texture = &_texture;
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	tsize.x = w; tsize.y = h;
}

void DrawableObject::Update()
{
}

void DrawableObject::Draw()
{
	if (texture != NULL) 
	{
		SDL_Rect info; info.x = position.x; info.y = position.y, info.w = tsize.x, info.h = tsize.y;
		SDL_RenderCopy(renderer, texture, &info, NULL);
	}
}

void DrawableObject::Event_Handle(SDL_Event& _event)
{
}
