#include "Texture.h"

Texture::Texture(){
    
};

Texture::Texture(Vector3 pos, Vector3 size){
    this->loc = Vector3(pos);
    this->dim = Vector3(size);
    this->LoadTexture();
};

Texture::~Texture(){

};

void Texture::LoadTexture(){
    obj_texture = pvr_mem_malloc(this->dim.X * this->dim.Y * 2);
    png_to_texture("/rd/img.png", obj_texture, PNG_NO_ALPHA);
};

void Texture::Draw(){
    pvr_poly_cxt_t cxt;
    pvr_poly_hdr_t hdr;
    pvr_vertex_t vert;

    pvr_poly_cxt_txr(&cxt, PVR_LIST_OP_POLY, PVR_TXRFMT_RGB565, this->dim.X, this->dim.Y, obj_texture, PVR_FILTER_BILINEAR);
    pvr_poly_compile(&hdr, &cxt);
    pvr_prim(&hdr, sizeof(hdr));

    vert.argb = PVR_PACK_COLOR(1.0f, 1.0f, 1.0f, 1.0f);
    vert.oargb = 0;
    vert.flags = PVR_CMD_VERTEX;

    //UV MAPPING
    //upper left corner
    vert.x = this->loc.X;
    vert.y = this->loc.X;
    vert.z = 1;
    vert.u = 0.0;
    vert.v = 0.0;
    pvr_prim(&vert, sizeof(vert));

    //upper right corner
    vert.x = this->loc.X + this->dim.X;
    vert.y = this->loc.Y;
    vert.z = 1;
    vert.u = 1.0;
    vert.v = 0.0;
    pvr_prim(&vert, sizeof(vert));

    //bottom left corner
    vert.x = this->loc.X;
    vert.y = this->loc.Y + this->dim.Y;
    vert.z = 1;
    vert.u = 0.0;
    vert.v = 1.0;
    pvr_prim(&vert, sizeof(vert));

    //bottom right corner
    vert.x = this->loc.X + this->dim.X;
    vert.y = this->loc.Y + this->dim.Y;
    vert.z = 1;
    vert.u = 1.0;
    vert.v = 1.0;
    vert.flags = PVR_CMD_VERTEX_EOL;
    pvr_prim(&vert, sizeof(vert));
};