#ifndef _MENU_H
#define _MENU_H
#include "GameObject.h"
#include "Texture.h"

class Menu: public IGameObject{
public:
	Menu();
	~Menu();
	virtual void Update(GAME_STATE *gs);
	virtual void Draw();
	virtual void Input(GAME_STATE *gs);
private:
	Texture bg;
};

#endif