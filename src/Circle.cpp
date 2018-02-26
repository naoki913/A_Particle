#include "Circle.h"


void Circle::setup() {
	pos.x = ofGetMouseX();
	pos.y = ofGetMouseY();
	center.x =  ofGetWidth() / 2;
	center.y =  ofGetHeight() / 2;
	radious.x = 200;
	//radious.y = radious.x / 2;
	gap = pos - center;
	degree=getDegree(gap.x, gap.y);
	//printf("%f\n", degree);

	count = 0;
	
	distance = sqrt(gap.x*gap.x + gap.y*gap.y);
	angle = 0;
	img.load("A_particle.png");
	snow.load("A_snow.png");

}

void Circle::update() {
	count+=2;
	if (count == 360)count = 0;
	radian = count*PI / 180;

	pos.x = distance*cos(radian);
	pos.y = distance/2 * sin(radian);
	
	if (distance < radious.x)distance++;
	
	if (distance > radious.x)distance--;

	angle++;
}

void Circle::draw() {
	ofPushMatrix();
	ofTranslate(center);
	ofRotate(degree);


	float posx = pos.x - 16;
	float posy = pos.y - 16;


	img.draw(posx - 16 + 10 * sin(50*ofGetElapsedTimef()), posy - 16 + 10 * cos(50*ofGetElapsedTimef()));


	ofPushMatrix();
	ofTranslate(posx, posy);
	ofRotate(angle);
	snow.draw(-snow.getWidth() / 2, -snow.getHeight() / 2);
	ofPopMatrix();




	//ofCircle(pos, 10);
	ofPopMatrix();
}

float Circle::getDegree(float x, float y) {
	float radian = atan2(y, x);
	float degree = radian * 180 / PI;
	
	return degree;
}