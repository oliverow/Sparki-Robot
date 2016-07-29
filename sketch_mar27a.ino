#include <Sparki.h>

void setup(){
  sparki.servo(0);
  sparki.RGB(RGB_WHITE);
  sparki.motorRotate(MOTOR_LEFT, DIR_CCW, 160);
  sparki.motorRotate(MOTOR_RIGHT, DIR_CW, 160);
  delay(3000);
}

void loop(){
  sparki.clearLCD();
  int black = 700;
  int turningDegree = 45;
  int dist = sparki.ping();
  int searchingDist = 60;
  int lineLeft   = sparki.lineLeft();
  int lineCenter = sparki.lineCenter();
  int lineRight  = sparki.lineRight();
  if (lineCenter < black){
      sparki.RGB(100,0,0);
      sparki.moveBackward();
      delay(5000);
      if (lineLeft < black && lineRight > black){
        sparki.println("turn right");
        sparki.updateLCD();
        sparki.moveRight(turningDegree);
      }
      else if (lineLeft > black && lineRight < black){
        sparki.println("turn left");
        sparki.updateLCD();
        sparki.moveLeft(turningDegree);
      }
      else{
        sparki.println("turn right");
        sparki.updateLCD();
        sparki.moveRight(turningDegree);
      }
      sparki.moveForward();
      delay(4000);
  }
  else{
    int determined = 0;
    while(dist > searchingDist){
      sparki.RGB(0,0,100);
      sparki.clearLCD();
      sparki.moveRight();
      dist = sparki.ping();
      sparki.print("Distance: "); 
      sparki.print(dist);
      sparki.println(" cm");
      sparki.println("searching forward area");
      sparki.updateLCD();
      delay(5);
      determined = 1;
    }
    if (determined == 1){
      sparki.println("target determined");
      sparki.println("turing to right position");
      sparki.updateLCD();
      sparki.moveRight();
      delay(400);
    }
    sparki.RGB(0,100,0);
    sparki.clearLCD();
    sparki.motorRotate(MOTOR_LEFT, DIR_CCW, 160);
    sparki.motorRotate(MOTOR_RIGHT, DIR_CW, 160);
    sparki.print("Distance: "); 
    sparki.print(dist);
    sparki.println(" cm");
    sparki.println("moving toward the target");
    sparki.updateLCD();
    delay(50);
  }
}

