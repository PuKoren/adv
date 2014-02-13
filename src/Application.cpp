#include "Application.h"

Application::Application(){
    pvr_init_defaults();
    tex = Texture(Vector3(0.f, 0.f), Vector3(128.f,128.f));
}

Application::~Application(){

}

void Application::Input(){
    maple_device_t *cont;
    cont_state_t *state;

    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    if(!cont)
        return;

    state = (cont_state_t *)maple_dev_status(cont);

    if(!state) {
        return;
    }

    if(state->buttons & CONT_DPAD_LEFT) {
        tex.Move(-1, 0);
    }else if(state->buttons & CONT_DPAD_RIGHT) {
        tex.Move(1, 0);
    }
    
    if(state->buttons & CONT_DPAD_UP) {
        tex.Move(0, -1);
    }else if(state->buttons & CONT_DPAD_DOWN) {
        tex.Move(0, 1);
    }
}

void Application::Update(){
    this->Input();
}

void Application::Draw(){
    pvr_wait_ready();
    pvr_scene_begin();
        pvr_list_begin(PVR_LIST_TR_POLY);
            tex.Draw();
        pvr_list_finish();
    pvr_scene_finish();
}