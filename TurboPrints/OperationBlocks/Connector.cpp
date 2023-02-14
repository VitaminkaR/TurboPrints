#include "Connector.h";

extern SDL_Renderer* gRenderer;
Connector *parent = 0;
// при соединении становится истинным, что в следующем кадре удалит ссылку на родителя
bool disable_parent = false;

Connector::Connector(void* parent_object)
{
	ParentObject = parent_object;
	ConnectWire = 0;
}

void Connector::Handler(SDL_Event &e, Vector2 position)
{
	Position = position;

	if(OtherConnectors.size() > 0)
		IsConnected = true;
	else
		IsConnected = false;

	if(ConnectWire != 0)
	{
		ConnectWire->Points.at(0) = { Position.x + 8, Position.y + 8 };
		if(OtherConnectors.size() > 0)
			ConnectWire->Points.at(ConnectWire->Points.size() - 1) = {OtherConnectors.at(0)->Position.x + 8, OtherConnectors.at(0)->Position.y + 8};
	}

	if (e.type == SDL_MOUSEBUTTONDOWN && check_button(e, Position.x, Position.y, 16, 16) && e.button.button == SDL_BUTTON_LEFT)
	{
		if (parent == 0)
		{
			parent = this;
			IsParent = true;
			ConnectWire = create_wire(); // добавляем провод
			ConnectWire->CreatePoint(0, 0);
		}
		else
		{
			if (this != parent)
			{
				// завершаем присоединение провода
				create_wire();
				// сначала дисконектим (чтобы не было одинкового подключения)
				UnConnect(parent);
				parent->UnConnect(this);

				// присоединяем
				parent->OtherConnectors.push_back(this);
				OtherConnectors.push_back(parent);
				parent->IsParent = false;
				disable_parent = true;
			}
		}
	}

	// отключение родителя
	if (parent == this && disable_parent)
	{
		parent = 0;
		disable_parent = false;
	}

	if (parent == this && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT)
	{
		if (parent->IsConnected)
		{
			for (int i = 0; i < OtherConnectors.size(); i++)
			{
				Connector* c = OtherConnectors.at(i);
				UnConnect(c);
			}
			OtherConnectors.clear();
		}
		parent->IsParent = false;
		disable_parent = true;
	}
}

void Connector::Draw()
{
	SDL_Rect outlineRect = { Position.x, Position.y, 16, 16 };
	if (IsParent)
		SDL_SetRenderDrawColor(gRenderer, 225, 0, 0, 255);
	else if (IsConnected)
		SDL_SetRenderDrawColor(gRenderer, 0, 225, 225, 255);
	else
		SDL_SetRenderDrawColor(gRenderer, 0, 225, 0, 255);
	
	SDL_RenderDrawRect(gRenderer, &outlineRect);
	SDL_RenderFillRect(gRenderer, &outlineRect);
}

void Connector::UnConnect(Connector* other_connector)
{
	for (int i = 0; i < other_connector->OtherConnectors.size(); i++)
	{
		if (other_connector->OtherConnectors.at(i) == this)
		{
			other_connector->OtherConnectors.erase(other_connector->OtherConnectors.begin() + i);
			break;
		}
	}
}