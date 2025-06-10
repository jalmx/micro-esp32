#define LED_1 33
#define LED_2 15
#define LED_3 32
#define LED_4 2
#define LED_5 4

void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_4, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_1, LOW);    // turn the LED off by making the voltage LOW]
  digitalWrite(LED_2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LED_3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LED_4, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LED_5, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

}
