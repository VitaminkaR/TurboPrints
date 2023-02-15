#include "Camera.h"

Vector2 camera_position = {0, 0};
Vector2 camera_mouse_offset = {0, 0};
bool camera_hold = false;

void camera_get_position(Vector2* vec)
{
	vec->x = camera_position.x;
	vec->y = camera_position.y;
}

void camera_handle(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_MIDDLE && !camera_hold)
	{
		camera_hold = true;
		camera_mouse_offset = {e.button.x + camera_position.x, e.button.y + camera_position.y};
	}
	if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_MIDDLE && camera_hold)
	{
		camera_hold = false;
	}
	if (e.type == SDL_MOUSEMOTION && camera_hold)
	{
		camera_position = {camera_mouse_offset.x - e.button.x, camera_mouse_offset.y - e.button.y };
	}
}