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

	g_Player.center.x = 4;
	g_Player.center.y = 0;

	g_Player.position.y = 22;
	g_Player.position.x = 0;

	g_Player.nLength = strlen(PLAYER_STR);

	g_Player.strPlayer = (char*)malloc(sizeof(char) * g_Player.nLength);
	strcpy(g_Player.strPlayer, PLAYER_STR);

	g_Ball.isReady = 1;
	g_Ball.position.x = g_Player.position.x;
	g_Ball.position.y = g_Player.position.y - 1;
	g_Ball.moveTime = 100;
}

void update() {
	clock_t CurTime = clock();
	if (g_Ball.isReady == 0) {
		if ((CurTime - g_Ball.oldTime) > g_Ball.moveTime) {
			if (g_Ball.position.y > 0) {
				g_Ball.position.y--;
				g_Ball.oldTime = CurTime;
			} else {
				g_Ball.isReady = 1;
				g_Ball.position.x = g_Player.position.x;
				g_Ball.position.y = g_Player.position.y - 1;
			}
		}
	}
}

void render() {
	ScreenClear();
	DrawFPS(&fpsData);
	// ae

	char string[100] = { 0, };

	int printX = g_Player.position.x - g_Player.center.x;
	//ScreenPrint(printX, g_Player.position.y, g_Player.strPlayer);

	if (printX < 0) {
		ScreenPrint(0, g_Player.position.y, &g_Player.strPlayer[printX * -1]);
	} else if (g_Player.position.x + g_Player.center.x + 1 > 40) {
		strncat(string, g_Player.strPlayer, g_Player.nLength - ((g_Player.position.x + g_Player.center.x + 1) - 40));
		ScreenPrint(printX, g_Player.position.y, string);
	} else {
		ScreenPrint(printX, g_Player.position.y, g_Player.strPlayer);
	}

	//ScreenPrint(g_Player.position.x, g_Player.position.y, g_Player.strPlayer);

	ScreenPrint(g_Ball.position.x, g_Ball.position.y, "◎");

	sprintf(string, "주인공 이동좌표 : %d, %d", g_Player.position.x, g_Player.position.y);
	ScreenPrint(0, 3, string);

	// ae
	//ScreenClear();
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
	case 'j':
		g_Player.position.x--;
		if (g_Player.position.x - g_Player.center.x < 0 || g_Player.position.x + (g_Player.center.x * 2) + 1 >40) {
			g_Player.position.x--;
		}
		break;
	case 'l':
		g_Player.position.x++;
		if (g_Player.position.x + (g_Player.center.x * 2) + 1 > 40 || g_Player.position.x - g_Player.center.x < 0) {
			g_Player.position.x++;
		}
		break;
	case'k':
		if (g_Ball.isReady)
		{
			g_Ball.position.x = g_Player.position.x;
			g_Ball.position.y = g_Player.position.y - 1;
			g_Ball.oldTime = clock();
			g_Ball.isReady = 0;
		}
		break;
	}
	if (g_Ball.isReady) {
		g_Ball.position.x = g_Player.position.x;
		g_Ball.position.y = g_Player.position.y - 1;
	}
}

void renderDelay(clock_t WasTime) {
	clock_t CurTime;
	for (;;) {
		CurTime = clock();
		if (CurTime - WasTime > _FR)
			break;
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
