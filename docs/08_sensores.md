# Sensores - Aplicación

## Sensores digitales

Usaremos diversos sensores para controlar distintos elementos.

## Teclado matricial 4x4

!!! Note Instalar la librería
    En ocasiones NO se encuentra la librería en el IDE, puedes instalarla desde el "Gestor de bibliotecas"
    
    ![keypad](./assets/keypad_install.png)


!!! Note Instalación manual de librería
    De otra forma, puedes descarga la librería y realizar la instalación manual. [Dar click aquí](./assets/libs/Keypad-3.1.1.zip)

Aquí vamos a probar el correcto conexionado y funcionamiento del teclado, imprimiendo por monitor serial la tecla presionada.

**Diagrama pictórico**

![](./assets/schematic/keypad_basic.png)

**Código**

```C
#include <Keypad.h> // importamos la librería para utilizar el teclado

#define ROW_NUM     4 // indicamos el numero de renglones del teclado
#define COLUMN_NUM  4 // indicamos el numero de columnas del teclado

char keys[ROW_NUM][COLUMN_NUM] = { // indicamos las letras que tiene el teclado, estas se pueden cambiar
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM]      = {19, 18, 5, 17}; // indicamos los pines que se usaran para los renglones
byte pin_column[COLUMN_NUM] = {16, 4, 0, 2};   // indicamos los pines que se usaran para las columnas

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM ); // se crea y configura el objeto para el uso del teclado

void setup() {
  Serial.begin(115200);
}

void loop() {
  char key = keypad.getKey(); // esperemos la tecla que se presiono

  if (key) { // si presionaron una tecla, entra al bloque del if
    Serial.println(key); // se imprime la tecla que fue presionada
  }
}

```

### Cerradura básica

Haremos una cerradura básica, en la cual si se colocar la contraseña correcta se encenderá un led 3 veces cada medio segundo, esto indica que la contraseña fue correctamente colocada.
En caso que la contraseña se incorrecta, parpadeara el led, indicando que la contraseña fue incorrecta.
Tendremos todo el feedback en el monitor serial.

**Diagrama pictórico**

![](./assets/schematic/keypad_pwd.png)

**Código**

```C
#include <Keypad.h> // importamos la librería para utilizar el teclado

#define ROW_NUM     4 // indicamos el numero de renglones del teclado
#define COLUMN_NUM  4 // indicamos el numero de columnas del teclado

char keys[ROW_NUM][COLUMN_NUM] = { // indicamos las letras que tiene el teclado, estas se pueden cambiar
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM]      = {19, 18, 5, 17}; // indicamos los pines que se usaran para los renglones
byte pin_column[COLUMN_NUM] = {16, 4, 0, 2};   // indicamos los pines que se usaran para las columnas

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );  // se crea y configura el objeto para el uso del teclado


const String password = "7890"; // Aquí el password super secreto
String input_password;

#define LED 25

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Serial.println("------------------------");
  Serial.println("El password es de 4 digitos");
  Serial.println("Presionar # para aceptar el password");
  Serial.println("Presionar * para cancelar y volver a escribir el password");
  Serial.println("------------------------");
  Serial.println("Introduccir el password");
  Serial.println("------------------------");
}

void loop() {
  char key = keypad.getKey(); // esperemos la tecla que se presiono

  if (key) {
    Serial.print(key);

    if (key == '*') {
      input_password = ""; // clear input password
      Serial.println("cancelado");
      Serial.println("");
    } else if (key == '#') {
      Serial.println("");
      if (password == input_password) {
        Serial.println("The password CORRECTO!!");
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
      } else {
        Serial.println("The password INCORRECTO!");
        digitalWrite(LED, HIGH);
        delay(250);
        digitalWrite(LED, LOW);
        delay(250);
        digitalWrite(LED, HIGH);
        delay(250);
        digitalWrite(LED, LOW);
        delay(250);
        digitalWrite(LED, HIGH);
        delay(250);
        digitalWrite(LED, LOW);
        delay(250);
      }
      Serial.println("------------------------");
      Serial.println("El password es de 4 digitos");
      Serial.println("Presionar # para aceptar el password");
      Serial.println("Presionar * para cancelar y volver a escribir el password");
      Serial.println("------------------------");
      Serial.println("Introduccir el password");
      Serial.println("------------------------");
      input_password = ""; // se limpia el contenido
    } else {
      input_password += key; // va juntando los caracteres
    }
  }
}

```
## Sensor de flama

