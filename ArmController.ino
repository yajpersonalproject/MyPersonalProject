#include <Servo.h>

const unsigned int MAX_MESSAGE_LENGTH = 12;
String entered;
int fullFlex = 180;
int threequarterFlex = 135;
int halfFlex = 90;
int quarterFlex = 45;
int resetFlex = 0;
Servo thumb;
Servo index;
Servo middle;
Servo ring;
Servo pinky;
Servo wrist;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  thumb.attach(8);
  index.attach(9);
  middle.attach(10);
  ring.attach(11);
  pinky.attach(12);
  wrist.attach(13);
}

void calibrate() {
  //calibration of thumb
  thumb.write(quarterFlex);
  delay(300); //300 millisecond delay
  thumb.write(resetFlex);
  delay(300); //300 millisecond delay
  thumb.write(quarterFlex);
  delay(300); //300 millisecond delay
  thumb.write(resetFlex);
  delay(300); //300 millisecond delay
  thumb.write(halfFlex);
  delay(300); //300 millisecond delay
  thumb.write(resetFlex);
  delay(300); //300 millisecond delay
  thumb.write(threequarterFlex);
  delay(300); //300 millisecond delay
  thumb.write(resetFlex);
  delay(300); //300 millisecond delay
  thumb.write(fullFlex);
  delay(300); //300 millisecond delay
  thumb.write(resetFlex);
  delay(300); //300 millisecond delay

  //calibration of index
  index.write(quarterFlex);
  delay(300); //300 millisecond delay
  index.write(resetFlex);
  delay(300); //300 millisecond delay
  index.write(quarterFlex);
  delay(300); //300 millisecond delay
  index.write(resetFlex);
  delay(300); //300 millisecond delay
  index.write(halfFlex);
  delay(300); //300 millisecond delay
  index.write(resetFlex);
  delay(300); //300 millisecond delay
  index.write(threequarterFlex);
  delay(300); //300 millisecond delay
  index.write(resetFlex);
  delay(300); //300 millisecond delay
  index.write(fullFlex);
  delay(300); //300 millisecond delay
  index.write(resetFlex);
  delay(300); //300 millisecond delay

  //calibration of middle
  middle.write(quarterFlex);
  delay(300); //300 millisecond delay
  middle.write(resetFlex);
  delay(300); //300 millisecond delay
  middle.write(quarterFlex);
  delay(300); //300 millisecond delay
  middle.write(resetFlex);
  delay(300); //300 millisecond delay
  middle.write(halfFlex);
  delay(300); //300 millisecond delay
  middle.write(resetFlex);
  delay(300); //300 millisecond delay
  middle.write(threequarterFlex);
  delay(300); //300 millisecond delay
  middle.write(resetFlex);
  delay(300); //300 millisecond delay
  middle.write(fullFlex);
  delay(300); //300 millisecond delay
  middle.write(resetFlex);
  delay(300); //300 millisecond delay

  //calibration of ring
  ring.write(quarterFlex);
  delay(300); //300 millisecond delay
  ring.write(resetFlex);
  delay(300); //300 millisecond delay
  ring.write(quarterFlex);
  delay(300); //300 millisecond delay
  ring.write(resetFlex);
  delay(300); //300 millisecond delay
  ring.write(halfFlex);
  delay(300); //300 millisecond delay
  ring.write(resetFlex);
  delay(300); //300 millisecond delay
  ring.write(threequarterFlex);
  delay(300); //300 millisecond delay
  ring.write(resetFlex);
  delay(300); //300 millisecond delay
  ring.write(fullFlex);
  delay(300); //300 millisecond delay
  ring.write(resetFlex);
  delay(300); //300 millisecond delay

  //calibration of pinky
  pinky.write(quarterFlex);
  delay(300); //300 millisecond delay
  pinky.write(resetFlex);
  delay(300); //300 millisecond delay
  pinky.write(quarterFlex);
  delay(300); //300 millisecond delay
  pinky.write(resetFlex);
  delay(300); //300 millisecond delay
  pinky.write(halfFlex);
  delay(300); //300 millisecond delay
  pinky.write(resetFlex);
  delay(300); //300 millisecond delay
  pinky.write(threequarterFlex);
  delay(300); //300 millisecond delay
  pinky.write(resetFlex);
  delay(300); //300 millisecond delay
  pinky.write(fullFlex);
  delay(300); //300 millisecond delay
  pinky.write(resetFlex);
  delay(300); //300 millisecond delay
}

