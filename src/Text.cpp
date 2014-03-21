#include "Text.h"

Text::Text(){
    fRenderer = NULL;
}

Text::Text(const char* txt, int size, fntTexFont* font){
    /*fRenderer = new fntRenderer();
    fRenderer->setFilterMode(0);
    fRenderer->setFont(font);
    fRenderer->setPointSize(size);
    text = std::string(txt);*/
}

Text::~Text(){
	delete fRenderer;
}

void Text::Draw(){
    /*fRenderer->begin();
    fRenderer->setColor(1, 1, 1);
    fRenderer->start2f(20, 50);
    fRenderer->puts(text.c_str());
    fRenderer->end();*/
}

void Text::Input(GAME_STATE *gs, cont_state_t *state){

}

void Text::Update(GAME_STATE *gs){

}
