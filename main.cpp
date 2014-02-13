#include <kos.h>
#include "Application.h"

extern uint8 romdisk_boot[];

KOS_INIT_FLAGS(INIT_DEFAULT);
KOS_INIT_ROMDISK(romdisk_boot);

int main(){
    Application a;
    bool running = true;
    while(running){
        a.Update();
        a.Draw();
    }
    return 0;
};