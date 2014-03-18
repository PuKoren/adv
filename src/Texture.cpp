#include "Texture.h"

Texture::Texture(){
    this->obj_texture = NULL;
};

Texture::Texture(Vector3 pos, Vector3 size, Vector3 screen_size, const char* location){
    this->loc = pos;
    this->dim = size;
    this->screen_size = screen_size;
    this->alpha = 1.f;
    this->angle = 0.f;
    this->LoadTexture(location);
};

Texture::Texture(Vector3 pos, Vector3 size, const char* location){
    this->loc = pos;
    this->dim = size;
    this->screen_size = size;
    this->alpha = 1.f;
    this->angle = 0.f;
    this->LoadTexture(location);
};

Texture::Texture(Vector3 pos, Vector3 size, Vector3 screen_size, Texture* tex){
    this->loc = pos;
    this->dim = size;
    this->screen_size = screen_size;
    this->obj_texture = tex->obj_texture;
    this->alpha = 1.f;
    this->angle = 0.f;
};

Texture::Texture(Vector3 pos, Vector3 size, Texture* tex){
    this->loc = pos;
    this->dim = size;
    this->screen_size = size;
    this->obj_texture = tex->obj_texture;
    this->alpha = 1.f;
    this->angle = 0.f;
};

Texture::~Texture(){
    pvr_mem_free(obj_texture);
};

void Texture::SetAlpha(float a){
    this->alpha = a;
};

void Texture::SetRotation(float angle){
    this->angle = angle;
};

void Texture::Rotate(float angle){
    this->angle += angle;

    rot[0] = GetRotation(Vector3(this->loc.X, this->loc.Y));
    rot[1] = GetRotation(Vector3(this->loc.X + this->screen_size.X, this->loc.Y));
    rot[2] = GetRotation(Vector3(this->loc.X, this->loc.Y + this->screen_size.Y));
    rot[3] = GetRotation(Vector3(this->loc.X + this->screen_size.X, this->loc.Y + this->screen_size.Y));
};

void Texture::Move(float x, float y){
    this->loc.X += x;
    this->loc.Y += y;
};

void Texture::LoadTexture(const char* location){
    obj_texture = pvr_mem_malloc(this->dim.X * this->dim.Y * 2);
    png_to_texture(location, obj_texture, PNG_FULL_ALPHA);

    pvr_poly_cxt_t cxt;
    //if there is no opacity on the image, use PVR_TXRFMT_RGB565
    pvr_poly_cxt_txr(&cxt, PVR_LIST_TR_POLY, PVR_TXRFMT_ARGB4444, this->dim.X, this->dim.Y, obj_texture, PVR_FILTER_BILINEAR);
    pvr_poly_compile(&hdr, &cxt);

    rot[0] = GetRotation(Vector3(this->loc.X, this->loc.Y));
    rot[1] = GetRotation(Vector3(this->loc.X + this->screen_size.X, this->loc.Y));
    rot[2] = GetRotation(Vector3(this->loc.X, this->loc.Y + this->screen_size.Y));
    rot[3] = GetRotation(Vector3(this->loc.X + this->screen_size.X, this->loc.Y + this->screen_size.Y));
};

void Texture::Draw(){
    pvr_vertex_t vert;
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

    vert.x = rot[0].X;
    vert.y = rot[0].Y;
    pvr_prim(&vert, sizeof(vert));

    //upper right corner
    vert.x = this->loc.X + this->screen_size.X;
    vert.y = this->loc.Y;
    vert.z = 1;
    vert.u = 1.0;
    vert.v = 0.0;
    
    vert.x = rot[1].X;
    vert.y = rot[1].Y;
    pvr_prim(&vert, sizeof(vert));

    //bottom left corner
    vert.x = this->loc.X;
    vert.y = this->loc.Y + this->screen_size.Y;
    vert.z = 1;
    vert.u = 0.0;
    vert.v = 1.0;

    vert.x = rot[2].X;
    vert.y = rot[2].Y;
    pvr_prim(&vert, sizeof(vert));

    //bottom right corner
    vert.x = this->loc.X + this->screen_size.X;
    vert.y = this->loc.Y + this->screen_size.Y;
    vert.z = 1;
    vert.u = 1.0;
    vert.v = 1.0;
    vert.flags = PVR_CMD_VERTEX_EOL;

    vert.x = rot[3].X;
    vert.y = rot[3].Y;
    pvr_prim(&vert, sizeof(vert));
};

Vector3 Texture::GetRotation(Vector3 point){
    float s = sin(angle);
    float c = cos(angle);

    Vector3 centerPoint((loc.X + screen_size.X)/2, 
        (loc.Y + screen_size.Y)/2);
    Vector3 returnPoint;
    // translate point back to origin:
    point.X -= centerPoint.X;
    point.Y -= centerPoint.Y;

    // rotate point
    float xnew = point.X * c - point.Y * s;
    float ynew = point.X * s + point.Y * c;

    // translate point back:
    point.X = xnew + centerPoint.X;
    point.Y = ynew + centerPoint.Y;
    return point;
};