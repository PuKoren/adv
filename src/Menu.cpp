#include "Menu.h"

Menu::Menu(){
	bg = Texture(Vector3(0.f, 0.f), 
        	Vector3(1024, 1024), 
        	Vector3(640, 480), "/rd/menu_bg.png");
}

Menu::~Menu(){

}

void Menu::Input(GAME_STATE *gs, cont_state_t *state){
    if(state->buttons & CONT_START){
        *gs = QUIT;
    }
}

void Menu::Update(GAME_STATE *gs){
    bg.Rotate(0.01f);
}

void Menu::Draw(){
	bg.Draw();
}