El sensor de flama va detectar cuando exista fuego, haciendo sonar una alarma y una lampara de emergencia (LED). Cuando ya no detecte peligro se apagará.

**Diagrama pictórico**

![analogico](./assets/schematic/flame_basic.png)

**Código**

```C
// defino los pines que se usaran para el sensor, buzzer y lámpara
#define BUZZER 25
#define LAMP 26
#define FLAME_SENSOR 34

void setup() {
  //configuro e inicio la comunicacion serial
  Serial.begin(115200);

  //configuro los pines como entradas y salidas
  pinMode(BUZZER, OUTPUT);
  pinMode(LAMP, OUTPUT);
  pinMode(FLAME_SENSOR, INPUT);

}

void loop() {

  // si detecta flama enciende la lampara y suena la alarma
  if (digitalRead(FLAME_SENSOR) == 1 ) {
    digitalWrite(LAMP, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(250);
    digitalWrite(BUZZER, LOW);
    delay(250);
    digitalWrite(BUZZER, HIGH);
    delay(250);
    digitalWrite(BUZZER, LOW);
    delay(250);
    digitalWrite(BUZZER, HIGH);
    delay(250);
    digitalWrite(BUZZER, LOW);
    delay(250);
  } else { // de lo contrario esta apagado todo
    digitalWrite(LAMP, LOW);
    digitalWrite(BUZZER, LOW);
    delay(1000); //espero 1 segundo para volver a detectar el sensor
  }
  delay(250);
}
```


## Sensor PIR HC-SR501 (Sensor de presencia)

![pir](./assets/schematic/pir_basic_bb.png)

![pir basic](./assets/videos/PIR_basic.gif)

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

!!! Warning Librería

    Se deben agregar una librerías para usar este sensor. [Click aquí](./assets/libs/Pack_DTHxx.zip), agregarlas a tu IDE, de lo contrario no funcionara el código de ejemplo.


![dht](./assets/schematic/dht11_bb.png)

![dht11 anima](./assets/videos/DHT11.gif)

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

!!! note Descargar la librería
    
    Agregar la librería de manera manual. [Dar click aquí](./assets/libs/NewPing.zip)

!!! note Instalación de la librería
    
    Abrir el "Gestor de Librerías" y buscar como se muestra.

    ![newping lib](./assets/newping_download.png)

### Distancia con sensor Ultrasónico

**Diagrama pictórico**

![ultrasonico](./assets/schematic/ultrasonic_basico.png)

**Animación**

![ultrasonico anima](./assets/videos/ultrasonico.gif)

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

**Diagrama pictórico**

![ultrasonico](./assets/schematic/ultrasonic_bar.png)

**Animación**

![utra bar](./assets/videos/ultrasonico_barra.gif)


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

## Sensor DS18B20 - Sensor de temperatura

!!! Note Descargar la librería

    Agregar la librería de manera manual. [Dar click aquí](./assets/libs/DS18B20.zip)

!!! Note Instalación de la librería
    Abrir el "Gestor de Librerías" y buscar como se muestra.

    ![ds18 install ide](./assets/ds18b_1-fs8.png)

    ![ds18 install ide](./assets/ds18b_2-fs8.png)

!!! warning Resistencia pull-up
    Se necesita agregarle una resistencia de pull-up al pin de señal, de lo contrario funcionara mal.
    `La resistencia es de` $4.7k\Omega$


