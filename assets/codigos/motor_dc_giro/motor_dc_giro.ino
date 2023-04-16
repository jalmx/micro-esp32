//Configuro los pines fisicos para las entradas y salidas
const byte LED_I = 25;
const byte LED_D = 26;
const byte MOTOR_1 = 18;
const byte MOTOR_2 = 19;
const byte BTN_D = 34;
const byte BTN_I = 35;

void setup() {
  // configurando los pines como entradas y salidas
  pinMode(LED_I, OUTPUT);
  pinMode(LED_O, OUTPUT);
  pinMode(MOTOR_I, OUTPUT);
  pinMode(MOTOR_D, OUTPUT);
  pinMode(BTN_I, INPUT);
  pinMode(BTN_D, INPUT);
}

void loop() {

  if (digitalRead(BTN_I) == 1) {
    delay(100);
    // Motor
    digitalWrite(MOTOR_I, HIGH);
    digitalWrite(MOTOR_D, LOW);
    //Leds
    digitalWrite(LED_I,HIGH);
    digitalWrite(LED_D,LOW);
  } else if (digitalRead(BTN_D) == 1) {
    delay(100);
    // Motor
    digitalWrite(MOTOR_I, LOW);
    digitalWrite(MOTOR_D, HIGH);
    //Leds
    digitalWrite(LED_I,LOW);
    digitalWrite(LED_D,HIGH);
  } else {
     // Motor apagado
    digitalWrite(MOTOR_I, LOW);
    digitalWrite(MOTOR_D, LOW);
    //Hago un blink con los leds
    //Leds
    digitalWrite(LED_I,LOW);
    digitalWrite(LED_D,LOW);
    delay(250);    
    digitalWrite(LED_I,HIGH);
    digitalWrite(LED_D,HIGH);
    delay(250);
  }
}