#include <Servo.h>
#include "Modulino.h"
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include <Scheduler.h>
#include "left_arrow.h"
#include <BleValueSync.h>

#define BLE_SYNC



int ServoPWMPin = 9;
int servoPos = 0;
char code[] = { "ABBCCA" };
char passkey[] = { "XXXXXX" };
int nextLetter = 0;

bool updateCounter = false;

Servo myservo;
ArduinoLEDMatrix matrix;
ModulinoBuzzer buzzer;
ModulinoButtons buttons;

enum riddleEvent { idle,
                   start,
                   bananas,
                   pwd,
                   win,
                   lose };

riddleEvent state;
riddleEvent state_sender;
riddleEvent prev_state;

#ifdef BLE_SYNC
/* BT Service and properties */
BleSync ble("RiddleTreasure", "b4d290a9-17e2-415a-88d7-441857d1caaa", 1);
BleSyncValue bleOpen("3b46051b-2b10-4202-8ce3-fe454098151c", BLERead | BLEWrite);
#endif



void setup() {
  prev_state = idle;
  Modulino.begin();
  buzzer.begin();
  buttons.begin();

  myservo.attach(ServoPWMPin);
  Serial.begin(9600);
  Serial1.begin(9600);

  matrix.begin();
  // Start the timer task
  myservo.write(0);
  //Close the door
  if (servoPos != 0) {
    CloseLock();
  }

  // Start the drawer task
  Scheduler.startLoop(drawer);

  // Start the Serial1 task
  Scheduler.startLoop(Serial1_receiver);
  // Start the Serial1 task
  Scheduler.startLoop(Serial1_sender);

#ifdef BLE_SYNC
  ble.addValue(&bleOpen);
  ble.initBLE();
#endif
}

void loop() {

  if (state == idle) {
    state_sender = idle;
    updateCounter = false;
    resetPassword();
    nextLetter =0;
  }

  if (state == pwd && state_sender != win) {
    inputPassword();
  }

  if (String(passkey) == String(code)) {
    if (state != lose) {
      state_sender = win;
      OpenLock();
      delay(1);
      if (updateCounter == false) {
        updateCounter = true;
        send_data_to_cloud();
      }
    }
  }

  delay(1);

  // Serial.print("passkey ==> ");
  // Serial.println(passkey);
}

void resetPassword() {
  for (int n = 0; n < 6; n++) {
    passkey[n] = 'X';
  }
}

void inputPassword() {
  if (buttons.update()) {
    if (buttons.isPressed(0)) {
      passkey[nextLetter] = 'A';
      nextLetter++;
    }
    if (buttons.isPressed(1)) {
      passkey[nextLetter] = 'B';
      nextLetter++;
    }
    if (buttons.isPressed(2)) {
      passkey[nextLetter] = 'C';
      nextLetter++;
    }
    if (nextLetter > 5 && !(String(passkey) == String(code))) {
      nextLetter = 0;
      wrongPassword();
      for (int n = 0; n < 6; n++) {
        passkey[n] = 'X';
      }
    }
  }
}
