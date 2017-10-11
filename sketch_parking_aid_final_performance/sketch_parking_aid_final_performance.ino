#include <JeeLib.h> // Low power functions library

ISR(WDT_vect) {
  Sleepy::watchdogEvent(); // Setup the watchdog
}

const int TRIG_PIN = 3; //3
const int ECHO_PIN = 2; //4
const int RED_PIN = 7; //7
const int YELLOW_PIN = 5; //10
const int GREEN_PIN = 13; //13
const long MAX_TIME = 45;

long last = 0;
int count = 0;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long cm = calculateDistance();

  Serial.print(cm);
  Serial.print(" ");
  Serial.print(last);
  Serial.print(" ");
  Serial.print(count);
  Serial.print(" ");
  Serial.println();

  //  if (last > cm - 30 && last < cm + 30) {
  if (cm < 150) {

    if (cm >= last - 2 && cm <= last + 2) {
      count += 1;
    } else {
      count = 0;
    }

    if (count < MAX_TIME) {
      if (cm < 30) {
        switchLeds(true, false, false);
      } else if (cm < 50) {
        switchLeds(false, true, false);
      } else if (cm < 100) {
        switchLeds(false, false, true);
      } else {
        switchLeds(false, false, false);
      }
      //Sleepy::loseSomeTime(500);
      delay(500);
      Serial.print("Midiendo");
      Serial.println();
    } else {
      Serial.print("Sleep");
      Serial.println();
      if (count == MAX_TIME) {
        switchLeds(false, false, false);
      } else {
        count = MAX_TIME + 1;
      }
      Sleepy::loseSomeTime(5000);
    }
    last = cm;
  } else {
  }
  if (last == 0) {
    last = cm;
  }
  //delay(500);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

long calculateDistance() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(250);
  //Sleepy::loseSomeTime(250);
  //accuracy??
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(250);
  //Sleepy::loseSomeTime(250);
  //accuracy??
  digitalWrite(TRIG_PIN, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  if (cm > 150) {
    cm = 150;
  }
  return cm;
}

void switchLeds(bool red, bool yellow, bool green) {
  if (red) {
    digitalWrite(RED_PIN, HIGH);
  } else {
    digitalWrite(RED_PIN, LOW);
  }
  if (yellow) {
    digitalWrite(YELLOW_PIN, HIGH);
  } else {
    digitalWrite(YELLOW_PIN, LOW);
  }
  if (green) {
    digitalWrite(GREEN_PIN, HIGH);
  } else {
    digitalWrite(GREEN_PIN, LOW);
  }

}
