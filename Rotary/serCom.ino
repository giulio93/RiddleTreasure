
void Serial1_sender() {
  if (prev_state != state) {
    Serial1.write(state);
    Serial.print("write => ");
    Serial.println(state);
    prev_state = state;
  }
  delay(1);
}

void Serial1_receiver() {
  if (Serial1.available() > 0) {
    int data = Serial1.read();
    riddleEvent currentEvent = (riddleEvent)data;  // Cast int to riddleEvent
    Serial.print("read => ");
    Serial.println(data);
    if (currentEvent == win) {
      reader_state = currentEvent;
    }
  }
  // Serial.print("read => ");
  // Serial.println(data);

  delay(1);
  //Serial.println(state);
}