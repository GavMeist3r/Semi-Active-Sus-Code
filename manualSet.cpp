#include <Arduino.h>

// Solenoid output pins
int pwmFront = 5;
int pwmBack = 6;
// Front motor direction pins
int m1inAFront = 8;
int m1inBFront = 7;
int m2inAFront = 10;
int m2inBFront = 9;
// Back motor direction pins
int m1inABack = 12;
int m1inBBack = 11;
int m2inABack = 25;
int m2inBBack = 24;

int dwait = 5; // 5 ms delay

// Front input pins
int softPinF = A0;  // Pin 14 on the teensy
int medPinF = A1;  // Pin 15 on the teensy
int hardPinF = A2;  // Pin 16 on the teensy
//int frontBPin = A0;
// Back input pins
int softPinB = A3;  // Pin 17 on the teensy
int medPinB = A4;  // Pin 18 on the teensy
int hardPinB = A5;  // Pin 19 on the teensy
//int backBPin = A3;

int softButtonStateF;
int medButtonStateF;
int hardButtonStateF;
int softButtonStateB;
int medButtonStateB;
int hardButtonStateB;
int pressureLevelFront = 50; // 0 < pwm output level < 255
int pressureLevelBack = 50; 
// Pressure level 0 is full hard and 255 is full soft

void setup() {
  pinMode(pwmFront, OUTPUT);
  pinMode(pwmBack, OUTPUT);
  pinMode(softPinF, INPUT_PULLUP);
  pinMode(medPinF, INPUT_PULLUP);
  pinMode(hardPinF, INPUT_PULLUP);
  pinMode(softPinB, INPUT_PULLUP);
  pinMode(medPinB, INPUT_PULLUP);
  pinMode(hardPinB, INPUT_PULLUP);

  digitalWrite(m1inAFront, 1);
  digitalWrite(m1inBFront, 0);
  digitalWrite(m2inAFront, 1);
  digitalWrite(m2inBFront, 0);
  digitalWrite(m1inABack, 1);
  digitalWrite(m1inBBack, 0);
  digitalWrite(m2inABack, 1);
  digitalWrite(m2inBBack, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  softButtonStateF = digitalRead(softPinF);
  medButtonStateF = digitalRead(medPinF);
  hardButtonStateF = digitalRead(hardPinF);

  softButtonStateB = digitalRead(softPinB);
  medButtonStateB = digitalRead(medPinB);
  hardButtonStateB = digitalRead(hardPinB);

  // Pressure levels for front shocks
  if(softButtonStateF == LOW){
    // Button was pressed
    pressureLevelFront = 200;
  }
  else if(medButtonStateF == LOW){
    pressureLevelFront = 150;
  }
  else if(hardButtonStateF == LOW){
    pressureLevelFront = 50;
  }

  // Pressure levels for back shocks
  if(softButtonStateB == LOW){
    pressureLevelBack = 200;
  }
  else if(medButtonStateB == LOW){
    pressureLevelBack = 150;
  }
  else if(hardButtonStateB == LOW){
    pressureLevelBack = 50;
  }

  analogWrite(pwmFront, pressureLevelFront);
  analogWrite(pwmBack, pressureLevelBack);

  delay(dwait);
}