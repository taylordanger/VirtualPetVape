#include <LiquidCrystal.h>

extern LiquidCrystal lcd;
extern int score;

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

void drawPet(int expression) {
  lcd.setCursor(0, 0);
  drawEyesAt(0, 4);
  drawFace(expression);
}

void drawEyesAt(int lcdRow, int lcdCol) {
  lcd.createChar(0, cFace_eye);
  lcd.setCursor(lcdCol, lcdRow);
  lcd.write(byte(0));
  lcd.print("     ");
  lcd.write(byte(0));
}

void drawFace(int expression) {
  lcd.createChar(1, smile);
  lcd.createChar(2, frowning);
  lcd.createChar(3, smoke);
  lcd.createChar(4, cFace_angry);

  lcd.setCursor(7, 0);
  if (expression == SMILE) {
    lcd.write(byte(1));
  } else if (expression == FROWNING) {
    lcd.write(byte(2));
  } else if (expression == SMOKE) {
    lcd.write(byte(3));
  }
}

void drawSmokeAt(int lcdRow, int lcdCol) {
  lcd.createChar(3, smoke);
  lcd.setCursor(lcdCol, lcdRow);
  lcd.write(byte(3));
  delay(250);
}

void drawHeartAt(int lcdRow, int lcdCol) {
  lcd.createChar(4, heart);
  lcd.setCursor(lcdCol, lcdRow);
  lcd.write(byte(4));
}

void drawDividerAt(int lcdRow, int lcdCol) {
  lcd.createChar(5, divider);
  lcd.setCursor(lcdCol, lcdRow);
  lcd.write(byte(5));
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
