#include <Sparki.h>

void setup(){
  sparki.clearLCD();
}

void loop(){
  sparki.clearLCD();
  int black = 900;
  int lineMid = sparki.lineCenter();
  int lineLeft = sparki.lineLeft();
  int lineRight = sparki.lineRight();
  int edgeLeft = sparki.edgeLeft();
  int edgeRight = sparki.edgeRight();
  sparki.println(edgeLeft);
  sparki.print(lineLeft);
  sparki.print("  ");
  sparki.print(lineMid);
  sparki.print("  ");
  sparki.println(lineRight);
  sparki.println(edgeRight);
  sparki.updateLCD();
  if (edgeLeft < black){
    sparki.moveForward(4);
    sparki.println("Turn Left");
    sparki.updateLCD();
    sparki.moveLeft(20);
    lineMid = sparki.lineCenter();
    while(lineMid > black){
    sparki.moveLeft();
    delay(20);
    lineMid = sparki.lineCenter();
    }
    sparki.moveLeft(10);
  }
  else if (lineLeft < black && edgeLeft > black){
    sparki.println("Left a little");
    sparki.updateLCD();
    sparki.moveLeft();
    delay(20);

  }
  else if (lineRight < black && edgeRight > black){
    sparki.println("Right a little");
    sparki.updateLCD();
    sparki.moveRight();
    delay(20);

  }
  else if (lineMid < black && lineLeft > black && lineRight > black){
    sparki.println("Move Forward");
    sparki.updateLCD();
    sparki.moveForward();
    delay(20);

  }
  else if (edgeRight < black){
    sparki.moveForward(4);
    sparki.println("Turn Right");
    sparki.updateLCD();
    sparki.moveRight(20);
    lineMid = sparki.lineCenter();
    while(lineMid > black){
    sparki.moveRight();
    delay(20);
    lineMid = sparki.lineCenter();
    }
    sparki.moveRight(10);
  }
  else if (lineMid > black && lineLeft > black && lineRight > black){
    int ending = 0;
    int turning = 0;
    int time = 1;
    while (ending == 0 && turning == 0){
      lineMid = sparki.lineCenter();
      if (lineMid < black){
        ending = 1;
      }
      if (time > 0){
        sparki.moveLeft();
        delay(10);
        time += 1;
        if (time > 10){
          time = -1;
          sparki.moveRight();
          delay(100);
        }
      }
      else if (time < 0){
        sparki.moveRight();
        delay(10);
        time -= 1;
        if (time < -10){
          time = 0;
          sparki.moveLeft();
          delay(100);
        }
      }
      else if (time = 0){
        turning = 1;
      }
    }
    while (ending == 0 && lineMid > black && lineLeft > black && lineRight > black){
      sparki.println("Back Off");
      sparki.updateLCD();
      sparki.moveBackward();
      delay(20);
      lineMid = sparki.lineCenter();
      lineLeft = sparki.lineLeft();
      lineRight = sparki.lineRight();
    }
    if(turning == 1){
      sparki.moveRight(180);
    }
  }
}
