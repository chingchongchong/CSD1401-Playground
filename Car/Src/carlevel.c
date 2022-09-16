#include "cprocessing.h"
#include "mainmenu.h"
#include <stdio.h>
void Car_Level_Init()
{
	printf("Im in car\n");
}

void Car_Level_Update()
{

	CP_Color idk = CP_Color_Create(0, 100, 255, 255);
	CP_Graphics_ClearBackground(idk);
	if (CP_Input_KeyDown(KEY_M)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		printf("Bye bye car\n");
	}

}

void Car_Leve_Exit()
{

}