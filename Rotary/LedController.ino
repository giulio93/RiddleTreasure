//Inizialize all the modulino LED to Red
void initializeLEDs() {
  for (int i = 0; i < 8; i++) {
    leds.set(i, GREEN, 10);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    leds.set(i, RED, 10);
    buzzer.tone(100 * i, 100);
    leds.show();
    delay(500);
  }
}

void updateLEDs() {
  for (int i = 0; i < 8; i++) {
    if (LedBrigh[i] == -1) {
      leds.set(i, RED, 10);
      //If at least one led is RED stay
      state = start;
    } else {
      leds.set(i, GREEN, LedBrigh[i]);
      //IFFall leds are green go next
      state = bananas;
    }
    leds.show();
  }
}

void randomLed() {
  for (int i = 0; i < 8; i++) {
    if (i == 0 || i == 1) {
      setPixel(i, RED);
    } else if (i == 2 || i == 3) {
      setPixel(i, BLUE);
    } else if (i == 4 || i == 5) {
      setPixel(i, GREEN);
    } else if (i == 6 || i == 7) {
      setPixel(i, VIOLET);
    } else if (i == 7 || i == 8) {
      setPixel(i, WHITE);
    }
    delay(25);
  }

  for (int i = 0; i < 8; i++) {
    setPixel(i, OFF);
    delay(25);
  }
}

void matchLed(int value) {
  LedBrigh[led] = value;
  buzzer.tone(700, 200);
  delay(200);
  buzzer.tone(440, 200);
  delay(200);
  newLed = (led + 1) % 8;
  leds.set(newLed, BLUE, 10);
  leds.clear(led);
  leds.show();
  count = 0;
  led = newLed;
  delay(500);
}

void nearLed(int leddone) {
  buzzer.tone(300, 200);
  leds.set(leddone, GREEN, 10);
  leds.clear(led);
  leds.show();
  delay(100);
  buzzer.tone(200, 200);
  leds.set(leddone, RED, 10);
  leds.clear(led);
  leds.show();
}

void winLEDs() {

  for (int i = 0; i < 8; i++) {
    leds.set(i, BLUE, 0);
    leds.show();
    buzzer.tone(200 + LedWinns[i], 100);
    delay(500);
  }
}

void looseLeds() {
  for (int i = 0; i < 8; i++) {
    leds.set(i, VIOLET, 100);
    leds.show();
    buzzer.tone(200 + (100 - LedWinns[i]), 100);
    delay(500);
  }
}

void setPixel(int pixel, ModulinoColor color) {
  leds.set(pixel, color, 10);
  leds.show();
}
