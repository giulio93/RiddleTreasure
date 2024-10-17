void Serial1_receiver() {
  if (Serial1.available() > 0) {
    int data = Serial1.read();
    riddleEvent currentEvent = (riddleEvent)data;  // Cast int to riddleEvent
    state = currentEvent;
    Serial.print("read => ");
    Serial.println(state);
    if (state == start) {
      //char codeToWrite[] = { "ABBCCA" };
      String i = Serial1.readString();
      Serial.print("read => ");
      Serial.println(i);
      code = i;
    }
  }
  delay(1);
}

void Serial1_sender() {
  if (prev_state != state_sender) {
    Serial1.write(state_sender);
    Serial.print("write => ");
    Serial.println(state_sender);
    prev_state = state_sender;
  }
  delay(1);
}
