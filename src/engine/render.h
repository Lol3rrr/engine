#ifndef RENDER_H
#define RENDER_H

#include <display_syscalls.h>
#include <display.h>
#include <color.h>

#define DISPLAY_WIDTH 384
#define DISPLAY_HEIGHT 216
#define vram 0xAC000000

#define EMPTY_PIXEL -1
#define WHITE_PIXEL 1
#define BLACK_PIXEL 0


typedef struct sprite {
    int height;
    int width;
    int** data;
} sprite;

void renderPixel(int x, int y, int color);
void renderSprite(int x, int y, sprite* pSprite, int scaleFactor);
void renderCenteredMiniText(int x1, int x2, int pY, unsigned char* text, color_t fore, color_t back);
void renderCenterMiniText(int y, unsigned char* text, color_t fore, color_t back);
void renderMiniText(int x, int y, unsigned char* text, color_t fore, color_t back);


void renderPixel(int x, int y, int color) {
	if (x > DISPLAY_WIDTH || x < 0) {
		return;
	}
	if (y > DISPLAY_HEIGHT || y < 0) {
		return;
	}

	unsigned short* p = (unsigned short*) vram;
	p += (DISPLAY_WIDTH * y) + x;
	*p = color;
}

void renderSprite(int x, int y, sprite* pSprite, int scaleFactor) {
    int iY = 0;
	int tmpY = y;
	while (iY < pSprite->height) {
		int yS = 0;
		while (yS < scaleFactor) {
            int iX = 0;
            int tmpX = x;
            while (iX < pSprite->width) {
                int xS = 0;
                int color = pSprite->data[tmpY][tmpX];
                while (xS < scaleFactor) {
                    if (color != EMPTY_PIXEL) {
                        renderPixel(tmpX, tmpY, color);
                    }

                    tmpX++;
                    xS++;
                }
                
                iX++;
            }

			tmpY++;
			yS++;
		}

		iY++;
	}
}

void renderCenteredMiniText(int x1, int x2, int pY, unsigned char* text, color_t fore, color_t back) {
    int rawCenter = (x2 - x1) / 2 - 1;

	int x = 0;
	int y = 0;
	PrintMini(&x, &y, text, 0, 0xFFFFFFFF, 0, 0, fore, back, 0, 0);

	int center = rawCenter - (x / 2 - 1) + x1;
	y = pY;
	PrintMini(&center, &y, text, 0, 0xFFFFFFFF, 0, 0, fore, back, 1, 0);
}

void renderCenterMiniText(int y, unsigned char* text, color_t fore, color_t back) {
	renderCenteredMiniText(0, DISPLAY_WIDTH, y, text, fore, back);
}

void renderMiniText(int x, int y, unsigned char* text, color_t fore, color_t back) {
    PrintMini(&x, &y, text, 0, 0xFFFFFFFF, 0, 0, fore, back, 1, 0);
}


#endif