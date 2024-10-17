const uint32_t questionmark[] = {
		0x79e49269,
		0xa08230c2,
		0x8000208
	};

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
  //delay(5000);
}

void leftArrow() {
  int k = 4;
  while (k >= 0) {
    matrix.loadFrame(left_arrow[k]);
    delay(150);
    k--;
  }
}
// void rightArrow() {
//   int k = 0;
//   while (k > 4) {
//     matrix.loadFrame(right_arrow[k]);
//     delay(150);
//     k++;
//   }
// }

void pwdPlease() {
  matrix.beginDraw();

  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);
  // add the text
  const char text[] = "PASSWORD PLEASE!!";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
  matrix.loadFrame(questionmark);
  //delay(1);
  yield();
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
