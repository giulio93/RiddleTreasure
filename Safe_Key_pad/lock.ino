void OpenLock(){
    for (;servoPos <= 90; servoPos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(servoPos);              // tell servo to go to position in variable 'pos'
    delay(3);                       // waits 15 ms for the servo to reach the position
  }
}

void CloseLock(){
    for (;servoPos >= 0; servoPos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(servoPos);              // tell servo to go to position in variable 'pos'
    delay(3);                       // waits 15 ms for the servo to reach the position
  }
}

void wrongPassword () {
      buzzer.tone(700, 200);
      delay(200);
      buzzer.tone(440, 200);
      delay(200);
      buzzer.tone(200, 200);
      delay(200);
      buzzer.tone(150, 200);
      delay(200);
}