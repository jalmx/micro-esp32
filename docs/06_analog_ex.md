# Ejercicios con I/O Analógicas

## Lámparas del parque

Realizar el siguiente ejercicio, ver la animación

![ldr_bar_sch](./assets/schematic/ldr_led_bar.png)

![ldr_bar_gir](./assets/videos/LDR_bar.gif)

**Funcionamiento**

1. Cuando exista poca luz en el sensor (esto definido por el programador), se deben encender todas las lamparas (los LEDs), de forma secuencial e ir quedando encendidas hasta que estén todas prendidas.
2. Si hay una luz intermedia, solo deben estar encendidas 2 lamparas.
3. Si hay suficiente luz en el ambiente, deben continuar apagadas.
4. Al momento en apagarse, se irán apagando una a una, hasta que al final queden apagadas.


<!-- Bloque de código -->
<!-- 
<details markdown="1">
<summary>Código</summary>

```C
const byte pinADC = 34;  //pin que sera leído del ADC
const byte LED1 = 25;    //Configuro el pin en donde colocaré el LED
const byte LED2 = 26;    //Configuro el pin en donde colocaré el LED
const byte LED3 = 27;    //Configuro el pin en donde colocaré el LED
const byte LED4 = 14;    //Configuro el pin en donde colocaré el LED
#define LIMIT_INF 1500       //ESTE VALOR SE CAMBIA CON BASE AL AJUSTE DEL SENSOR
#define LIMIT_SUP 3000       //ESTE VALOR SE CAMBIA CON BASE AL AJUSTE DEL SENSOR

// the setup routine runs once when you press reset:
void setup() {
  // inicializamos el monitor serial a 115200 baudios
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);  //configuro como salida el pin para el led
  pinMode(LED2, OUTPUT);  //configuro como salida el pin para el led
  pinMode(LED3, OUTPUT);  //configuro como salida el pin para el led
  pinMode(LED4, OUTPUT);  //configuro como salida el pin para el led
}

void loop() {
  int valueLDR = analogRead(pinADC);  //leemos el pin del ADC
  Serial.print("Valor del ADC: ");
  Serial.println(valueLDR);

  if (valueLDR < LIMIT_INF) {
    digitalWrite(LED1, LOW);
    delay(250);
    digitalWrite(LED2, LOW);
    delay(250);
    digitalWrite(LED3, LOW);
    delay(250);
    digitalWrite(LED4, LOW);
  } else if (valueLDR > LIMIT_INF && valueLDR < LIMIT_SUP ) {
    digitalWrite(LED1, HIGH);
    delay(250);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  } else {
    digitalWrite(LED1, HIGH);
    delay(250);
    digitalWrite(LED2, HIGH);
    delay(250);
    digitalWrite(LED3, HIGH);
    delay(250);
    digitalWrite(LED4, HIGH);
  }

  delay(10);  // para la estabilidad del valor de entrada
}
```
</details>

 -->