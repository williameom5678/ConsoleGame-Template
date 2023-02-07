#define _CRT_SECURE_NO_WARNINGS

#include"fps.h"
#include "screen.h"

void InitFPSData(FPSData** fpsData)
{
    (*fpsData) = (FPSData*)malloc(sizeof(FPSData));
    (*fpsData)->frameCnt = 0;
    (*fpsData)->fpsTextBuffer = (char*)malloc(sizeof(char) * 10);
    sprintf((*fpsData)->fpsTextBuffer, "FPS: %d", (*fpsData)->frameCnt);
    (*fpsData)->fpsOldTime = clock();

}

void DrawFPS(FPSData** fpsData)
{
    //출력코드
    (*fpsData)->frameCnt++;
    (*fpsData)->fpsCurTime = clock();
    if ((*fpsData)->fpsCurTime - (*fpsData)->fpsOldTime >= 1000)
    {
        sprintf((*fpsData)->fpsTextBuffer, "FPS: %d", (*fpsData)->frameCnt);
        (*fpsData)->fpsOldTime = clock();
        (*fpsData)->frameCnt = 0;
    }

    ScreenPrint(0, 0, (*fpsData)->fpsTextBuffer);
}

void DestoyFPSData(FPSData** fpsData)
{
    free((*fpsData)->fpsTextBuffer);
    free(*fpsData);
}