<details markdown="1">
<summary>Pines DS18B20</summary>
  Descripción del encapsulado. Hacer los ajustes necesarios

  ![](./assets/AR0333-Sensor-de-temperatura-Digital-DS18B20-V1.jpg)

</details>


Vamos a realizar un lectura básica de la temperatura con el sensor de Dallas DS18B20 y mandar el valor al monitor serial


**Diagrama pictórico**

![ds18b](./assets/schematic/ds18b_basic.png)

**Código**

```C
// Se deben incluir estas librerías para el control del sensor
#include <OneWire.h> // conexión de one wire para la comunicación
#include <DallasTemperature.h> // lib que se encarga de transformar el dato al valor de temperatura

// definimos el pin que usaremos para la comunicación con el sensor
#define ONE_WIRE_BUS 25

// se configura la instancia (el objeto) para la comunicación con el protocolo one wire
OneWire oneWire(ONE_WIRE_BUS);

// se pasa la referencia a la lib de Dallas, que recibirá los datos del sensor y hacer la conversión
DallasTemperature sensors(&oneWire);

void setup(void) {
  Serial.begin(115200); // Se configura la comunicación serial

  //se arranca y configura la comunicación con el sensor de temperatura
  sensors.begin();
}

void loop(void) {
  Serial.print("Obteniendo temperatura...");
  sensors.requestTemperatures(); // se hace la solicitud de temperatura al sensor

  // se obtiene la temperatura en grados Celsius del sensor que hay (se le pasa 0 porque solo tenemos un sensor)
  float tempC = sensors.getTempCByIndex(0);

  // se verifica si el valor es correcto
  if (tempC != DEVICE_DISCONNECTED_C) {
    Serial.print("La temperatura es: ");
    Serial.println(tempC);
  }
  else  {
    Serial.println("Error: No se pudo obtener el valor de temperatura");
  }
  delay(5000);
}
```

## Sensor de Sonido

Vamos a realizar un interruptor por aplausos, con dos aplausos se prende y con otros 2 se apaga el led.

**Diagrama Pictórico**

![sound](./assets/schematic/sound_basic.png)

![sound](./assets/schematic/sound_basic_digital.png)

**Código**

```C
//CÓDIGO NO PROBADO 
// CÓDIGO PARA EL SENSOR CON SALIDA ANALÓGICA
#define MICROPHONE 34
#define LED 25
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;

void setup() {
  pinMode(MICROPHONE, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int status_microphone = digitalRead(MICROPHONE);

  if (status_microphone == 0) {
    if (clap == 0) {
      detection_range_start = detection_range = millis();
      clap++;
    }
    else if (clap > 0 && millis() - detection_range >= 50) {
      detection_range = millis();
      clap++;
    }
  }

  if (millis() - detection_range_start >= 400) {
    if (clap == 2) {
      if (!status_lights) {
        status_lights = true;
        digitalWrite(LED, HIGH);
      }
      else if (status_lights) {
        status_lights = false;
        digitalWrite(LED, LOW);
      }
    }
    clap = 0;
  }
}
```

## Sensor de humedad de tierra (Higrómetro)

Este sensor mide la conductividad de la tierra, es decir, que entre mas seca, menos conduce. Esta medición me esta indicando que haría falta agua (esto depende de la planta, que tanta agua requiera).

**Diagrama pictórico**

![](./assets/schematic/humedad_tierra.png)

**Código**

```C
#define SENSOR 34
#define LED 25

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {

  if (humedad == digitalRead(SENSOR)) {
    Serial.println("Tierra seca");
    Serial.println("Encender bomba");
    digitalWrite(LED, HIGH);
  } else {
    Serial.println("Encender apagada");
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
```

**Diagrama pictórico**

![](./assets/schematic/humedad_tierra_adc.png)

**Código**

