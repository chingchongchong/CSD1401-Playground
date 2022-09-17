#include "cprocessing.h"
#include "splashscreen.h"
#include <stdio.h>
#include <math.h>

int BG_Width, BG_Height, m, M;
int transparency, runtime;
float alpha, periodPerFrame, PI = 22.0/7.0;
float TotalElapsedTime;

CP_Image BG;

void splash_screen_init(void)
{
	BG = CP_Image_Load("./Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_System_SetWindowSize(CP_Image_GetWidth(BG), CP_Image_GetHeight(BG));

	//transparency value
	runtime = 2;
	//Min transparency value
	m = 0;
	//Max transparency value
	M = 255;

}
void splash_screen_update(void)
{
	////Fluff
	//int currentFps = CP_System_GetFrameRate();
	//int currentFrameCount = CP_System_GetFrameCount();
	//int fps_cycle = (int)CP_System_GetFrameRate() * runtime;
	//int kek = currentFrameCount % fps_cycle;
	//int TimeTakenSec = (int) floor(TotalElapsedTime) % runtime;
	
	//Impt codes
	TotalElapsedTime += CP_System_GetDt();
	CP_Graphics_ClearBackground(CP_Color_Create(10,10,10,255));
	//Fade in #1 #Start
	//Get perc of (time taken from last to current frame) from (Specified Runtime)
	//Use perc to get alpha's perc equivalent => use this as transition speed to next frame
	alpha += (CP_System_GetDt() / runtime) * M;
	//Resets img alpha value to 0 after max value of 255
	transparency = (int) alpha % M;
	//Fade in #End
	
	////Fade in #2 #Start
	////Simplify Fade in #1 into one line
	//transparency = (int) ((TotalElapsedTime * M) / runtime ) % M;
	////Fade in #2 #End
	
	
	
	//Fade in AND Fade out
	//using sine wave for oscillating values between 0 - 255
	
	////Using Sine #Start
	//transparency = abs(255 * sinf(TotalElapsedTime * PI/runtime));
	////Using Sine #End
	
	////Using Cosine #Start
	//transparency = abs(M / 2 * cosf(TotalElapsedTime * (2 * PI) / runtime) - M / 2);
	////Using Cosine #End


	////Using Mod #Start
	//transparency = abs(M - ((int)(TotalElapsedTime * M) / runtime % (M * 2)));
	////Using Mod #End

	printf("%f | %d | %f\n", alpha, transparency, TotalElapsedTime);
	

	CP_Image_Draw(BG, 10.f, 10.f,CP_System_GetWindowWidth(), CP_System_GetWindowHeight(), transparency);

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