int T0;
int T1;
int DTOA;
int thresh = 700;
void setup() {
  Serial.begin(9600);
  pinMode(A15, INPUT); //Back Mic
  pinMode(A14, INPUT); //Front Mic
  pinMode(28, OUTPUT); //Back Led
  pinMode(32, OUTPUT); //Front Led
  pinMode(13, OUTPUT); //On-Board Led
  digitalWrite(28, LOW);
  digitalWrite(32, LOW);
  digitalWrite(13, HIGH);
}
int DTOA_to_Deg(int val) {
  int deg = (val*(-0.75))+90;
  return deg;
}

void loop() {
  int nVal =  analogRead(A14);
  int nVal2 = analogRead(A15);
  Serial.print(nVal); Serial.print(","); Serial.print(nVal2); Serial.print("\n");
  if (nVal >= thresh) {
    T0 = 0;
    T1 = 0;
    Serial.print("T0= "); Serial.print(T0); Serial.print("\n");
    while (nVal2 < thresh) {nVal2 = analogRead(A15); T1 = T1+1;}
    Serial.print("T1= "); Serial.print(T1); Serial.print("\n");
    DTOA = T1 - T0;
    Serial.print("DT0A= "); Serial.print(DTOA); Serial.print("\n");
    int degree = DTOA_to_Deg(DTOA);
    Serial.print("degree= "); Serial.print(degree); Serial.print("\n");
    digitalWrite(13, LOW);
    delay(2000);
    digitalWrite(13, HIGH);
  }
  if (nVal2 >= thresh) {
    T0 = 0;
    T1 = 0;
    Serial.print("T1= "); Serial.print(T1); Serial.print("\n");
    while (nVal < thresh) {nVal =  analogRead(A14); T0 = T0 + 1;}
    Serial.print("T0= "); Serial.print(T0); Serial.print("\n");
    DTOA = T1 - T0;
    Serial.print("DT0A= "); Serial.print(DTOA); Serial.print("\n");
    int degree = DTOA_to_Deg(DTOA);
    Serial.print("degree= "); Serial.print(degree); Serial.print("\n");
    digitalWrite(13, LOW);
    delay(2000);
    digitalWrite(13, HIGH);
  }
  //Serial.print("Pin read: \t"); Serial.print(nVal); Serial.print("\n");
  //Serial.print("Pin read: \t"); Serial.print(nVal2); Serial.print("\n");
}
