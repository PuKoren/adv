#include "Text.h"

Text::Text(const char* text, int size, fntTexFont* font){
    fRenderer = new fntRenderer();
    fRenderer->setFilterMode(0);
    fRenderer->setFont(font);
    fRenderer->setPointSize(30);
}

Text::~Text(){
	delete fRenderer;
}

void Text::Draw(){
    fRenderer->begin();
    //text->setColor(1, 1, 1);
    //text->start2f(20, y);
    //text->puts(tmpbuf);
    fRenderer->end();
}
