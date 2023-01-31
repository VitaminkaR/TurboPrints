#include "DrawableObject.h"
#include "Button.h"

extern const int WIDTH;
extern const int HEIGHT;
extern SDL_Renderer* gRenderer;

class ControlPanel : public DrawableObject
{
public:
	Button* call_button;

	void Init(std::vector<DrawableObject*>* _objects, std::vector<SDL_Texture*>* _textures);
	void Call_Button();

	void Show();
	void Close();

	void Draw();

	bool isShow;

	void Event_Handle(SDL_Event& e);
};