// Created: 2019-04-29 15:00:00
// Last modified: 2019-04-29 15:00:00
// author:  TheCatwoman


//this is a program for arduino UNO that is a virtual pet vape battery
//sort of super silly , i know 
//but whatever art is art
//be safe and dont explode your batteries lol


void buttonpress() {
    if(onHomeScreen) { onHomeScreen = false; }
    
}

void buttonListener() {
    switch(buttonpresses) {
        case 1:
            buttonpress = 1;
            drawFace(OPEN_MOUTH);
            digitalWrite(vapePin, HIGH);
            delay(500);
            digitalWrite(vapePin, LOW);
            drawFace(SMILE);
            score++;
            drawScoreAt(0, 0, score);
            buttonPresses--;
            break;

        case 2:
            buttonpress = 2;
            showMenu();
            clearCharAt(10, 1);
            setPointerTo(5, 0);
            lcd.print(">");
            if(selectState == LOW) {
                resetScore();
            }
        case 3;
            buttonpress = 3;
            showMenu();
            clearCharAt(5, 1);
            setPointerTo(10, 0);
            if(selectState == LOW) {
                onHomeScreen = true;
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