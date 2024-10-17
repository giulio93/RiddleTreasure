#include <Scheduler.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include "right.h"
#include "left.h"
#include "Modulino.h"
#include "right_arrow.h"

ArduinoLEDMatrix matrix;
ModulinoKnob encoder;
ModulinoPixels leds;
ModulinoBuzzer buzzer;
ModulinoColor OFF(0, 0, 0);


int timer = 99;
int led = 0;
int count = 0;
int newLed = 0;


enum riddleEvent { idle,start,
                   bananas,
                   pwd,
                   win,
                   lose };

riddleEvent state;
riddleEvent prev_state;
riddleEvent reader_state;


//int LedBrigh[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
int LedBrigh[8] = { 12, 24, 12, 22, 5, 13, 25, -1 };
//int LedSucc[8]= {25,37,10,25,15,3,33,12};
int LedSucc[8] = { 12, 24, 12, 22, 5, 13, 25, 7 };
int LedWinns[8] = { 100, 90, 80, 70, 40, 50, 30, 20 };



void setup() {
  
  state = idle;
  reader_state = idle;
  prev_state = win;


  Modulino.begin();
  encoder.begin();
  leds.begin();
  buzzer.begin();
  //Initialize Led Matrix
  matrix.begin();
  //Init LEDs Modulino
  //initializeLEDs();
  // Start the timer task
  Scheduler.startLoop(Countdown_99);
  //Start Serial sender
  Scheduler.startLoop(Serial1_sender);
  //Start Serial receiver
  Scheduler.startLoop(Serial1_receiver);


  Serial1.begin(9600);
  Serial.begin(9600);

}

void loop() {
  //DEBUG
  if(millis() % 100 == 0){
    LedBrigh[7] = 7;
    delay(1);
  }
  
  Serial.println(state);

  bool click = encoder.isPressed();
  if(click && state == idle){
    state = start;
    initializeLEDs();
  }

  if (state == idle) {
    randomLed();
  }

  if (state == start) {
    updateLEDs();
  }


  if (timer < 0 && reader_state != win) {
    state = lose;
    looseLeds();
  }

  int value = encoder.get() % 100;
  if (value < 0) {
    encoder.set(0);
  }

  //ENABLE FOR DEBUG
  // Serial.print("encoder ==>");
  // Serial.println(value);

  //If you match the rigth value
  if ((value == LedSucc[led]) && state == start) {
    matchLed(value);
    //If you are near to the right value
  } else if ((value < LedSucc[led] + 10 && value > LedSucc[led] - 10) && state == start) {

    nearLed(led);
  }
  //render on modulino led
  leds.show();
  yield();
}
