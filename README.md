# Vape Pet LCD Display  (Tokeamachi)

This project uses an Arduino UNO R3 and an LCD screen to create a virtual pet that responds to button presses and a vape sensor. The pet's face can show different expressions, and its movements are animated on the LCD screen. The project is divided into four source files, each handling different aspects of the functionality.

## Files

1. `vpet.ino`
2. `vpetart.ino`
3. `vpetmenu.ino`
4. `vpetevents.ino`

### `vpet.ino`

This is the main file that initializes the hardware and handles the main loop. It reads input from the button and vape sensor, updates the pet's expression and score, and switches between the home screen and menu.

### `vpetart.ino`

Contains the custom character definitions for the pet's face and other graphical elements on the LCD. It also includes functions to draw these characters on the screen.

### `vpetmenu.ino`

Handles the button listener and menu interactions. It updates the pet's expression and score based on button presses and the vape sensor state.

### `vpetevents.ino`

Manages the timed movements of the pet on the LCD screen and adjusts the score periodically. It ensures the score display remains fixed while the pet moves.

## Hardware

- **Arduino UNO R3**
- **LCD Screen** (16x2)
- **Button** (connected to pin 2)
- **Vape Sensor** (connected to pin 3)

## Installation

1. **Wire the hardware:**
   - Connect the LCD screen to the Arduino UNO R3 as follows:
     - RS to pin 0
     - E to pin 1
     - D4 to pin 8
     - D5 to pin 9
     - D6 to pin 10
     - D7 to pin 11
   - Connect the button to pin 2.
   - Connect the vape sensor to pin 3.

2. **Clone the repository:**
   [```bash
  [ git clone <repository_url](https://github.com/taylordanger/VirtualPetVape.git)>](https://github.com/taylordanger/VirtualPetVape)

   Open the project in the Arduino IDE:

Open the vpet.ino file in the Arduino IDE.
Ensure all other files (vpetart.ino, vpetmenu.ino, vpetevents.ino) are in the same directory.
Upload the code to the Arduino:

Select the correct board and port in the Arduino IDE.
Click the upload button to transfer the code to the Arduino.
Usage
Button Press:

When the button is pressed, the display toggles between the home screen and a menu.
On the home screen, the pet's face is shown, and the score is displayed at the top left.
In the menu, you can choose to reset the score or quit.
Vape Sensor:

When the vape sensor is activated, the pet shows a smoke expression, and the score increases.
Score Display:

The score is displayed at the top left of the LCD screen and remains fixed while the pet's face moves.
Functions
vpet.ino
void setup(): Initializes the button and vape sensor pins, and draws the initial pet face.
void loop(): Handles button presses, toggles between screens, updates the pet's expression and score.
vpetart.ino
void drawPet(int expression): Draws the pet's face with the given expression.
void drawEyesAt(int lcdRow, int lcdCol): Draws the pet's eyes at the specified position.
void drawFace(int expression): Draws the pet's face based on the expression.
void drawScoreAt(int lcdRow, int lcdCol, int score): Displays the score at the specified position.
vpetmenu.ino
void buttonPresses(): Handles button press actions and updates the screen accordingly.
void buttonListener(): Listens for button presses and calls the appropriate functions.
void showMenu(): Displays the menu on the screen.
void setPointerTo(int lcdRow, int lcdCol): Sets the cursor to the specified position.
vpetevents.ino
void timePetMovements(unsigned long currentTime): Manages the pet's movements on the screen and reprints the score.
void scoreMove(unsigned long currentTime): Adjusts the pet's movements based on the current time.
License
This project is open-source and available under the MIT License. See the LICENSE file for more information.

Contributing
Contributions are welcome! Please fork the repository and create a pull request with your changes. Ensure your code follows the style and structure of the existing codebase.

Contact
For questions or suggestions, please open an issue in the repository.









