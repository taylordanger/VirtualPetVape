#include <LiquidCrystal.h>

// Function declarations
void drawPet(int expression);
void timePetMovements(unsigned long currentTime);
void scoreDown(unsigned long currentTime);
void buttonListener();
void drawDividerAt(int lcdRow, int lcdCol);
void drawScoreAt(int lcdRow, int lcdCol, int score);
void resetScore();

#define RIGHT_EYE 0
#define LEFT_EYE 1
#define SMILE 2
#define FROWNING 3
#define SMOKE 4
#define HEART 5
#define DIVIDER 6

LiquidCrystal lcd(0, 1, 8, 9, 10, 11);
const int buttonPin = 2;
const int vapePin = 3;

int buttonState = HIGH;
int vapeState = LOW;
int buttonPress = 0;
int score = 0;
int onHomeScreen = true;

unsigned long prevMove = 0;
unsigned long moveDelay = 900;
int timesMoved = 0;

void setup() {
unsigned long currentTime = millis();

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(vapePin, INPUT_PULLUP);
  lcd.begin(16, 2);
  drawDividerAt(1, 3);
  drawDividerAt(0, 3);
  drawScoreAt(0, 0, score);
  scoreMove(currentTime);
  drawPet(SMILE);
  timePetMovements(currentTime);
  // Initial pet display
}

void loop() {
  unsigned long currentTime = millis();

  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    buttonPress++;
    if (onHomeScreen) {
      lcd.clear();
      drawDividerAt(1, 3);
      drawDividerAt(0, 3);
      drawScoreAt(0, 0, score);
      drawPet(SMILE);
      timePetMovements(currentTime);
      scoreMove(currentTime);
    } else {
      lcd.clear();
      lcd.print("Vape Pet");
      lcd.setCursor(0, 1);
      lcd.print("vape to feed me!!");
      lcd.clear();
      drawPet(SMILE);
      timePetMovements(currentTime);
      scoreMove(currentTime);
    }
    onHomeScreen = !onHomeScreen;
    delay(500);
    
  }

  buttonListener(); // Call the button listener function

  if (buttonPress > 0) {
    drawPet(SMOKE);
    digitalWrite(vapePin, HIGH);
    delay(500);
    digitalWrite(vapePin, LOW);
    drawPet(SMILE);
    score++;
    drawScoreAt(0, 0, score);
    timePetMovements(currentTime);
    scoreMove(currentTime);
  if (score >= 3) {
    lcd.print("WHOAA..");
    lcd.clear();
  }
     
  }

  if (onHomeScreen) {
    timePetMovements(currentTime);
    scoreMove(000);
    drawDividerAt(1, 3);
    drawDividerAt(0, 3);
    drawScoreAt(0, 0, score);
     // Decrease score over time
  }
}
