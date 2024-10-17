void Serial1_receiver() {

  if (Serial1.available() > 0) {
    int data = Serial1.read();
    riddleEvent currentEvent = (riddleEvent)data;  // Cast int to riddleEvent
    state = currentEvent;
  }
  // Serial.print("read => ");
  // Serial.println(state_sender);
  delay(1);
}

void Serial1_sender() {
  if (prev_state != state_sender) {
    Serial1.write(state_sender);
    Serial.print("write => ");
    Serial.println(state_sender);
    delay(1);
    prev_state = state_sender;
    if (state_sender == start) {
      Serial1.write(codeToWrite);
      Serial.print("code => ");
      Serial.println(codeToWrite);
    }
  }

  delay(1);
}
