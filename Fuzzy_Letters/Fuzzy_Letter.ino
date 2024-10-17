// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include "letters.h"
#include "right_arrow.h"
#include "left_arrow.h"
#include <Scheduler.h>


ArduinoLEDMatrix matrix;
int GroundTwo = 2;
int GroundThree = 3;

int dodici = 12;
int unidici = 11;
// int d, u;

int analogPin = 0;
int analogPinOne = 1;

int a0 = 0;
int a0_sync = 0;
int a1 = 0;
int a1_sync = 0;



int CONTROL1 = 200;
int CONTROL2 = 200;

uint32_t mask[3] = { 0x0, 0x0, 0x0 };
uint32_t frame[3] = { 0x0, 0x0, 0x0 };
char codeToDraw[9] = { "XXXXXXXX" };
char codeToWrite[7] = { "XXXXXX" };



int masker = 255;
int count = 0;

uint32_t sad[] = { 0x19819, 0x80000007, 0xfe606000 };


enum riddleEvent { idle,
                   start,
                   bananas,
                   pwd,
                   win,
                   lose };

riddleEvent state;
riddleEvent state_sender;
riddleEvent prev_state;



void setup() {
  prev_state = idle;
  //state = bananas;
  matrix.begin();

  pinMode(GroundTwo, OUTPUT);
  pinMode(GroundThree, OUTPUT);

  pinMode(dodici, INPUT_PULLUP);
  pinMode(unidici, INPUT_PULLUP);

  Serial1.begin(9600);
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  //Start Serial receiver
  Scheduler.startLoop(Serial1_receiver);

  //Start Serial sender
  Scheduler.startLoop(Serial1_sender);

  //Start Serial receiver
  Scheduler.startLoop(Bananas_manager);


  //Initialize the sequence
  // 0 1 2 A B C right Matrix
  // 3 4 5 A B C left Matrix
}

void loop() {




  if (state == idle) {
    generateRandomCode(codeToDraw, codeToWrite);
    Serial1.flush();
    state_sender = idle;
    palywithMe();
  }
  if (state == start) {
    state_sender = start;
    leftArrow();
  }

  if (state == lose) {
    state_sender = lose;
    youLose();
  }

  if (state == win) {
    state_sender = win;
    youWin();
  }

  if (state == bananas) {
    if ((CONTROL1 == 0) && (CONTROL2 == 0)) {
      state_sender = pwd;
      showPassoword();
      rightArrow();
    } else {
      state_sender = bananas;
      matrix.loadFrame(sad);
    }
  }
  delay(1);
}


void generateRandomCode(char codeToDraw[], char codeToWrite[]) {
  char letters[] = { "ABC" };

  for (int i = 0; i < 6; i++) {
    codeToWrite[i] = letters[random(3)];  // Random letters A-C
  }

  strcpy(codeToDraw, codeToWrite);
  strcat(codeToDraw, "00");

  Serial.println(codeToDraw);
  Serial.println(codeToWrite);
}
