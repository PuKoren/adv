#include "Menu.h"

Menu::Menu(){
	bg = Texture(Vector3(0.f, -(640.f-512.f)/2), 
        	Vector3(512, 512), 
        	Vector3(640, 640), "/rd/wombat.png");
}

Menu::~Menu(){

}

void Menu::Input(GAME_STATE *gs){

}

void Menu::Update(GAME_STATE *gs){

}

void Menu::Draw(){
	bg.Draw();
}