// Created: 2019-04-29 15:00:00
// Last modified: 2019-04-29 15:00:00
// author:  TheCatwoman


//this is a program for arduino UNO that is a virtual pet vape battery
//sort of super silly , i know 
//but whatever art is art
//be safe and dont explode your batteries lol


#include <LiquidCrystal.h>

byte cFace_eye[8] = {
    B00100,
    B01010,
    B00110,
    B01110,
    B01110,
    B01110,
    B01110,
    B01110
};

byte cFace_angry[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B01110,
    B01010,
    B01110
};

byte divider[8] = {
    B00001,
    B00001,
    B00001,
    B00001,
    B00001,
    B00001,
    B00001,
    B00001
};

byte heart[8] = {
    B00000,
    B01010,
    B11111,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000
};

byte smile[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B01110,
    B00000
};

byte frowning[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B01110,
    B10001,
    B00000
};

byte smoke[8] = {
    B01010,
    B10101,
    B01010,
    B10101,
    B01010,
    B10101,
    B01010,
    B00100
};

// ----------------- LCD -----------------

void drawPet(int expression) {
    lcd.clear();
    drawEyesAt(7, 0);
    drawFace(expression);
}

void drawEyesAt(int lcdRow, int lcdCol) {
    lcd.createChar(0, cFace_eye);
    lcd.createChar(1, cFace_eye);
    lcd.setCursor(lcdCol, lcdRow);
    lcd.write(byte(0));
    lcd.print("       ")
    lcd.write(byte(1));
}

void drawFace(int expression) {
    lcd.createChar(4, smile);
    lcd.createChar(5, frowning);
    lcd.createChar(6, smoke);
    lcd.createChar(7, cFace_angry);
    
    lcd.setCursor(11, 0);
    if (expression == SMILE) {
        lcd.write(byte(4));
    } else if (expression == FROWNING) {
        lcd.write(byte(5));
    } else if (expression == OPEN_MOUTH) {
        lcd.write(byte(6));
    
    }

void drawSmokeAt(int lcdRow, int lcdCol) {
        lcd.createChar(6, smoke);
        lcd.setCursor(lcdCol, lcdRow);
        lcd.write(byte(SMOKE));
        delay(250);
    }

void drawHeartAt(int lcdRow, int lcdCol) {
        lcd.createChar(7, heart);
        lcd.setCursor(lcdCol, lcdRow);
        lcd.write(byte(HEART));
    }

void drawDividerAt(int lcdRow, int lcdCol) {
        lcd.createChar(8, divider);
        lcd.setCursor(lcdCol, lcdRow);
        lcd.write(byte(DIVIDER));
    }

void drawTextAt(int lcdRow, int lcdCol, String text) {
        lcd.setCursor(lcdCol, lcdRow);
        lcd.print(text);
    }

void clearCharAt(int lcdRow, int lcdCol) {
        lcd.setCursor(lcdCol, lcdRow);
        lcd.print(" ");
    }
void drawScoreAt(int lcdRow, int lcdCol, int score) {
        lcd.setCursor(lcdCol, lcdRow);
        lcd.print(score);
    }
void resetScore() {
        score = 0;
        drawScoreAt(0, 0, score);
    }