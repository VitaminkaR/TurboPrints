#include "DrawableObject.h"
#include "Content.h"

DrawableObject::DrawableObject()
{

}
DrawableObject::DrawableObject(std::string _tag)
{
	tag = _tag;
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
		render_texture(texture, gRenderer, position.x, position.y, tsize.x, tsize.y);
	}
}

void DrawableObject::Event_Handle(SDL_Event& _event)
{
}

void DrawableObject::Dispose()
{

}