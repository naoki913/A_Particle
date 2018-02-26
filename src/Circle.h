#pragma once
#include"ofMain.h"
class Circle
{
public:
	void setup();
	void update();
	void draw();

	float getDegree(float x, float y);

	ofVec2f pos;
	ofVec2f center;
	ofVec2f gap;
	ofVec2f radious;
	float degree;
	float angle;
	float distance;
	float count;
	float radian;
	ofImage snow;
	ofImage img;
};

