#include "Menu.h"

Menu::Menu(){
	bg = Texture(Vector3(0.f, 0.f), Vector3(512, 512), Vector3(640, 480), "/rd/menu_bg.png");
    bg1 = Texture(Vector3(100.f, 100.f), Vector3(512, 512), Vector3(300, 200), bg);
    bg2 = Texture(Vector3(250.f, 0.f), Vector3(512, 512), Vector3(300, 200), bg);
    bg3 = Texture(Vector3(300.f, 250.f), Vector3(512, 512), Vector3(300, 200), bg);
    bg4 = Texture(Vector3(150.f, 75.f), Vector3(512, 512), Vector3(300, 200), bg);
    bg5 = Texture(Vector3(200.f, 50.f), Vector3(512, 512), Vector3(300, 200), bg);
    bg6 = Texture(Vector3(250.f, 120.f), Vector3(512, 512), Vector3(300, 200), bg);
    //txt = Text("Menu", 16, FontManager::getInstance()->getFont(DEFAULT));
}

Menu::~Menu(){

}

void Menu::Input(GAME_STATE *gs, cont_state_t *state){
    if(state->buttons & CONT_START){
        *gs = QUIT;
    }
}

void Menu::Update(GAME_STATE *gs){
    bg1.Rotate(0.001f);
    bg2.Rotate(-0.001f);
    bg3.Rotate(0.002f);
    bg4.Rotate(0.003f);
    bg5.Rotate(-0.002f);
    bg6.Rotate(0.001f);
}

void Menu::Draw(){
	bg.Draw();
    bg1.Draw();
    bg2.Draw();
    bg3.Draw();
    bg4.Draw();
    bg5.Draw();
    bg6.Draw();
    //txt.Draw();
}