#include "Texture.h"

Texture::Texture(){
    
};

Texture::Texture(Vector3 pos, Vector3 size, Vector3 screen_size, const char* location){
    this->loc = pos;
    this->dim = size;
    this->screen_size = screen_size;
    this->alpha = 1.f;
    this->LoadTexture(location);
};

Texture::Texture(Vector3 pos, Vector3 size, const char* location){
    this->loc = pos;
    this->dim = size;
    this->screen_size = size;
    this->alpha = 1.f;
    this->LoadTexture(location);
};

Texture::Texture(Vector3 pos, Vector3 size, Vector3 screen_size, Texture* tex){
    this->loc = pos;
    this->dim = size;
    this->screen_size = screen_size;
    this->obj_texture = tex->obj_texture;
    this->alpha = 1.f;
};

Texture::Texture(Vector3 pos, Vector3 size, Texture* tex){
    this->loc = pos;
    this->dim = size;
    this->screen_size = size;
    this->obj_texture = tex->obj_texture;
    this->alpha = 1.f;
};

Texture::~Texture(){
    pvr_mem_free(obj_texture);
};

void Texture::SetAlpha(float a){
    this->alpha = a;
};

void Texture::Move(float x, float y){
    this->loc.X += x;
    this->loc.Y += y;
};

void Texture::LoadTexture(const char* location){
    obj_texture = pvr_mem_malloc(this->dim.X * this->dim.Y * 2);
    png_to_texture(location, obj_texture, PNG_FULL_ALPHA);
};

void Texture::Draw(){
    pvr_poly_cxt_t cxt;
    pvr_poly_hdr_t hdr;
    pvr_vertex_t vert;

    //if there is no opacity on the image, use PVR_TXRFMT_RGB565
    pvr_poly_cxt_txr(&cxt, PVR_LIST_TR_POLY, PVR_TXRFMT_ARGB4444, this->dim.X, this->dim.Y, obj_texture, PVR_FILTER_BILINEAR);
    pvr_poly_compile(&hdr, &cxt);
    pvr_prim(&hdr, sizeof(hdr));

    vert.argb = PVR_PACK_COLOR(this->alpha, 1.0f, 1.0f, 1.0f);
    vert.oargb = 0;
    vert.flags = PVR_CMD_VERTEX;

    //UV MAPPING
    //upper left corner
    vert.x = this->loc.X;
    vert.y = this->loc.Y;
    vert.z = 1;
    vert.u = 0.0;
    vert.v = 0.0;
    pvr_prim(&vert, sizeof(vert));

    //upper right corner
    vert.x = this->loc.X + this->screen_size.X;
    vert.y = this->loc.Y;
    vert.z = 1;
    vert.u = 1.0;
    vert.v = 0.0;
    pvr_prim(&vert, sizeof(vert));

    //bottom left corner
    vert.x = this->loc.X;
    vert.y = this->loc.Y + this->screen_size.Y;
    vert.z = 1;
    vert.u = 0.0;
    vert.v = 1.0;
    pvr_prim(&vert, sizeof(vert));

    //bottom right corner
    vert.x = this->loc.X + this->screen_size.X;
    vert.y = this->loc.Y + this->screen_size.Y;
    vert.z = 1;
    vert.u = 1.0;
    vert.v = 1.0;
    vert.flags = PVR_CMD_VERTEX_EOL;
    pvr_prim(&vert, sizeof(vert));
};