```C
//Entrada analógica
#define SENSOR_HUMEDAD 34
#define LED 25

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  int humedad = analogRead(SENSOR_HUMEDAD);
  Serial.print(humedad);

  if (humedad < 500) {
    Serial.println("Tierra seca");
    Serial.println("Encender bomba");
    digitalWrite(LED, HIGH);
  }else{
    Serial.println("Encender apagada");
    digitalWrite(LED, LOW);
  }


  delay(1000);
}
```

## Sensor de Gas LP (MQ-2)

Vamos a realizar una simple alarma que al detectar una fuga de gas, active una alarma sonora, para alarmar al usuario de dicha fuga.

!!! Note Conexión del módulo

    ![conexion](./assets/MQ2-Gas-Sensor-Pin-Diagram-Image-1024x878.png)

**Diagrama Pictórico**

![mq2](./assets/schematic/mq2_basic.png)

**Código**

```C
#define LED  25
#define BUZZER  26
#define SENSOR_GAS 34
#define LIMIT 1200

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}
void loop() {

  int valor = analogRead(SENSOR_GAS);

  Serial.print("Gas Sensor: ");
  Serial.println(valor);

  if (valor > LIMIT) {
    Serial.println("Fuga de Gas");
    digitalWrite (LED, HIGH);
    digitalWrite (BUZZER, HIGH);
    delay(250);
    digitalWrite (LED, LOW);
    digitalWrite (BUZZER, LOW);
    delay(250);
    digitalWrite (LED, HIGH);
    digitalWrite (BUZZER, HIGH);
    delay(250);
    digitalWrite (LED, LOW);
    digitalWrite (BUZZER, LOW);
    delay(250);
    digitalWrite (LED, HIGH);
    digitalWrite (BUZZER, HIGH);
    delay(250);
    digitalWrite (LED, LOW);
    digitalWrite (BUZZER, LOW);
    delay(250);
  }
  else {
    Serial.println("Sin fuga de Gas");
    digitalWrite (LED, HIGH) ;
    digitalWrite (BUZZER, LOW);
    delay(1000);
  }
}
```

## Tarjeta RFID

!!! Note Descargar la librería
    Descarga la librería, [Dar click aquí](./assets/libs/MFRC522.zip)

!!! Note Instalar librería con IDE
    ![rfid ide](./assets/rfid_install_ide.png). Ver la instalación manual -> [aquí](./instalacion_manual.md)


!!! Warning Conexiones del módulo
    ![](./assets/RC522-RFID-Reader-Writer-Module-Pinout.png)


!!! Note Conexiones

    Estas conexiones no pueden cambiar, siempre se debe conectar de esta manera

    ||ESP32|<--->|RFID|
    |:---:|:---:|:---:|:---:|
    |1|3.3V|<--->|VCC|
    |2|D0|<--->|RST|
    |3|GND|<--->|GND|
    |4|NC|<--->|IRQ|
    |5|D19|<--->|MISO|
    |6|D23|<--->|MOSI|
    |7|D18|<--->|SCK|
    |8|D5|<--->|SDA|

### Dumpeando los datos de tarjeta RFID

Obteniendo todos los datos de la tarjeta o llavero. Mostrando toda la información en el monitor serial.

**Diagrama Pictórico**

![rfid schematic](./assets/schematic/rfid_basic.png)

**Código**

```C
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   0
#define SS_PIN    5

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Crea el objeto para el módulo RFID

void setup() {
  Serial.begin(115200);     // Inicializa la comunicación serial

  SPI.begin();          // Inicia la comunicación de SPI
  mfrc522.PCD_Init();   // Inicializa la comunicación con el modulo
  delay(4);             // un delay para esperar que se configure correctamente el modulo
  mfrc522.PCD_DumpVersionToSerial();    // Muestra los detalles del modulo MFRC522
  Serial.println(F("Escaneado el PICC para ver el UID, SAK, tipo, bloque de datos..."));
}
//
void loop() {
  // Resetea en cada vuelta del ciclo, para leer una una tarjeta.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Selecciona una tarjeta
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // vuelca la informacion encontrada en la tarjeta
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

```

