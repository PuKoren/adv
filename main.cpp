#include <kos.h>
#include "Application.h"

extern uint8 romdisk_boot[];

KOS_INIT_FLAGS(INIT_DEFAULT | INIT_MALLOCSTATS);
KOS_INIT_ROMDISK(romdisk_boot);

int main(){
    Application a;
    while(a.Update()){
        a.Draw();
    }
    return 0;
};