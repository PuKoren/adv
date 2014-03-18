#include "FontManager.h"

FontManager* FontManager::_instance = NULL;

FontManager::FontManager(){
	int i = 0;
	for(i = 0; i <= DEFAULT; i++){
		font[i] = NULL;
	}
}

FontManager::~FontManager(){
	int i = 0;
	for(i = 0; i < DEFAULT; i++){
		delete font[i];
	}
}

FontManager* FontManager::getInstance(){
	if(_instance){
		return _instance;
	}
	else{
		_instance = new FontManager();
		return _instance;
	}
}

fntTexFont* FontManager::getFont(FONTS i){
	if(font[i] == NULL){
		char tmpbuf[256];
		sprintf(tmpbuf, "/rd/fonts/%d.txf", i);
		font[i] = new fntTexFont(tmpbuf);
	}
	return font[i];
}

void FontManager::releaseFont(FONTS i){
	delete font[i];
	font[i] = NULL;
}

void FontManager::clear(){
	delete _instance;
}