#include "cprocessing.h"
#include "splashscreen.h"
#include <stdio.h>
#include <math.h>

int BG_Width, BG_Height, m, printed;
int frame, animationSecs, runtime;
float alpha, TransitionSpeed;
float TotalElapsedTime;

CP_Image BG;

void splash_screen_init(void)
{
	BG = CP_Image_Load("./Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_System_SetWindowSize(CP_Image_GetWidth(BG), CP_Image_GetHeight(BG));

	//transparency value
	runtime = 2;

}
void splash_screen_update(void)
{
	//Flutter
	int currentFps = CP_System_GetFrameRate();
	int currentFrameCount = CP_System_GetFrameCount();
	int fps_cycle = (int)CP_System_GetFrameRate() * runtime;
	int kek = currentFrameCount % fps_cycle;
	int TimeTakenSec = (int) floor(TotalElapsedTime) % runtime;
	
	//Impt codes
	//Fade in
	//tl:dr math =
	//Get perc of (time taken from last to current frame) from (Specified Runtime)
	//Use perc to get alpha's perc equivalent => use this as transition speed to next frame
	//Rinse and repeat.
	CP_Graphics_ClearBackground(CP_Color_Create(10,10,10,255));
	TotalElapsedTime += CP_System_GetDt();
	alpha += (CP_System_GetDt() / runtime) * 255;
	//Resets img alpha value to 0 after max value of 255
	m = (int) alpha % 255;
	CP_Image_Draw(BG, 10.f, 10.f,CP_System_GetWindowWidth(), CP_System_GetWindowHeight(), m);
	
	//Fade in AND Fade out
	//tl:dr math = 
	int transparency = runtime * sin(TotalElapsedTime);



	cursor();

	if (CP_Input_KeyDown(KEY_SPACE))
	{
		CP_Engine_Terminate();
	}
}

void splash_screen_exit(void)
{
	CP_Image_Free(&BG);
}


void cursor(void) {

	CP_Color red = CP_Color_Create(255, 0, 0, 255);
	CP_Settings_Fill(red);

	CP_Graphics_DrawCircle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 20.f);
}