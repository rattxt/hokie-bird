#include <Servo.h>
#include <ezButton.h>


const int stepPin = 5; 
const int dirPin = 2; 
const int enPin = 8;
const int def = 90; //  angle of the servo, defaults at 0 degrees (looking ahead).
int pos = 0;


Servo eyeServo;  // creates servo object
Servo tailServo;

ezButton limitSwitch(7);  // create ezButton object that attach to pin 7;




void setup() {

// eye set up
  Serial.begin(9600);
  eyeServo.attach(10); // attatch eye servo to digital pin 9
// cease

// body set up
   // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
  Serial.begin(9600);
  limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
// cease

// tail set up
 tailServo.attach(9); 
//cease

}


void loop() {

// EYE BEGIN
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
// EYE END

// body begin 
 limitSwitch.loop(); // MUST call the loop() function first


  int state = limitSwitch.getState();
    Serial.println(state);

    while (state == 1) {
    digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
    // Makes 200 pulses for making one full cycle rotation
    for(int x = 0; x < 800; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(5000); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(100000); 
    }

    digitalWrite(dirPin,LOW); //Changes the rotations direction
    // Makes 400 pulses for making two full cycle rotation
    for(int x = 0; x < 800; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(5000);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(100000);
   }
  }

// body end

// tail move
 for (pos = 0; pos <= 270; pos += 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    tailServo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println("Hello world!");
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  Serial.println("Hello world!");

  for (pos = 270; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees

    tailServo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println("Bottom Text");
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  Serial.println("Bottom Text");
// cease

}



// functions

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
    eyeServo.write(i);
    Serial.print(i);
    Serial.print('\t');
  } 
  for(int j = turnTilL; j >= def; j--) { // goes back
    eyeServo.write(j);
    Serial.print(j);
    Serial.print('\t');
  }   
  Serial.println();
} 


void lookRight() {             
  int turnTilR = randomTime(0, 90);        
  for(int i = turnTilR; i <= def; i++) { // goes to determined angle
    eyeServo.write(i);
    Serial.print(i);
    Serial.print('\t');
  }   
  for(int j = def; j >= turnTilR; j--) { // goes back
    eyeServo.write(j);
    Serial.print(j);
    Serial.print('\t');
  }
  Serial.println();  
}


void fullSweep() {
  for(int i = 0; i <= 180; i++) {
    eyeServo.write(i);
    Serial.print(i);
    Serial.print('\t');
  }
  
  for(int j = 180; j >= 0; j--) {
    eyeServo.write(j);
    Serial.print(j);
    Serial.print('\t');
  }
  Serial.println();
}