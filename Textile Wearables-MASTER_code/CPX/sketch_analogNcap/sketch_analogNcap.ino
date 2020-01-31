/*
   https://learn.adafruit.com/circuit-playground-fruit-drums/hello-capacitive-touch
      By Manisha Laroia, Mentor: Kate Hartman,
   Advanced Wearables, Digital Futures OCAD University

   Circuit playground playtone-
   https://learn.adafruit.com/circuit-playground-music/the-circuit-playground-library
   Pitch notes- https://learn.adafruit.com/circuit-playground-music/the-sound-of-music

*/

#include <Adafruit_CircuitPlayground.h>

//for cap function
#define CAP_THRESHOLD   500
#define DEBOUNCE        250
int felt1val;
int felt2val;

//for analog function
int sensorPin = A6;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor


////////////////////////////////////////////////////////////////////////////
boolean capButton(uint8_t pad) {
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;
  } else {
    return false;
  }
}

////////////////////////////////////////////////////////////////////////////
void setup() {
  // Initialize serial.
  Serial.begin(9600);

  // Initialize Circuit Playground library.
  CircuitPlayground.begin();

  pinMode(ledPin, INPUT); //for analog function
}

////////////////////////////////////////////////////////////////////////////
void loop() {


  CircuitPlayground.setPixelColor(3, 0, 0, 0);
  CircuitPlayground.setPixelColor(8, 0, 0, 0);
  // Check if capacitive touch exceeds threshold.

  CircuitPlayground.setPixelColor(0, 0, 0, 0);
  CircuitPlayground.setPixelColor(1, 0, 0, 0);

  // read the switch value
  felt1val = capButton(6);
  // print out the switch value
  Serial.print(felt1val);
  // print a comma to separate the values
  Serial.print(",");

  felt2val = capButton(2);
  // print out the switch value
  Serial.print(felt2val);
  // print a comma to separate the values
  Serial.print(",");

  sensorValue = analogRead(sensorPin);
  // print out the switch value
  Serial.print(sensorValue);
  // print a comma to separate the values
  Serial.println(",");

  delay(100); // the delay is necessary for the serial communication

  digitalWrite(ledPin, HIGH);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:

  //the threshld changes based on how the sensor is made and attached.
  if (sensorValue >= 800) {
    sensor1();
  }
  //
  //  if (sensorValue < 100) {
  //    sensorOff();
  //  }

  delay(100);

  if (capButton(6)) {
    felt1();
  }

  if (capButton(2)) {
    felt2();
  }
  // But not too often.
  delay(DEBOUNCE);
}

void felt1() {
  //  Serial.println("Touched!");
  CircuitPlayground.playTone(440, 100);
  CircuitPlayground.setPixelColor(3, 120, 63, 150);
}

void felt2() {
  //  Serial.println("Touched!");
  CircuitPlayground.playTone(900, 20);
  CircuitPlayground.setPixelColor(8, 200, 63, 50);
}

void sensor1() {
  CircuitPlayground.setPixelColor(0, 80, 38, 200);
  CircuitPlayground.setPixelColor(1, 120, 63, 150);
  CircuitPlayground.playTone(100, 50);
}

//void sensorOff() {
//  CircuitPlayground.clearPixels();
////  CircuitPlayground.playTone(0, 0);
//}
