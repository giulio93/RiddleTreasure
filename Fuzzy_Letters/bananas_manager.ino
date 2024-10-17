void Bananas_manager() {
  digitalWrite(GroundTwo, LOW);
  digitalWrite(GroundThree, LOW);
  // a0 = analogRead(A0);
  // a1 = analogRead(A1);
  int d = digitalRead(dodici);
  int u = digitalRead(unidici);

  if (d == LOW) {
    a0_sync++;
    if (a0_sync > 3) {
      CONTROL1 = 0;
    }
  } else {
    a0_sync = 0;
    CONTROL1 = 200;
  }
  if (u == LOW) {
    a1_sync++;
    if (a1_sync > 3) {
      CONTROL2 = 0;
    }
  } else {
    a1_sync = 0;
    CONTROL2 = 200;
  }


  // if (a0 > 1000) {
  //   a0_sync++;
  //   if (a0_sync > 3) {
  //     CONTROL1 = 0;
  //   }
  // } else if (a0 < 1000) {
  //   a0_sync = 0;
  //   CONTROL1 = 200;
  // }
  // if (a1 > 1000) {
  //   a1_sync++;
  //   if (a1_sync > 3) {
  //     CONTROL2 = 0;
  //   }
  // } else if (a1 < 1000) {
  //   a1_sync = 0;
  //   CONTROL2 = 200;
  // }
  delay(1);
  // Serial.print("d: ");
  // Serial.println(d);
  // Serial.print("u: ");
  // Serial.println(u);


  //debug_b();
}


void debug_b() {
  // Serial.print("a0: ");
  // Serial.println(a0);
  // Serial.print("a1: ");
  // Serial.println(a1);
  // Serial.print("CONTROL1: ");
  // Serial.println(CONTROL1);
  // Serial.print("CONTROL2: ");
  // Serial.println(CONTROL2);
}