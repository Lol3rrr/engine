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

		renderPixel(10, 10, C_BLACK);
		renderPixel(11, 10, C_BLACK);
		renderPixel(10, 11, C_BLACK);
		renderPixel(11, 11, C_BLACK);

		renderPixel(20, 10, C_WHITE);
		renderPixel(21, 10, C_WHITE);
		renderPixel(20, 11, C_WHITE);
		renderPixel(21, 11, C_WHITE);

		renderPixel(30, 10, C_RED);
		renderPixel(31, 10, C_RED);
		renderPixel(30, 11, C_RED);
		renderPixel(31, 11, C_RED);

		renderPixel(40, 10, C_GREEN);
		renderPixel(41, 10, C_GREEN);
		renderPixel(40, 11, C_GREEN);
		renderPixel(41, 11, C_GREEN);

		renderPixel(50, 10, C_BLUE);
		renderPixel(51, 10, C_BLUE);
		renderPixel(50, 11, C_BLUE);
		renderPixel(51, 11, C_BLUE);

    GetKey(&key);
		switch (key) {
		}
	}

	return 0;
}
