void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

uint8_t pwm;
void loop() {
  // put your main code here, to run repeatedly:
  pwm += 2;
  Serial.print(pwm);
  Serial.print("\n");
  analogWrite(7,pwm);

  delay(100);

}