void flare() {

  //We want all the fingers one by one to perform a grabbing motion
  thumb.write(resetFlex);
  delay(750);
  thumb.write(fullFlex);
  delay(750); //750 milli seconds, which is about 3/4th of a full second
  index.write(fullFlex);
  delay(750); //750 milli seconds, which is about 3/4th of a full second
  middle.write(fullFlex);
  delay(750); //750 milli seconds, which is about 3/4th of a full second
  ring.write(fullFlex);
  delay(750); //750 milli seconds, which is about 3/4th of a full second
  pinky.write(fullFlex);

  //Now we're making the servos go back to the original position, to complete the 'flaring' of the fingers

  delay(750); //750 milli seconds, which is about 3/4th of a full second
  pinky.write(resetFlex);
  delay(750); //750 milli seconds, which is about 3/4th of a full second
  ring.write(resetFlex);
  delay(750); //750 milli seconds, which is about 3/4th of a full second
  middle.write(resetFlex);
  delay(750); //750 milli seconds, which is about 3/4th of a full second
  index.write(resetFlex);
  delay(750); //750 milli seconds, which is about 3/4th of a full second
  
}

void fullGrab() {
  //No delay will be given, we want it to grab immediately
  thumb.write(fullFlex);
  delay(100);
  index.write(fullFlex);
  delay(100);
  middle.write(fullFlex);
  delay(100);
  ring.write(fullFlex);
  delay(100);
  pinky.write(fullFlex);
  delay(100);
  
}

void halfGrab() {
  //In situations where a loose grip is neccesary
  thumb.write(halfFlex);
  index.write(halfFlex);
  middle.write(halfFlex);
  ring.write(halfFlex);
  pinky.write(halfFlex);
}

void release1() {
  //A very versatile function, will be used a lot in the main loop
  thumb.write(resetFlex);
  index.write(resetFlex);
  middle.write(resetFlex);
  ring.write(resetFlex);
  pinky.write(resetFlex);
}

void thumbsUp() {
  index.write(fullFlex);
  middle.write(fullFlex);
  ring.write(fullFlex);
  pinky.write(fullFlex);
  thumb.write(resetFlex);
}

void rock() {
  middle.write(fullFlex);
  ring.write(fullFlex);
  index.write(resetFlex);
  pinky.write(resetFlex);
  thumb.write(resetFlex);
}

//pinch

void point() {
  middle.write(fullFlex);
  ring.write(fullFlex);
  pinky.write(fullFlex);
  thumb.write(fullFlex);
  index.write(resetFlex);
}
 
void clawGrip() {
  thumb.write(quarterFlex);       
  index.write(quarterFlex);
  middle.write(quarterFlex);
  ring.write(quarterFlex);
  pinky.write(quarterFlex);
}

void wristSTUaltRot(){ //wrist "side to up" rotation, implying a 90 degree rotation ALT refers to alternating, meaning it goes both sides
  wrist.detach();
  delay(5000);
  wrist.attach(13); 
  wrist.write(180);
  delay(250);
}

void wrist22(){
  wrist.detach();
  delay(5000);
  wrist.attach(13);
  wrist.write(0);
  delay(250);
}
void loop() {
  //hand has to go through a calibration phase to ensure accurate measurements, and accurate measurements are foundational to the quality of my product
  while(Serial.available()){
    entered = Serial.readString(); 
    if(entered=="grab"){
      fullGrab();
    }
    if (entered=="release"){
      release1();
    }
    if (entered=="alternate"){
      flare();
    }
    if (entered=="point"){
      point();
    }
  }
}
