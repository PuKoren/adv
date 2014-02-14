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
    ~Application();
    bool Update();
    void Draw();
private:
    void Input();
    void LoadScreen();
	GAME_STATE gs;
    vector<IGameObject*> screens;
};
#endif