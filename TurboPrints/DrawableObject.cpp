#include "DrawableObject.h"

DrawableObject::DrawableObject(Vector2 _position, SDL_Renderer& _renderer)
{
	position = _position;
	renderer = &_renderer;
}

void DrawableObject::Update()
{
}

void DrawableObject::Draw()
{
}

void DrawableObject::Event_Handle(SDL_Event& _event)
{
}
