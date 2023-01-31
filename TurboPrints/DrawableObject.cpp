#include "DrawableObject.h"
#include "Content.h"

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
		render_texture(texture, renderer, position.x, position.y, tsize.x, tsize.y);
	}
}

void DrawableObject::Event_Handle(SDL_Event& _event)
{
}
