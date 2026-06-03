#include <Arduino.h>

#define LED_1 27
#define LED_2 26
#define LED_3 25
#define LED_4 33
#define LED_5 32
#define BUZZER 14

#define BTN_1 34
#define BTN_2 35

void led1();

void led1(){
  digitalWrite(LED_1, HIGH);
  delay(250);
  digitalWrite(LED_1, LOW);
  delay(250);
}

const int ledPins[] = {LED_1, LED_2, LED_3, LED_4, LED_5};
const int btnPins[] = {BTN_1, BTN_2};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
const int numBtns = sizeof(btnPins) / sizeof(btnPins[0]);

// Configuración del canal PWM para el Buzzer en ESP32
const int buzzerChannel = 0;
const int resolution = 8;

void setup()
{
  Serial.begin(115200);
  Serial.println("Sistema de Luces y Sonido Iniciado...");

  // Configurar LEDs como salidas
  for (int i = 0; i < numLeds; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  // Configurar botones (Recuerda usar resistencias de pull-down externas en GPIO 34 y 35)
  for (int i = 0; i < numBtns; i++)
  {
    pinMode(btnPins[i], INPUT);
  }

  // Configurar el PWM para el buzzer en el ESP32
  // Nota: ledcSetup y ledcAttachPin se usan en el core de ESP32 para manejar tonos
  ledcSetup(buzzerChannel, 2000, resolution);
  ledcAttachPin(BUZZER, buzzerChannel);
  ledcWriteTone(buzzerChannel, 0); // Silencio inicial
}

// Función para apagar todos los LEDs rápidamente
void apagarLeds() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void loop()
{
  // Leer botones
  bool btn1 = digitalRead(BTN_1);
  bool btn2 = digitalRead(BTN_2);

  if (btn1 && btn2)
  {
    Serial.println("¡AMBOS BOTONES PULSADOS! Modo Caos activado...");

    // Efecto de sonido tipo glitch de computadora/caótico
    for (int i = 0; i < 10; i++) {
      int freqAleatoria = random(800, 3000); // Frecuencias altas aleatorias
      ledcWriteTone(buzzerChannel, freqAleatoria);

      // Encender un LED aleatorio y apagar los demás (Efecto estrobo)
      apagarLeds();
      digitalWrite(ledPins[random(0, numLeds)], HIGH);

      delay(60); // Ritmo muy rápido
    }

    ledcWriteTone(buzzerChannel, 0);
    apagarLeds();
  }else if (btn1)
  {
    Serial.println("Ejecutando: Efecto Sirena...");

    // Ciclo 1: Subiendo tono y encendiendo LEDs uno a uno
    for (int i = 0; i < numLeds; i++)
    {
      digitalWrite(ledPins[i], HIGH);
      ledcWriteTone(buzzerChannel, 600 + (i * 150)); // Tonos de 600Hz a 1200Hz
      delay(150);
      digitalWrite(ledPins[i], LOW);
    }

    // Ciclo 2: Bajando tono y regresando los LEDs
    for (int i = numLeds - 1; i >= 0; i--)
    {
      digitalWrite(ledPins[i], HIGH);
      ledcWriteTone(buzzerChannel, 1200 - ((numLeds - 1 - i) * 150));
      delay(150);
      digitalWrite(ledPins[i], LOW);
    }

    ledcWriteTone(buzzerChannel, 0); // Apagar sonido al terminar
  }
  else if (btn2)
  {
    Serial.println("Ejecutando: Efecto Arpegio Ascendente...");

    // Las frecuencias corresponden a las notas: Do, Mi, Sol, Do (Agudo), Mi (Agudo)
    int notas[] = {262, 330, 392, 523, 659};

    // Van encendiendo y se quedan encendidos acumulativamente
    for (int i = 0; i < numLeds; i++)
    {
      digitalWrite(ledPins[i], HIGH);
      ledcWriteTone(buzzerChannel, notas[i]);
      delay(200);
    }

    // Un destello final con el tono más agudo
    ledcWriteTone(buzzerChannel, 880); // Nota La (Aguda)
    delay(300);

    ledcWriteTone(buzzerChannel, 0); // Apagar sonido
    apagarLeds();                    // Apagar luces
    delay(200);
  }
  else
  {
    // Si no se presiona nada, nos aseguramos de que todo esté apagado y en silencio
    ledcWriteTone(buzzerChannel, 0);
    apagarLeds();
    led1(); // Pequeño destello para indicar que el sistema está activo
    delay(50); // Pequeña pausa para estabilidad
  }
}