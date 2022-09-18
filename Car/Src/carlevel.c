#include "cprocessing.h"
#include "mainmenu.h"
#include <utils.h>
#include <stdio.h>


int cRad = 50, lineGap = 10, a = 255, currentCar;
//init starting x,y for all three circle /cars
int swidth, sheight;
Car one, two, three;
Circle Cars[3];
CP_Color onec, twoc, threec;

void Car_Level_Init()
{
	printf("Im in car\n");
	swidth = CP_System_GetWindowWidth();
	sheight = CP_System_GetWindowHeight();
	
	//Init car structs
	onec = CP_Color_Create(200, 0, 0, a);
	twoc = CP_Color_Create(0, 200, 0, a);
	threec = CP_Color_Create(0, 0, 200, a);
	CP_Settings_EllipseMode(CP_POSITION_CENTER);
	
	one = CreateCar((Circle) {cRad, swidth/2, sheight/2}, "Up");
	//Cars[0] = one;
	//Cars[1] = two;
	//Cars[2] = three;
}

void Car_Level_Update()
{

	CP_Graphics_ClearBackground(CP_Color_Create(150, 150, 150, 255));
	
	//Unecessary #Start
	CP_Settings_Save();
	CP_Settings_StrokeWeight(1.0f);
	for (int i = 0; i <= swidth / lineGap; i++) {
		//Draw X lines
		CP_Graphics_DrawLine(i*lineGap, 0 , i*lineGap, sheight);
	}
	for (int i = 0; i <= sheight / lineGap; i++) {
		//Draw Y lines
		CP_Graphics_DrawLine(0, i*lineGap, swidth, i*lineGap);
	}
	//Unecessary #End
	
	//Circle default origin = center;
	CP_Settings_StrokeWeight(2.0f);
	CP_Settings_Fill(onec);
	if (CP_Input_KeyDown(KEY_D)) {
		one.triangle.rot += 0.1;
		UpdateCarRotation(&one);
	}
	else if (CP_Input_KeyDown(KEY_A)) {
		one.triangle.rot -= 0.1;
		UpdateCarRotation(&one);
	}
	DrawCar(&one);
	//CP_Graphics_DrawCircle(one.coor.x, one.coor.y, one.rad);
	//CP_Settings_Fill(twoc);
	//CP_Graphics_DrawCircle(two.coor.x, two.coor.y, two.rad);
	//CP_Settings_Fill(threec);
	//CP_Graphics_DrawCircle(three.coor.x, three.coor.y, three.rad);


	if (CP_Input_KeyDown(KEY_M)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		printf("Bye bye car\n");
	}

}

void Car_Leve_Exit()
{

}

