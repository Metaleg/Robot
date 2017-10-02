#include "Robot.h"
int c=0;
Robot robo(8, 9, 11, 10, 0.051, 0.204);

void setup(){
  /*pinMode(3, OUTPUT);  
  pinMode(11, OUTPUT);  
  digitalWrite(3, HIGH);
  digitalWrite(11, HIGH);*/
}

void loop(){
  if (c==0){
  /*robo.driveForward(1.273, 1);
  delay(200);
  robo.turnLeft(0.25, 90);
  delay(200);
 
  robo.driveLeft(8, 0.5, 360);
  delay(2000);
  robo.driveBackward(1.273, 1);
  delay(2000);
  
  robo.turnLeft(0.25, 90);
  delay(2000);
  robo.driveForward(2.546, 1);
  delay(200);
  robo.turnRight(0.25, 90);
  delay(200);
  robo.driveForward(2.546, 1);
  delay(200);
  robo.turnRight(0.25, 90);
  delay(200);
  robo.driveForward(2.546, 1);
  delay(200);
  robo.turnRight(0.25, 90);
  delay(200);
  robo.driveForward(1.273, 1);
  delay(200);
  robo.turnRight(0.25, 90);
  delay(200);
  
  robo.driveForward(1.273, 1);
  delay(200);
  robo.turnRight(0.25, 360);
  delay(200);*/
  robo.driveForward(1, 1);
  delay(200);
  robo.driveBackward(1, 1);
  delay(200);
  robo.driveLeft(1, 1, 90);
  delay(200);
  robo.driveRight(1, 1, 90);
  delay(200);
  robo.turnLeft(0.5, 90);
  delay(200);
  robo.turnRight(0.5, 90);
  delay(200);
  c++;
  }
}

