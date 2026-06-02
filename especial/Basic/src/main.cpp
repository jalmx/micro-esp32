#include <Arduino.h>

#define LED_1 27
#define LED_2 26
#define LED_3 25
#define LED_4 33
#define LED_5 32
#define BUZZER 14

#define BTN_1 34
#define BTN_2 35

#define TIME 500

const int ledPins[] = {LED_1, LED_2, LED_3, LED_4, LED_5};
const int btnPins[] = {BTN_1, BTN_2};

void setup()
{
  // configuuramos las salidas de los leds y el buzzer
  for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(BUZZER, OUTPUT);

  // configuramos las entradas de los botones
  for (int i = 0; i < sizeof(btnPins) / sizeof(btnPins[0]); i++)
  {
    pinMode(btnPins[i], INPUT);
  }

  // apagamos los leds y el buzzer al inicio
  for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++)
  {
    digitalWrite(ledPins[i], LOW);
  }
  digitalWrite(BUZZER, LOW);
}

void loop()
{

  if (digitalRead(BTN_1))
  {
    for (int i = 0; i < sizeof(btnPins) / sizeof(btnPins[0]); i++)
    {
      digitalWrite(ledPins[i], HIGH);
      delay(TIME);
    }
    for (int i = 0; i < sizeof(btnPins) / sizeof(btnPins[0]); i++)
    {
      digitalWrite(ledPins[i], LOW);
      delay(TIME);
    }
  }
  else if (digitalRead(BTN_2))
  {
    for (int i = 0; i < sizeof(btnPins) / sizeof(btnPins[0]); i++)
    {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(TIME);
    for (int i = 0; i < sizeof(btnPins) / sizeof(btnPins[0]); i++)
    {
      digitalWrite(ledPins[i], LOW);
    }
    delay(TIME);
  }
  else
  {
    for (int i = 0; i < sizeof(btnPins) / sizeof(btnPins[0]); i++)
    {
      digitalWrite(ledPins[i], i % 2 ? HIGH : LOW);
      delay(TIME);
    }
  }
}
