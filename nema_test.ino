// defines pins numbers
const int stepPin = 5; 
const int dirPin = 2; 
const int enPin = 8;

#include <ezButton.h>

ezButton limitSwitch(7);  // create ezButton object that attach to pin 7;


void setup() {
  
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
  Serial.begin(9600);
  limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
}


void loop() {
  
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
  
  
}
