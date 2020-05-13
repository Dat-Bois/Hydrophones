
void setup() {
  Serial.begin(9600);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);
  pinMode(A16, INPUT);
}

void loop() {
  int nVal =  analogRead(A16);
  int nVal2 = analogRead(A15);
  int nVal3 = analogRead(A14);
  Serial.print(nVal); Serial.print(","); Serial.print(nVal2); Serial.print(","); Serial.print(nVal3); Serial.print("\n");
}
