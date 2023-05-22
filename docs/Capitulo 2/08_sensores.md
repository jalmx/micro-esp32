# Sensores - Aplicación

## Sensores digitales

Usaremos diversos sensores para controlar distintos elementos.

## Teclado 4x4

<!-- https://esp32io.com/tutorials/esp32-keypad -->

## Sensor PIR HC-SR501 (Sensor de presencia)

![pir](../assets/schematic/pir_basic_bb.png)

![pir basic](../assets/videos/PIR_basic.gif)

**Código**

```C
#define PIR 34 //defino el pin para el sensor PIR
#define LED 25 //defino el pin para el LED

void setup() {
  Serial.begin(115200);
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  if(digitalRead(PIR) == 1){
    digitalWrite(LED, HIGH);
    Serial.println("Hay presencia");
    delay(1000);
  }else{
    digitalWrite(LED, LOW);
  }
  delay(10);
}

```

## Sensor de Temperatura y Humedad DTH11

!!! Warning Lib
    Se deben agregar una librerías para usar este sensor. [Click aquí](../assets/libs/Pack_DTHxx.zip), agregarlas a tu IDE, de lo contrario no funcionara el código de ejemplo.


![dht](../assets/schematic/dht11_bb.png)

![dht11 anima](../assets/videos/DHT11.gif)

```C
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2     // El pin que se usara para comunicar al sensor con el micro

#define DHTTYPE    DHT11   // se define que sensor se usara (tenemos el DHT22, FHT21)

DHT_Unified dht(DHTPIN, DHTTYPE); // Se crea el objeto con los valores indicados para que se configure el sensor a usar

uint32_t delayMS;

void setup() {
  Serial.begin(115200);
  // Initialize device.
  dht.begin(); //inicializamos al sensor
  Serial.println(F("Sensor DHT11"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Tipo: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Valor Max:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Valor Min:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
```

## Sensor Ultrasónico HC-SR04

**Instalación de la librería**

![newping lib](../assets/newping_download.png)

### Distancia con sensor Ultrasónico

![ultrasonico anima](../assets/videos/ultrasonico.gif)

```C
#include <NewPing.h>

#define TRIGGER_PIN  4  // Pin que se usara para el TRIGGER que recibe el sensor
#define ECHO_PIN     2  // Pin que se usara el el ECHO que enviara el sensor
#define MAX_DISTANCE 400 // Distancia maxima que puede medir el sensor

NewPing ultrasonico(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Se configura el objeto del sensor que usara los datos

void setup() {
  Serial.begin(115200);
}

float duracion, distancia;

void loop() {

  duracion = ultrasonico.ping();

  distancia = (duracion / 2) * 0.0343;
  Serial.print("Distancia: ");

  if (distancia >= 400 || distancia <= 2) {
    Serial.println("Fuera de rango");
  } else {
    Serial.print(distancia);
    Serial.println(" cm");
    delay(500);
  }

  delay(500);
}
```

### Barra de leds con Ultrasonico

![utra bar](../assets/videos/ultrasonico_barra.gif)

```C
#include <NewPing.h>

#define TRIGGER_PIN  4  // Pin que se usara para el TRIGGER que recibe el sensor
#define ECHO_PIN     2  // Pin que se usara el el ECHO que enviara el sensor
#define MAX_DISTANCE 400 // Distancia maxima que puede medir el sensor

NewPing ultrasonico(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Se configura el objeto del sensor que usara los datos

#define NO_LEDS 7
const int PINS[] = {32, 33, 25, 26, 27, 12, 14}; //pines para leds


void setup() {
  Serial.begin(115200);
  for (char x = 0; x < NO_LEDS; x++) {
    pinMode(PINS[x], OUTPUT);
  }
}

void loop() {

  float distancia = (ultrasonico.ping() / 2) * 0.0343;
  Serial.print("Distancia: ");

  if (distancia >= 400 || distancia <= 2) {
    Serial.println("Fuera de rango");

    for (char x = 0; x < NO_LEDS; x++) {
      digitalWrite(PINS[x], HIGH);
    }
    delay(250);
    for (char x = 0; x < NO_LEDS; x++) {
      digitalWrite(PINS[x], LOW);
    }
    delay(250);

  } else {
    Serial.print(distancia);
    Serial.println(" cm");

    if (distancia < 50) {
      const int LEVEL = 1;

      for (char x = 0; x < LEVEL; x++) {
        digitalWrite(PINS[x], HIGH);
      }
      delay(100);
      for (char x = LEVEL; x < NO_LEDS; x++) {
        digitalWrite(PINS[x], LOW);
      }
    } else if (distancia >= 50 && distancia < 100) {
      const int LEVEL = 2;

      for (char x = 0; x < LEVEL; x++) {
        digitalWrite(PINS[x], HIGH);
      }
      delay(100);
      for (char x = LEVEL; x < NO_LEDS; x++) {
        digitalWrite(PINS[x], LOW);
      }
    } else if (distancia >= 100 && distancia < 150) {
      const int LEVEL = 3;

      for (char x = 0; x < LEVEL; x++) {
        digitalWrite(PINS[x], HIGH);
      }
      delay(100);
      for (char x = LEVEL; x < NO_LEDS; x++) {
        digitalWrite(PINS[x], LOW);
      }
    } else if (distancia >= 150 && distancia < 200) {
      const int LEVEL = 4;

      for (char x = 0; x < LEVEL; x++) {
        digitalWrite(PINS[x], HIGH);
      }
      delay(100);
      for (char x = LEVEL; x < NO_LEDS; x++) {
        digitalWrite(PINS[x], LOW);
      }
    } else if (distancia >= 200 && distancia < 250) {
      const int LEVEL = 5;

      for (char x = 0; x < LEVEL; x++) {
        digitalWrite(PINS[x], HIGH);
      }
      delay(100);
      for (char x = LEVEL; x < NO_LEDS; x++) {
        digitalWrite(PINS[x], LOW);
      }
    } else if (distancia >= 250 && distancia < 300) {
      const int LEVEL = 6;

      for (char x = 0; x < LEVEL; x++) {
        digitalWrite(PINS[x], HIGH);
      }
      delay(100);
      for (char x = LEVEL; x < NO_LEDS; x++) {
        digitalWrite(PINS[x], LOW);
      }
    } else {
      const int LEVEL = 7;

      for (char x = 0; x < LEVEL; x++) {
        digitalWrite(PINS[x], HIGH);
      }
      delay(100);
      for (char x = LEVEL; x < NO_LEDS; x++) {
        digitalWrite(PINS[x], LOW);
      }
    }
    delay(500);
  }

  delay(10);
}
```

## Sensor DS18B - Sensor de temperatura

## Sensor de Sonido

## Sensor de humedad de tierra

