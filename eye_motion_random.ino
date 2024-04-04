/*
*
 * Eye motion control for Hokie Bird Animatronic
 * Calculates a random amount of time, speed, and eye movement and then... does.. it.
 *
 */

#include <Servo.h>

Servo servo;  // creates servo object
const int def = 90; //  angle of the servo, defaults at 0 degrees (looking ahead).


int randomTime(int min, int max){ 
  return random(min, max);
}

int randomSpeed() { // needs to be implemented...
  return random(1000, 10000);
}

int randomMovement() {
  return random(1, 4);
}



void lookLeft() {
  int turnTilL = randomTime(90, 180);     // determines degree of movement  
  for(int i = def; i <= turnTilL; i++) { // goes to determined angle
    servo.write(i);
    Serial.print(i);
    Serial.print('\t');
  } 
  for(int j = turnTilL; j >= def; j--) { // goes back
    servo.write(j);
    Serial.print(j);
    Serial.print('\t');
  }   
  Serial.println();
} 


void lookRight() {             
  int turnTilR = randomTime(0, 90);        
  for(int i = turnTilR; i <= def; i++) { // goes to determined angle
    servo.write(i);
    Serial.print(i);
    Serial.print('\t');
  }   
  for(int j = def; j >= turnTilR; j--) { // goes back
    servo.write(j);
    Serial.print(j);
    Serial.print('\t');
  }
  Serial.println();  
}


void fullSweep() {
  for(int i = 0; i <= 180; i++) {
    servo.write(i);
    Serial.print(i);
    Serial.print('\t');
  }
  
  for(int j = 180; j >= 0; j--) {
    servo.write(j);
    Serial.print(j);
    Serial.print('\t');
  }
  Serial.println();
}



void setup() {
  Serial.begin(9600);
  servo.attach(9); // attatch servo to digital pin 9
}

   // code currently assumes that 90 degrees is equal to the
  //  hokie bird looking straight ahead, 0 degrees is to the 
 //   left, and 180 is to the right.  This will need to be
//    changed when implemented onto the animatronic, though.

void loop() {

  Serial.println();
  int movement = randomMovement();
  Serial.println(movement);


  switch(movement) {
    case 1:
    Serial.println("look left function");
      lookLeft();
      Serial.println("LL fini");
      Serial.println();
      break;

    case 2:
    Serial.println("Look right function");
      lookRight();
      Serial.println("LR fini");
      Serial.println();
      break;

    case 3:
    Serial.println("Full sweep");
      fullSweep();
      Serial.println("Full sweep fini");
      Serial.println();
      break;

    default:
      Serial.println();
      break;
  }

  int delay_amt = randomTime(1000, 10000);
  Serial.println(delay_amt);
  delay(delay_amt);
}



