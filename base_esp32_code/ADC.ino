#define ADC1 34
#define ADC2 35

#define LED
void setup() {
  // declare the ledPin as an OUTPUT:
Serial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  Serial.print("ADC1: ");
  Serial.print(ADC1);
  Serial.print(": ");
  Serial.println(analogRead(ADC1));
    Serial.print("ADC2: ");
  Serial.print(ADC2);
  Serial.print(": ");
  Serial.println(analogRead(ADC2));

  delay(1000);
}
