#include "Application.h"

Application::Application(){
    pvr_init_defaults();
    pvr_set_bg_color(1.f, 1.f, 1.f);
    gs = SPLASHSCREEN;
    screens.reserve(QUIT);
    this->LoadScreen();
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
    }else{
        screens[gs]->Input(&gs);
    }
}

void Application::LoadScreen(){
    if(gs == SPLASHSCREEN){
        screens[gs] = new SplashScreen();
    }else if(gs == MENU){
        screens[gs] = new Menu();
    }else if(gs == INGAME){
        //screens[gs] = new Game();
    }
}

void Application::Update(){
    this->Input();
    GAME_STATE old_gs = gs;
    screens[gs]->Update(&gs);
    if(old_gs != gs){
        delete screens[old_gs];
        this->LoadScreen();
    }
}

void Application::Draw(){
    pvr_wait_ready();
    pvr_scene_begin();
        pvr_list_begin(PVR_LIST_TR_POLY);
            screens[gs]->Draw();
        pvr_list_finish();
    pvr_scene_finish();
}
