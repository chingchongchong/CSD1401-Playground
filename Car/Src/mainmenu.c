#include "cprocessing.h"
#include "carlevel.h"
#include "utils.h"
#include <stdio.h>

int swidth, sheight;
int rect1x, rect1y, rect1w, rect1h;
int rect2x, rect2y, rect2w, rect2h;
CP_Color red;

void Main_Menu_Init()
{
	swidth = 800;
	sheight = 600;
	CP_System_SetWindowSize(swidth, sheight);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	//CP_Settings_ImageWrapMode(CP_POSITION_CORNER);
}


void Main_Menu_Update()
{

	int rectW = 100, rectH = 50, rectWOff = rectW / 2, rectHOff = rectH / 2;
	//Y ++ = down
	//X ++ = right
	CP_Settings_Save();
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 255));
	CP_Settings_StrokeWeight(1.0f);
	CP_Graphics_DrawLine(0, sheight / 2, swidth, sheight / 2);
	for (int i = 0; i <= 20; i++) {
		CP_Graphics_DrawLine(swidth / 2 - rectWOff + i*5 , 0, swidth / 2 - rectWOff + i*5, sheight);
	}

	int centeroffset = 100;
	//CP_Settings_StrokeWeight(1.0f);
	CP_Settings_Restore();
	CP_Settings_Fill(CP_Color_Create(255, 100, 100, 255));
	
	rect1w = rect2w = rectW;
	rect1h = rect2h = rectH;

	rect1x = rect2x = swidth / 2;
	rect1y = sheight / 2;
	CP_Graphics_DrawRect(rect1x,rect1y, rect1w, rect1h);
	rect2y = sheight / 2 + centeroffset;
	CP_Graphics_DrawRect(rect2x,rect2y, rect1w, rect2h);
	
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("Start", swidth / 2 -rectWOff/3.5, sheight / 2 + 4);
	CP_Font_DrawText("End", swidth/2 - rectWOff/4,sheight/2 + centeroffset + 4);
	
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) {
		if (IsAreaClicked(rect1x, rect1y, rect1w, rect1h, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 0) {
			CP_Engine_SetNextGameState(Car_Level_Init, Car_Level_Update, Car_Leve_Exit);
			printf("Legoo Car\n");
		}
	}

	
	if (CP_Input_KeyDown(KEY_C)) {
		CP_Engine_SetNextGameState(Car_Level_Init, Car_Level_Update, Car_Leve_Exit);
		printf("Legoo Car\n");
		//CP_Engine_Run();
	}
	if (CP_Input_KeyDown(KEY_K)) {
		CP_Engine_Terminate();
	}
}

void Main_Menu_Exit()
{
	
}