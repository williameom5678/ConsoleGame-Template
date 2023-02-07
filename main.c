#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>

#include "screen.h"
#include "fps.h"
#include "settings.h"

#include "player.h"

FPSData* fpsData;

void init() {
	InitFPSData(&fpsData);

	g_Player.position.y = 22;
	g_Player.position.x = 0;

	g_Player.nLength = strlen(PLAYER_STR);

	g_Player.strPlayer = (char*)malloc(sizeof(char) * g_Player.nLength);
	strcpy(g_Player.strPlayer, PLAYER_STR);
}

void update() {}

void render() {
	ScreenClear();
	DrawFPS(&fpsData);
	// ae

	char string[100] = { 0, };

	ScreenPrint(g_Player.position.x, g_Player.position.y, g_Player.strPlayer);

	sprintf(string, "주인공 이동좌표 : %d, %d", g_Player.position.x, g_Player.position.y);
	ScreenPrint(0, 3, string);

	// ae
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
	int remain;
	switch (key) {
	case 'a':
		//break;
		g_Player.position.x--;
	case 'd':
		//break;
		g_Player.position.x++;
	case 'w':
		g_Player.position.y--;
	case 's':
		g_Player.position.y++;
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

		//renderDelay(clock());

	}

	release();
	ScreenRelease();
	return 0;
}
