#ifndef _SPLASHSCREEN_H
#define _SPLASHSCREEN_H
#include "GameObject.h"
#include "Texture.h"

class SplashScreen: public IGameObject{
public:
	SplashScreen();
	virtual ~SplashScreen();
	virtual void Update(GAME_STATE *gs);
	virtual void Draw();
	virtual void Input(GAME_STATE *gs);
private:
	float alpha;
	float fadeRate;
	Texture bg;
};

#endif