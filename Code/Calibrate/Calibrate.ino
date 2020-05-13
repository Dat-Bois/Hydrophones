unsigned long times;
int x = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  times = millis();
  x=x+1;
  if (times == 1000){
    Serial.print(x);
    while(true) {
      int dev = 0;
    }
  }
}
