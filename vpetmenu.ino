#include <LiquidCrystal.h>

extern int onHomeScreen;
extern int buttonPress;
extern int score;
extern int vapeState;

void buttonPresses() {
  if (onHomeScreen) {
    onHomeScreen = false;
  }
}

void buttonListener() {
  switch (buttonPress) {
    case 1:
      buttonPress = 1;
      drawFace(SMOKE);
      digitalWrite(vapePin, LOW);
      delay(500);
      digitalWrite(vapePin, LOW);
      drawFace(SMILE);
      score++;
      drawScoreAt(0, 0, score);
      buttonPress--;
      break;

    case 2:
      buttonPress = 2;
      showMenu();
      clearCharAt(10, 1);
      setPointerTo(5, 0);
      lcd.print(">");
      if (vapeState == LOW) {
        resetScore();
      }
      break;

    case 3:
      buttonPress = 3;
      showMenu();
      clearCharAt(5, 1);
      setPointerTo(10, 0);
      if (vapeState == HIGH) {
        onHomeScreen = true;
      }
      break;
  }
}

void showMenu() {
  lcd.clear();
  drawDividerAt(0, 4);
  drawScoreAt(0, 0, score);
  drawTextAt(1, 0, "Reset Score?");
  drawTextAt(1, 5, "yes");
  drawTextAt(1, 10, "Quit");
}

void setPointerTo(int lcdRow, int lcdCol) {
  lcd.setCursor(lcdCol, lcdRow);
}
