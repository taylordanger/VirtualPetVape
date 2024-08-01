// Created: 2019-04-29 15:00:00
// Last modified: 2019-04-29 15:00:00
// author:  TheCatwoman


//this is a program for arduino UNO that is a virtual pet vape battery
//sort of super silly , i know 
//but whatever art is art
//be safe and dont explode your batteries lol


#include <LiquidCrystal.h>

#define RIGHT_EYE 0
#define LEFT_EYE 1
#define SMILE 2
#define FROWNING 3
#define OPEN_MOUTH 4

LiquidCrystal(0,1,9,10,11);
const int buttonPin = 2;
const int vapePin = 3;


int buttonState = HIGH;
int vapeState = HIGH;
int buttonPresses = 0;
int score = 0;

int onHomeScreen = true;

if(onHomeScreen = true) {
    drawDividerAt(0, 4);
    drawScoreAt(0, 0, score);
}

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(vapePin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Vape Pet");
  lcd.setCursor(0, 1);
  lcd.print("vape to feed me!!");
  lcd.clear();
  drawFace(SMILE);  
  drawDividerAt(0, 4);
  drawScoreAt(0, 0, score);

}

void loop() {
    unsigned long currentMillis = millis();

  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    buttonPresses++;
    if (onHomeScreen) {
      lcd.clear();
      drawFace(SMILE);
      timePetMovements(currentTime);
    } else {
      lcd.clear();
      lcd.print("Vape Pet");
      lcd.setCursor(0, 1);
      lcd.print("vape to feed me!!");
      drawFace(SMILE);
    }
    onHomeScreen = !onHomeScreen;
    delay(500);
  }

  buttonListener();


  if (buttonPresses > 0) {
    drawFace(OPEN_MOUTH);

    digitalWrite(vapePin, HIGH);
    delay(500);
    digitalWrite(vapePin, LOW);
    drawFace(SMILE);
    score++;
    drawScoreAt(0, 0, score);
    buttonPresses--;
  }

if(onHomeScreen) {
    drawDividerAt(0, 4);
    drawScoreAt(0, 0, score);
    timePetMovements(currentTime);
}
}