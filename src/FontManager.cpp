#include "FontManager.h"

FontManager* FontManager::_instance = NULL;

FontManager::FontManager(){
	if(_instance == NULL){
		_instance = new FontManager();
		int i = 0;
		for(i = 0; i < DEFAULT; i++){
			_instance->font[i] = NULL;
		}
	}
}

FontManager::~FontManager(){
	int i = 0;
	for(i = 0; i < DEFAULT; i++){
		delete _instance->font[i];
	}
	delete _instance;
}

fntTexFont* FontManager::getFont(FONTS i){
	if(_instance->font[i] == NULL){
		char tmpbuf[256];
		sprintf(tmpbuf, "/rd/fonts/%d.txf", i);
		_instance->font[i] = new fntTexFont(tmpbuf);
	}
	return _instance->font[i];
}

void FontManager::releaseFont(FONTS i){
	delete _instance->font[i];
	_instance->font[i] = NULL;
}