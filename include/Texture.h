#ifndef _TEXTURE_H
#define _TEXTURE_H
#include <png/png.h>
#include <zlib/zlib.h>

class Texture {
public:
    Texture();
    Texture(int width, int height);
    ~Texture();
    void Draw();
private:
    pvr_ptr_t obj_texture;
};
#endif