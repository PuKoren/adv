#include "SplashScreen.h"

SplashScreen::SplashScreen(){
	alpha = 0.0f;
	fadeRate = 0.005f;
	bg = Texture(Vector3(0.f, (512.f - 640.f)/2), 
        	Vector3(512, 512), 
        	Vector3(640, 640), "/rd/pukogames.png");
	bg.SetAlpha(alpha);
}

SplashScreen::~SplashScreen(){

}

void SplashScreen::Input(GAME_STATE *gs){

}

void SplashScreen::Update(GAME_STATE *gs){
	alpha += fadeRate;
	if(alpha >= 1.f){
		alpha = 1.f;
		fadeRate = -fadeRate;
	}
	if(fadeRate < 0.f && alpha <= 0.f){
		alpha = 0.f;
		*gs = MENU;
	}
	bg.SetAlpha(alpha);
}

void SplashScreen::Draw(){
	bg.Draw();
}