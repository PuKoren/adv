#ifndef _TEXTURE_H
#define _TEXTURE_H
#include <png/png.h>
#include <zlib/zlib.h>
#include "Vector3.h"

class Texture {
public:
    Texture();
    Texture(Vector3 pos, Vector3 size, const char* location);
    Texture(Vector3 pos, Vector3 size, Vector3 screen_size, const char* location);
    Texture(Vector3 pos, Vector3 size, Texture* tex);
    Texture(Vector3 pos, Vector3 size, Vector3 screen_size, Texture* tex);
    ~Texture();
    void Draw();
    void Move(float x, float y);
private:
    void LoadTexture(const char* location);
    pvr_ptr_t obj_texture;
    Vector3 loc;
    Vector3 dim;
    Vector3 screen_size;
};
#endif