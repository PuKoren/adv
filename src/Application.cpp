#include "Application.h"

Application::Application(){
    pvr_init_defaults();
    tex = Texture(Vector3(0.f, 0.f), Vector3(128.f,128.f));
}

Application::~Application(){

}

void Application::Update(){
    
}

void Application::Draw(){
    pvr_wait_ready();
    pvr_scene_begin();
        pvr_list_begin(PVR_LIST_OP_POLY);
            tex.Draw();
        pvr_list_finish();
    pvr_scene_finish();
}