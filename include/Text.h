#ifndef _TEXT_H
#define _TEXT_H

#include <kos.h>
#include <dcplib/fnt.h>
#include <string>
#include "GameObject.h"
#include "FontManager.h"

class Text: public IGameObject{
public:
    Text();
	Text(const char*, int, fntTexFont*);
	~Text();
	virtual void Update(GAME_STATE *gs);
	virtual void Draw();
	virtual void Input(GAME_STATE *gs, cont_state_t *state);
private:
	fntRenderer* fRenderer;
    fntTexFont* font;
    std::string text;
};

#endif