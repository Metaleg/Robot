#ifndef Robot_h
#define Robot_h
#include <Stepper.h>

class Robot {

	static const int STEPS = 200;
	int pin1, pin2, pin3, pin4;
	float radius;
	float width;
	Stepper engine1{STEPS, pin1, pin2};
	Stepper engine2{STEPS, pin3, pin4};

	void drive(float distance1, float speed1, float distance2, float speed2)const;
	void drive(float distance, float speed, float angle)const;
	void turnAround(float speed, float angle);

	int stepsCalculate(float distance);
	float speedCalculate(float speed);


public:
	Robot(int p1, int p2, int p3, int p4, float r, float w);

	void driveForward(float distance, float speed)const;///----------------------вперед
	void driveBackward(float distance, float speed)const;///---------------------назад
	void driveLeft(float distance, float speed, float angle)const;///------------влево
	void driveRight(float distance, float speed, float angle)const;///-----------вправо
	void turnLeft(float speed, float angle)const;///-----------------------------разворот на месте влево
	void turnRight(float speed, float angle)const;///----------------------------разворот на месте вправо
};

#endif
