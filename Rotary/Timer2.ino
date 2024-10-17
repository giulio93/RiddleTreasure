const uint32_t questionmark[] = {
  0x79e49269,
  0xa08230c2,
  0x8000208
};

void Countdown_99() {
  if (timer >= 0 && state != idle && reader_state != win) {
    uint32_t frame[3] = { 0x0, 0x0, 0x0 };
    setNumber(timer, frame);
    matrix.loadFrame(frame);
    delay(1000);
    timer = timer - 1;
    if (state == bananas) {
      playArrow();
    }
  } else {
    if (state != idle && reader_state != win) {
      state = lose;
      youLose();
    }
    if (state == idle) {
      palywithMe();
    }
  }

  if (state != idle && reader_state == win) {
    state = win;
    youWin();
  }

  delay(1);
}


//Set the left and right number on the ledMatrix
void setNumber(uint8_t i, uint32_t *frame) {
  mergeMatrix(leftMatrix[i / 10], rightMatrix[i % 10], frame);
}

//Led Matrix OR between 1:: and ::1
void mergeMatrix(const uint32_t *leftN, const uint32_t *rightN, uint32_t *frame) {
  frame[0] = leftN[0] | rightN[0];
  frame[1] = leftN[1] | rightN[1];
  frame[2] = leftN[2] | rightN[2];
}
