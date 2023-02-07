#include<malloc.h>
#include<stdio.h>
#include<time.h>

typedef struct FPSData
{
    clock_t fpsCurTime, fpsOldTime;
    int frameCnt;
    char* fpsTextBuffer;
}FPSData;


void InitFPSData(FPSData** fpsData);

void DrawFPS(FPSData** fpsData);

void DestoyFPSData(FPSData** fpsData);