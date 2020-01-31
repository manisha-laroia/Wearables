/**
 * Load and Display 
 * 
 * Images can be loaded and displayed to the screen at their actual size
 * or any other size. 
 * By Manisha Laroia, Mentor: Kate Hartman, 
 * Advanced Wearables, Digital Futures OCAD University
 *
 * Circuit playground playtone-
 * https://learn.adafruit.com/circuit-playground-music/the-circuit-playground-library
 * Pitch notes- https://learn.adafruit.com/circuit-playground-music/the-sound-of-music
 *
 */
import processing.serial.*; // import the Processing serial library
Serial myPort;              // The serial port

PImage img1; // Declare variable "a" of type PImage
PImage img2;
PImage img3;
PImage img4;
PImage img5;

int n = 0;
int o = 0;
int p = 0;
int q = 0;

int cap1;
int cap2;
int sensor1;
//float mappedSensor1;

void setup() {
  size(1000, 800);
  //fullScreen();
  background(0, 0, 0);

  //PFont font;
  //font = createFont("ShareTechMono.ttf", 32);
  //fill(255, 255, 255);
  //textAlign(CENTER);
  //textSize(32);
  //text("We have become a species of 'button pushers'.", width/2, height/2);
  //textAlign(LEFT);
  //textSize(18);
  //text("- Benjamin Bratton, The Stack.'", (width/2)+140, (height/2)+50);



  // List all the available serial ports in the console
  printArray(Serial.list());
  // Change the 6 to the appropriate number of the serial port
  // that your microcontroller is attached to.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  // read incoming bytes to a buffer
  // until you get a linefeed (ASCII 10):
  myPort.bufferUntil('\n');

  // The image file must be in the data folder of the current sketch 
  // to load successfully  
  img1 = loadImage("hi.png");  // Load the image into the program 
  img2 = loadImage("heart.png");
  img3 = loadImage("like.png");
  img4 = loadImage("poke.png");
  img5 = loadImage("hug.png");
}

void draw() {

  if (cap1==1) {
    poke();
  }

  if (cap2==1) {
    like();
  }
  //the threshld changes based on how the sensor is made and attached.
  if (sensor1>=400) {
    heart();
  }
}  

//void mouseClicked() {
//  image(img1, random(0,width), random(0,height), 100, 100);
//}   

void hi() {
  image(img1, random(0, width), random(0, height), 100, 100);
}  

void heart() {
  image(img2, random(0, width), random(0, height), 50, 50);
}  

void like() {
  image(img3, random(0, width), random(0, height), 50, 50);
}  

void poke() {
  image(img4, random(0, width), random(0, height), 50, 50);
}  

void serialEvent(Serial myPort) {
  // read the serial buffer:
  String myString = myPort.readStringUntil('\n');
  if (myString != null) {
    // println(myString);
    myString = trim(myString);

    // split the string at the commas
    // and convert the sections into integers:
    int sensors[] = int(split(myString, ','));
    for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
      print("Sensor " + sensorNum + ": " + sensors[sensorNum] + "\t");
    }
    // add a linefeed at the end:
    println();
    cap1 = sensors[0];  
    cap2 = sensors[1];
    sensor1 = sensors[2];
    // mappedSensor1 = map(sensor1, 0, 1023, height, 0);
  }
}