### Leyendo el NUID de la tarjeta RFID

Lo que se realiza es leer la tarjeta, si es diferente a la anterior, te muestra su código en hexadecimal y decimal, en caso que se la misma tarjeta que se vuelve a pasar por el lector, manda el mensaje de `tarjeta leída`

```C
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   0
#define SS_PIN    5
 
MFRC522 rfid(SS_PIN, RST_PIN); // crea el objeto para ocupar el lector

MFRC522::MIFARE_Key key; 

// inicializa el array donde se almacenara el NUID
byte nuidPICC[4];

void setup() { 
  Serial.begin(115200);
  SPI.begin(); // Inicializa el bus para la comunicación SPI
  rfid.PCD_Init(); // Inicializa el modulo MFRC522 

  for (byte i = 0; i < 6; i++) {// crea una llave temporal de referencia
    key.keyByte[i] = 0xFF;
  }

  Serial.println(F("Este es el codigo leido NUID."));
  Serial.print(F("Usa la siguiente llave:"));
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
  Serial.println("");//solo para dar un enter
}
 
void loop() {

  // Resetea en cada vuelta del ciclo, para leer una una tarjeta.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verifica si el NUID ha sido leído
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println(F("Tarjeta nueva detectada."));

    // Almacena el NUID dentro del array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    Serial.println(F("El tag del NUID:"));
    Serial.print(F("En hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    Serial.print(F("En dec: "));
    printDec(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
  }
  else Serial.println(F("Tarjeta ya leida."));

  // Con estas 2 funciones se evita que siga leyendo como loco el sensor,
  // si lo quitas comenzara a leer sin parar
  // tu decides si es necesario quitarlo
  // Halt PICC
  rfid.PICC_HaltA();
  // Detiene la encriptacion en PCD
  rfid.PCD_StopCrypto1();
}


/**
 * Ayuda a imprimir los bytes del array en forma hexadecimal. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
 * Ayuda a volcar los bytes del array en forma decimal. 
 */
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
```

### Acceso autorizado

Este codigo lee la tarjeta e indica si el codigo leido es igual al almacenado. En caso que sea correcto, manda el mensaje `ACCESO CORRECTO`, de lo contrario `Acceso no autorizado`.

```C
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   0
#define SS_PIN    5

MFRC522 rfid(SS_PIN, RST_PIN); // crea el objeto para ocupar el lector

// Es la NUID de una tarjeta, aquí reemplázalo por tu NUID
byte nuidPICC[4] = {138, 92, 3, 14};;

void setup() {
  Serial.begin(115200);
  SPI.begin(); // Inicializa el bus para la comunicación SPI
  rfid.PCD_Init(); // Inicializa el modulo MFRC522

}

void loop() {

  // Resetea en cada vuelta del ciclo, para leer una una tarjeta.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verifica si el NUID ha sido leído
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  //aquí verifico que el código almacenado en la memoria sera igual al de la tarjeta que se esta verificando
  if (rfid.uid.uidByte[0] != nuidPICC[0] || rfid.uid.uidByte[1] != nuidPICC[1] || rfid.uid.uidByte[2] != nuidPICC[2] || rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println(F("ACCESO CORRECTO"));
    
  }
  else Serial.println(F("Acceso no autorizado"));

  // Con estas 2 funciones se evita que siga leyendo como loco el sensor,
  // si lo quitas comenzara a leer sin parar
  // tu decides si es necesario quitarlo
  // Halt PICC
  rfid.PICC_HaltA();
  // Detiene la encriptación en PCD
  rfid.PCD_StopCrypto1();
}
```

<!-- ### Reloj tiempo real (RTC DS1302) -->