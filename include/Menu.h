#ifndef _MENU_H
#define _MENU_H
#include <kos.h>
#include "GameObject.h"
#include "Texture.h"
#include "FontManager.h"
#include "Text.h"

class Menu: public IGameObject{
public:
	Menu();
	~Menu();
	virtual void Update(GAME_STATE *gs);
	virtual void Draw();
	virtual void Input(GAME_STATE *gs, cont_state_t *state);
private:
	Texture bg;
    Texture bg1;
    Texture bg2;
    Texture bg3;
    Texture bg4;
    Texture bg5;
    Texture bg6;
    Text txt;
};

#endif