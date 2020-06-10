int speakerPin = A0;
int volume = 0;
void setup () {
  pinMode (speakerPin, OUTPUT);
}
void loop () {
  for(volume; volume<255; volume++){
  analogWrite (speakerPin, volume);
  delay (100);
  }
  volume = 0;
}