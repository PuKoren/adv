#include "Application.h"

Application::Application(){
    pvr_init_defaults();
    tex = Texture(Vector3(0.f, 0.f), Vector3(128.f,128.f));
}

Application::~Application(){

}

void Application::Update(){
    tex.Move(1, 0);
}

void Application::Draw(){
    pvr_wait_ready();
    pvr_scene_begin();
        pvr_list_begin(PVR_LIST_TR_POLY);
            tex.Draw();
        pvr_list_finish();
    pvr_scene_finish();
}