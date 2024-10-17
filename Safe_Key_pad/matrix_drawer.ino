void drawer() {

  if (state == idle && state_sender != win) {
    if (servoPos != 0) {
      CloseLock();
    }
    palywithMe();
  }

  if (state == lose) {
    youLose();
  }

  if (state_sender == win && state != lose) {
    youWin();
  } else {
    if (state == start || state == bananas) {
      leftArrow();
    }
    if (state == pwd) {
      pwdPlease();
    }
  }

  delay(1);
}

//   if (defeat == LOW && password == false){

//       for (int j=4; j>=0; j--){
//         matrix.loadFrame(left_animation[j]);
//         delay(500);
//       }

//   }

//   if (defeat == HIGH && password == false){
//       // Make it scroll!
//     matrix.beginDraw();

//     matrix.stroke(0xFFFFFFFF);
//     matrix.textScrollSpeed(50);

//     // add the text
//     const char text[] = "PASSWORD PLEASE!!";
//     matrix.textFont(Font_5x7);
//     matrix.beginText(0, 1, 0xFFFFFF);
//     matrix.println(text);
//     matrix.endText(SCROLL_LEFT);
//     matrix.endDraw();
//     matrix.loadFrame(questionmark);
//     delay(500);
//     yield();

//   }
//   if (boom == true){

//     matrix.beginDraw();

//     matrix.stroke(0xFFFFFFFF);
//     matrix.textScrollSpeed(75);

//     // add the text
//     const char text[] = "BBBBBOOOOM YOU LOOOOSE!";
//     matrix.textFont(Font_5x7);
//     matrix.beginText(0, 1, 0xFFFFFF);
//     matrix.println(text);
//     matrix.endText(SCROLL_LEFT);

//     matrix.endDraw();
//     delay(5000);


//   }

//   if (password == true && boom == false){
//     matrix.beginDraw();
//     matrix.stroke(0xFFFFFFFF);
//     matrix.textScrollSpeed(75);
//     const char text[] = "YOU WIN!";
//     matrix.textFont(Font_5x7);
//     matrix.beginText(0, 1, 0xFFFFFF);
//     matrix.println(text);
//     matrix.endText(SCROLL_LEFT);
//     matrix.endDraw();
//     delay(5000);
//   }

// }
