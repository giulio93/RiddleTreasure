void showPassoword() {
  masker = 0;
  for (int k = 0; k < 8;) {
    Mask(masker % 27584930445, mask);
    setMask(&code[k], &code[k + 1], frame, mask);
    k = k + 2;
    matrix.loadFrame(frame);
    delay(800);
  }
}

void youLose() {

  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(75);
  const char text[] = "TIME IS UP!";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
  yield();
}

void youWin() {
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(75);
  const char text[] = "OPEN!!";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
}
void palywithMe() {
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(75);
  const char text[] = "PLAY WITH ME!";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
}

void leftArrow() {
  int k = 4;
  while (k >= 0) {
    matrix.loadFrame(left_arrow[k]);
    delay(150);
    k--;
  }
}
void rightArrow() {
  int k = 0;
  while (k <= 4) {
    matrix.loadFrame(right_arrow[k]);
    delay(150);
    k++;
  }
}

void mergeMask(const uint32_t* leftN, const uint32_t* rightN, uint32_t* frame, uint32_t* mask) {
  frame[0] = leftN[0] | mask[0] | rightN[0];
  frame[1] = leftN[1] | mask[1] | rightN[1];
  frame[2] = leftN[2] | mask[2] | rightN[2];
}


void setMask(char* left, char* right, uint32_t* frame, uint32_t* mask) {

  int i = 0;
  int j = 0;
  switch (*left) {
    case 'A':
      i = 0;
      break;
    case 'B':
      i = 1;
      break;
    case 'C':
      i = 2;
      break;
    case '0':
      i = 6;
      break;
  }
  switch (*right) {
    case 'A':
      j = 3;
      break;
    case 'B':
      j = 4;
      break;
    case 'C':
      j = 5;
      break;
    case '0':
      j = 7;
      break;
  }

  mergeMask(letters[i], letters[j], frame, mask);
}


// Function to split the integer into three 32-bit unsigned integers
void Mask(int value, uint32_t array[3]) {
  // Mask and shift to split the integer
  array[0] = (uint32_t)(value & 0xFFFFFFFF);          // Lower 32 bits
  array[1] = (uint32_t)((value >> 32) & 0xFFFFFFFF);  // Middle 32 bits
  array[2] = (uint32_t)((value >> 64) & 0xFFFFFFFF);  // Upper 32 bits (if necessary)
}
