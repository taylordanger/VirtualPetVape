// Created: 2019-04-29 15:00:00
// Last modified: 2019-04-29 15:00:00
// author:  TheCatwoman


//this is a program for arduino UNO that is a virtual pet vape battery
//sort of super silly , i know 
//but whatever art is art
//be safe and dont explode your batteries lol


unsigned long prevmove = 0;
unsigned long moveDelay = 900;
int timesMoved = 0;


void timePetMovements(unsigned long currentTime) {
    if(currentTime - prevMove >= moveDelay) {
        prevMove = currentTime;
        if(timesMoved < 3) {
            lcd.scrollDisplayLeft();
            timesMoved++;
        } else if(timesMoved < 6) {
            lcd.scrollDisplayRight();
            timesMoved++;
        } else {
            timesMoved = 0;
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


