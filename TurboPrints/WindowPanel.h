#pragma once
#include "DrawableObject.h"

extern const int WIDTH;
extern const int HEIGHT;
extern SDL_Renderer* gRenderer;
extern std::vector<SDL_Texture*>* textures;
extern std::vector<DrawableObject*>* objects;

const int WINDOW_COUNT = 5;

// ����� ������� �������� ������� ���������� ������
// ����������� �������� (�� ������ �� � ���� �����("����������" ������))
class WindowPanel : public DrawableObject
{
public:
	WindowPanel();

	// �������� ��� ����(�����) ����������
	std::vector<DrawableObject*>* windows[WINDOW_COUNT];

	// mode 0 - cheme 1- data
	int mode = 0;
	void DataWorktop();
	void SchemeWorktop();

	// 0 - scheme editor
	// 1 - data editor
	std::vector<DrawableObject*>** GetScene(int id);

	void Event_Handle(SDL_Event& e);

	void Dispose();
};