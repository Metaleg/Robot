#include "Arduino.h"
#include "Robot.h"
#include <math.h>
#define _USE_MATH_DEFINES	//for use PI

//На версии со стандартным Stepper двигатель совершает 800 шагов за оборот, поэтому далее расстояние distance умножается на 4;

//Разворот на месте осуществляется относительно центра оси колес, в нашем случае она сдвинута относительно центра масс на несколько сантиметров.
//Поэтому угол angle умножается на 1.15;

//Умножение скорости speed на 5 вычислено эмпирическим путем.




////////----------------------CONSTRUCTORS-------------------------------------//////////

Robot::Robot(int p1, int p2, int p3, int p4, float r, float w) :
	pin1(p1), pin2(p2), pin3(p3), pin4(p4), radius(r), width(w) {}



///////-------------------------METHODS---------------------------------------///////////

int Robot::stepsCalculate(float distance) {				//-----------------converting distance to steps
	return (int)(distance * STEPS) / (2 * M_PI * radius);
}

float Robot::speedCalculate(float speed) {				//-----------------converting speed from kilometers per hour to rpm
	return (int)(speed * 1000 / (2 * M_PI * radius * 60));
}

void Robot::driveForward(float distance, float speed)const {
	distance *= 4;
	speed *= 5;
	this->drive(distance, speed, distance, speed);
}

void Robot::driveBackward(float distance, float speed)const {
	distance *= 4;
	speed *= 5;
	this->drive(-distance, speed, -distance, speed);
}

void Robot::driveLeft(float distance, float speed, float angle)const {
	distance *= 4;
	speed *= 5;
	angle *= 1.2;
	this->drive(distance, speed, angle);
}

void Robot::driveRight(float distance, float speed, float angle)const {
	distance *= 4;
	speed *= 5;
	angle *= 1.2;
	this->drive(distance, speed, -angle);
}

void Robot::turnLeft(float speed, float angle)const {
	speed *= 5;
	angle *= 1.2;
	this->turnAround(speed, angle);
}

void Robot::turnRight(float speed, float angle)const {
	speed *= 5;
	angle *= 1.2;
	this->turnAround(speed, -angle);
}

//////////---------------------------BASIC FUNCTIONS------------------------------------------//////

void Robot::turnAround(float speed, float angle) {
	float distance = M_PI * width / (360 / angle);
	distance *= 4;

	engine1.setSpeed(speedCalculate(speed));
	engine2.setSpeed(speedCalculate(speed));

	for (int i = 0; i < abs(stepsCalculate(distance)); ++i) {
		engine1.step(-distance / abs(distance));
		engine2.step(-distance / abs(distance));
	}
}


void Robot::drive(float distance, float speed, float angle)const {

	float time = distance / speed;
	float centerRadius = distance * (360 / angle) / (M_PI * 2);

	float radius1 = centerRadius - width * 2;			///----------умножаем на 2(вместо деления, так как умножаем все на 4)
	float radius2 = centerRadius + width * 2;

	float distance1 = M_PI * 2 * radius1 / (360 / angle);
	float distance2 = M_PI * 2 * radius2 / (360 / angle);

	float speed1 = distance1 / time;
	float speed2 = distance2 / time;

	this->drive(distance1, speed1, distance2, speed2);
}



void Robot::drive(float distance1, float speed1, float distance2, float speed2)const {
	engine1.setSpeed(speedCalculate(speed1));
	engine2.setSpeed(speedCalculate(speed2));

	float stepCoef = abs((float)stepsCalculate(distance2) / (float)stepsCalculate(distance1));
	float currentStep = 0;
	int direction_1 = distance1 / abs(distance1);
	int direction_2 = -(distance2 / abs(distance2));

	for (int j = 0; j < abs(stepsCalculate(distance1)); ++j) {

		engine1.step(direction_1);
		currentStep += stepCoef;
		while (currentStep >= 1) {
			engine2.step(direction_2);
			currentStep -= 1;
		}
	}
}
