#ifndef _FONTMANAGER_H
#define _FONTMANAGER_H

#include <kos.h>
#include <dcplib/fnt.h>

enum FONTS{
	DEFAULT
};

struct FontMemory{
    fntTexFont* fntPtr;
    pvr_ptr_t memPtr;
};

class FontManager{
public:
	FontMemory getFont(FONTS);
	void releaseFont(FONTS);
    static FontManager* getInstance();
    static void clear();
private:
	FontManager();
	~FontManager();
	static FontManager* _instance;
    FontMemory font[DEFAULT+1];
};

#endif