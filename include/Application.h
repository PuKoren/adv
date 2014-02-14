#ifndef _APPLICATION_H
#define _APPLICATION_H
#include <kos.h>
#include <png/png.h>
#include <zlib/zlib.h>
#include <vector>

#include "Vector3.h"
#include "GameObject.h"
#include "SplashScreen.h"
#include "Menu.h"

using namespace std;

class Application{
public:
    Application();
    virtual ~Application();
    bool Update();
    void Draw();
    void Input();
private:
	GAME_STATE gs;
	void LoadScreen();
    vector<IGameObject*> screens;
};
#endif