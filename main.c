#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>

#include "screen.h"
#include "fps.h"
#include "settings.h"

FPSData* fpsData;

void init() {
	InitFPSData(&fpsData);
}

void update() {}

void render() {
	ScreenClear();
	
	DrawFPS(&fpsData);

	ScreenFlipping();
}

void release() {
	DestoyFPSData(&fpsData);
}

int getKeyEvent() {
	if (_kbhit()) { return _getch(); }
	return -1;
}

void keyProcess(int key) {
	switch (key) {
	case 'i':
		break;
	case 'j':
		break;
	}
}

void renderDelay(clock_t WasTime) {
	clock_t CurTime;
	while(1) {
		CurTime = clock();
		if (CurTime - WasTime > _FR) {
			break;
		}
	}
}

int main(void) {
	
	ScreenInit();
	init();

	for (;;) {
		int nKey = getKeyEvent();
		if (nKey == 'q') { break; }
		keyProcess(nKey);

		update();

		render();

		renderDelay(clock());

	}

	release();
	ScreenRelease();
	return 0;
}
