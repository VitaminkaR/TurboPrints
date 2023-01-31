#include "DrawableObject.h"
#include "Button.h"

extern const int WIDTH;
extern const int HEIGHT;
extern SDL_Renderer* gRenderer;
extern std::vector<SDL_Texture*>* textures;
extern std::vector<DrawableObject*>* objects;

class ControlPanel : public DrawableObject
{
public:
	Button* call_button;

	int list_offset;
	bool focus; // если курсор внутри области панели

	void Init();
	void Call_Button();

	void Show();
	void Close();

	void Draw();

	bool isShow;

	void Event_Handle(SDL_Event& e);
};