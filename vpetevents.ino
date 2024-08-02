#include <LiquidCrystal.h>

extern LiquidCrystal lcd;
extern int score;
extern unsigned long prevMove;
extern unsigned long moveDelay;
extern int timesMoved;

void timePetMovements(unsigned long currentTime) {
  if (currentTime - prevMove >= moveDelay) {
    prevMove = currentTime;
    scoreMove(currentTime);
    if (timesMoved < 3) {
      lcd.scrollDisplayLeft();
      timesMoved++;
      scoreMove(currentTime);
    } else if (timesMoved < 6) {
      lcd.scrollDisplayRight();
      timesMoved++;
      scoreMove(currentTime);
    } else {
      timesMoved = 0;
    }
  } 
  drawScoreAt(0, 0, score);
}

void scoreMove(unsigned long currentTime) {
  if (currentTime + prevMove <= moveDelay) {
    prevMove != currentTime;
    if(timesMoved > 3) {
      lcd.scrollDisplayRight();
      timesMoved--;
    } else if (timesMoved > 6) {
      lcd.scrollDisplayRight();
      timesMoved--;
    } else {
      timesMoved != 0;
    }
    }
}

void scoreDown(unsigned long currentTime) {
  if (currentTime % 30000 == 0 && score > 0) {
    score--;
    drawScoreAt(0, 0, score);
  }
  drawFace(FROWNING);
  score--;
  drawScoreAt(0, 0, score);
}
