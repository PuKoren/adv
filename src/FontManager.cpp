#include "FontManager.h"

FontManager* FontManager::_instance = NULL;

FontManager::FontManager(){
	int i = 0;
	for(i = 0; i <= DEFAULT; i++){
		font[i].fntPtr = NULL;
	}
}

FontManager::~FontManager(){
	int i = 0;
	for(i = 0; i < DEFAULT; i++){
		pvr_mem_free(font[i].memPtr);
		delete font[i].fntPtr;
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

FontMemory FontManager::getFont(FONTS i){
	if(font[i].fntPtr == NULL){
		char tmpbuf[256];
		sprintf(tmpbuf, "/rd/fonts/%i.txf", i);
		FontMemory fmem;
		fmem.memPtr = pvr_mem_malloc(512 * 512 * 2);
		fmem.fntPtr = new fntTexFont(tmpbuf);
		font[i] = fmem;
	}
	return font[i];
}

void FontManager::releaseFont(FONTS i){
	delete font[i].fntPtr;
	pvr_mem_free(font[i].memPtr);
	font[i].fntPtr = NULL;
}

void FontManager::clear(){
	delete _instance;
}