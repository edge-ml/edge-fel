void setup() {
  Serial.begin(115200);
  delay(100);
  
  long timer;
  long dur;

  for (int i = 0; i < 3; i++){
  int x = 6, y = 7;
  timer = micros();
  int xy = x/y;
  dur = micros() - timer;
  Serial.print(F("Result int: "));
  Serial.print(xy);
  Serial.print(", took: ");
  Serial.print(dur);
  Serial.println(F(" µs"));
  delay(100);

  float a = 1.064567f, b = 0.34654f;
  timer = micros();
  float ab = a/b;
  dur = micros() - timer;
  Serial.print(F("Result float: "));
  Serial.print(ab);
  Serial.print(", took: ");
  Serial.print(dur);
  Serial.println(F(" µs"));
  delay(100);

  double c = 1.064567, d = 0.34654;
  timer = micros();
  double cd  = c/d;
  dur = micros() - timer;
  Serial.print(F("Result double: "));
  Serial.print(cd);
  Serial.print(", took: ");
  Serial.print(dur);
  Serial.println(F(" µs"));
  delay(100);
  }
}

void loop() {
  
  
}
