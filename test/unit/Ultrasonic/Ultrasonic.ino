const int trig = 9;
const int echo = 10;

long Time;
int distance;
void setup() {
  Serial.begin(9600);  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  Time = pulseIn(echo, HIGH);
  distance = Time * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
}