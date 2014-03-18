#ifndef _FONTMANAGER_H
#define _FONTMANAGER_H

#include <kos.h>
#include <dcplib/fnt.h>

enum FONTS{
	DEFAULT
};

class FontManager{
public:
	fntTexFont* getFont(FONTS);
	void releaseFont(FONTS);
    static FontManager* getInstance();
    static void clear();
private:
	FontManager();
	~FontManager();
	static FontManager* _instance;
    fntTexFont* font[DEFAULT+1];
};

#endif