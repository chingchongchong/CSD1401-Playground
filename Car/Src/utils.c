#include "cprocessing.h"

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{
	//return 0 if true, else false;
	int halfWidth = area_width / 2, halfHeight = area_height / 2;
	int xLeftLimit = area_center_x - halfWidth, xRightLimit = area_center_x + halfWidth;
	int yTopLimit = area_center_y - halfHeight, yBtmLimit = area_center_y + halfHeight;

	if (xLeftLimit < click_x && click_x < xRightLimit && yTopLimit < click_y && click_y < yBtmLimit ) {
		return 0;
	}
	return 1;
}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
	// TODO
	return 0;
}

CP_Vector AngleToVector(float radian_angle)
{
    // TODO 
    //CP_Vector ret;
    //return ret;
}

