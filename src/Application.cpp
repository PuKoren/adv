#include "Application.h"

Application::Application(){
    pvr_init_defaults();
    tex = NULL;
    tex = new Texture(128, 128);
}

Application::~Application(){
    delete tex;
}

void Application::Update(){
    
}

void Application::Draw(){
    pvr_wait_ready();
    pvr_scene_begin();
        pvr_list_begin(PVR_LIST_OP_POLY);
            tex->Draw();
        pvr_list_finish();
    pvr_scene_finish();
}