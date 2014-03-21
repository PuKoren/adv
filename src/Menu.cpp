#include "Menu.h"

Menu::Menu(){
	bg = Texture(Vector3(0.f, 0.f), Vector3(512, 512), Vector3(640, 480), "/rd/menu_bg.png");
    txt = Text("Menu", 32, FontManager::getInstance()->getFont(DEFAULT).fntPtr);
}

Menu::~Menu(){

}

void Menu::Input(GAME_STATE *gs, cont_state_t *state){
    if(state->buttons & CONT_START){
        *gs = QUIT;
    }
}

void Menu::Update(GAME_STATE *gs){
}

void Menu::Draw(){
	bg.Draw();
    txt.Draw();
}