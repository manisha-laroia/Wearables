/* Library reference: https://learn.adafruit.com/circuit-playground-lesson-number-0/sound-sensor
Sound sensor keeps company and talks when quiet- performs.
*/

#include <Adafruit_Circuit_Playground.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

float value;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

  myservo.attach(9);  // attaches the servo on digital pin 9 to the servo object
}

void loop() {
  // Take 10 milliseconds of sound data to calculate
  value = CircuitPlayground.mic.soundPressureLevel(20);

  Serial.print("Sound Sensor SPL: ");
  Serial.println(value);

  if (value < 64) {
  for (pos = 0; pos <= 60; pos += 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
else {
  for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 30; pos >= 120; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
   delay(90);
}
