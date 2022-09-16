#include "cprocessing.h"
#include "carlevel.h"
#include <stdio.h>

int swidth, sheight;
CP_Color red;

void Main_Menu_Init()
{
	swidth = 800;
	sheight = 500;
	CP_System_SetWindowSize(swidth, sheight);
	//CP_Settings_ImageWrapMode(CP_POSITION_CORNER);
}

void Main_Menu_Update()
{
	red = CP_Color_Create(255, 50, 100, 255);
	CP_Graphics_ClearBackground(red);
	int rectW = 60, rectH = 30;
	int rectWOffset = rectW / 2, rectHOffset = rectH / 2, rectDrawOffset = 100;
	int rectX = swidth / 2 - rectWOffset, rectY = sheight / 2 - rectHOffset;
	CP_Graphics_DrawRect(rectX, rectY, rectW, rectH);
	CP_Graphics_DrawRect(rectX, rectY - rectDrawOffset, rectW, rectH);

	
	CP_Font_DrawText("Hello World", rectX, rectY);
	

	
	if (CP_Input_KeyDown(KEY_M)) {
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