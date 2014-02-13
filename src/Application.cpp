#include "Application.h"

Application::Application(){
    pvr_init_defaults();
    background = Texture(Vector3(0.f, (512.f - 640.f)/2), Vector3(512, 512), Vector3(640, 640), "/rd/pukogames.png");
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
    }else if(state->buttons & CONT_DPAD_RIGHT) {
    }

    if(state->buttons & CONT_DPAD_UP) {
    }else if(state->buttons & CONT_DPAD_DOWN) {
    }
}

void Application::Update(){
    this->Input();
}

void Application::Draw(){
    pvr_wait_ready();
    pvr_scene_begin();
        pvr_list_begin(PVR_LIST_TR_POLY);
            background.Draw();
        pvr_list_finish();
    pvr_scene_finish();
}