#include "engine/input.h"
#include "engine/render.h"
#include "engine/collision.h"
#include "engine/utils.h"


#include <display_syscalls.h>
#include <keyboard_syscalls.h>


int main(void) {
	int key;
     
	while (1) {
        Bdisp_AllClr_VRAM();
        GetKey(&key);
		switch (key) {
		}
	}
 
	return 0;
}