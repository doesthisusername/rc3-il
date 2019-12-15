#include "../npea00387.h"

// binds
#define BTN_ACTION (BTN_L2 | BTN_R2)
#define BTN_ALT BTN_L3

#define BTN_RELOAD BTN_R3
#define BTN_SAVE BTN_L1
#define BTN_LOAD BTN_R1

// variables
#define i (*((int*)0xD9FEFC))
#define save_pos ((void*)0xD9FF00)
#define save_save ((void*)0x1100000)

void entry() {
    if((down_buttons & BTN_ACTION) == BTN_ACTION) {
        // reload planet
        if((pressed_buttons & BTN_RELOAD) == BTN_RELOAD) {
            // reload save
            if((down_buttons & BTN_ALT) == BTN_ALT) {
                if((down_buttons & BTN_UP) || *(int*)save_save == 0) {
                    // prevent stack overflow from giga memcpy
                    for(i = 0; i < 0x200000; i += 0x8000) {
                        memcpy((void*)((int)save_save + i), (void*)((int)savedata_buf + i), 0x8000);
                    }
                }

                perform_load(0, save_save);
            }
            // just reload planet
            else {
                destination_planet = current_planet;
                should_load = 1;
            }
        }
        // save pos
        else if((pressed_buttons & BTN_SAVE) == BTN_SAVE) {
            memcpy(save_pos, &player_pos, 0x20);
        }
        // load pos
        else if((pressed_buttons & BTN_LOAD) == BTN_LOAD) {
            memcpy(&player_pos, save_pos, 0x20);
        }
    }
}