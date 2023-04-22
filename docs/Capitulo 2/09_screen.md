# Pantallas

## Pantalla LCD con comunicación I^2^C

La pantalla LCD es una pantalla de cristal liquido, su controlador mas común es el [HD44780](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf), su comunicación puede ser de 4 bits u 8 bits. Dado que si nos comunicamos con 8 bits, implica usar 8 pines del microcontrolador, o en su defecto si usamos la comunicación de 4 bits, se usarían 4 pines, y en ocasiones dependiendo del microcontrolador, no nos podemos dar el lujo de usar tantos, surgió un modulo de comunicación I^2^C, que implica solo usar 2 pines para el control total de toda la pantalla.

![pantalla](https://www.electronicathido.com/assets/recursosImagenes/productos/702/imagenes/16x2azul.jpg)


Los tamaños mas comunes de pantalla son 

- 16x2: 16 caracteres de forma horizontal y 2 renglones
- 20x4: 20 caracteres de forma horizontal y 4 renglones


![pantalla20](https://cdn.shopify.com/s/files/1/0020/8027/6524/files/Pantalla_esp32-topView_1024x1024.jpg?v=1624811640)


El control es exactamente igual, obviamente se debe especificar en que sitio se colocara el carácter.

Cada carácter esta formado de 5x7 pixels, es decir, podemos dar la forma o figura que quisiéramos por cada carácter y hacer combinaciones infinitas (inclusive hacer juegos)

![pantalla](https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/Character-LCD-Internal-Pixel-Grid-Structure.png)

La comunicación I^2^C nos reduce el uso de pines, pero esto incrementa el uso de mas hardware o librerías para implementar el protocolo.

![i2c](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/07/I2C_LCD2.jpg?w=750&quality=100&strip=all&ssl=1)

El controlador es el PCF8574 el encargado de recibir la informacion y comunicarla al microcontrolador de la LCD, realizando las acciones que enviamos por el protocolo.

![i2c](https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/PCF8574-Chip-On-I2C-LCD.jpg)

En la comunicación I^2^C es un protocolo tipo Maestro-Esclavo, y cada esclavo tiene un ID único (dirección), para saber a que dispositivo le estamos solicitando la información y de quien estamos recibiendo.

Al igual en este modulo incorpora un trimpot para ajustar el contraste de la pantalla, el jumper para el brillo de la pantalla y el selector de dirección (es la modificación de una resistencia)

![back](https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/I2C-LCD-Adapter-Hardware-Overview.jpg)

## Pines de la LCD con I^2^C

![lcd](https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/I2C-LCD-Display-Pinout.png)

!!! Warning Conexión
    Los pines a los que se conectan los pines de `SDA` y `SCL` de la pantalla Iran a:

    |LCD | ESP32|
    |---|---|
    |SDA| GPIO21| 
    |SCL| GPIO22|
    |VCC| 5V|
    |GND| GND|

![connect](../assets/schematic/lcd_basic_connect.png)]


!!! Warning Librería
    Descargar la librería para poder comunicar el ESP32 con el módulo I^2^C. Agregarla a Arduino IDE.
    [Dar click aquí](../assets/libs/LiquidCrystal-I2C.zip)

!!! Note Nota
    Si al arrancar la pantalla no se ve nada, recuerda mover el tripot para el contraste.

## Algoritmos de encendido de pantalla

Estos son los pasos que siempre Iran al inicio para arrancar la pantalla.

1. Función `begin()`: Solo se llama al inicio para arrancar la pantalla
2. Función `backlight()`: Enciende la luz de fondo (depende si quieres prenderla)
3. Función `clear()`: Limpia la pantalla de cualquier ruido o carácter raro que salga en pantalla
4. Función `setCursor(column, row)` 

Ya posicionados, podemos comenzar a escribir el mensaje en pantalla.



https://lastminuteengineers.com/esp32-i2c-lcd-tutorial/

### Visualización de mensaje

Se mandara un mensaje a la pantalla, línea por línea.

**Diagrama Pictórico**

![connect](../assets/schematic/lcd_basic_connect.png)]


```C
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // inicializamos la pantalla para comunicación 
  lcd.begin();
  // Enciende la luz de fondo pantalla
  lcd.backlight();
  //Por default comenzará a escribir en la posición x=0,y=0
  //se manda el siguiente texto a la pantalla
  lcd.print("Mecatronica 85"); //no se ponen acentos 
  //Nos movemos al segundo renglón, en la primera posición
  lcd.setCursor(0, 1);
  //se manda el siguiente texto a la pantalla
  lcd.print("Rules");
}

void loop()
{
  // Aquí no colocamos nada
}
```

#### Voltímetro

Realizaremos un voltímetro sencillo y básico, donde vamos a leer el voltaje de un divisor de tension.

Para ello debemos aplicar una formula donde vamos a convertir el valor que se recibe del ADC a un valor equivalente de voltaje, como tenemos un potenciómetro lineal, la relación es directa, quedando la formula

$$voltaje = ADC_{bit} \frac{3.3V}{4095_{bit}}$$

Con esta formula estamos convirtiendo lo que recibimos en la entrada del ADC a lo correspondiente de voltaje.

Como el valor máximo de voltaje es 3.3V, esto se divide entre la resolución del ADC y lo multiplicamos por el valor leído.

**Diagrama pictórico**

![voltimetro lcd](../assets/schematic/voltimetro_lcd_01.png)


**Código básico**

```C
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define PIN_ADC 34


void setup(){
  // inicializamos la pantalla para comunicación 
  lcd.begin();
  // Enciende la luz de fondo pantalla
  lcd.backlight();
  //Por default comenzará a escribir en la posición x=0,y=0
  //se manda el siguiente texto a la pantalla
  lcd.print("Mecatronica 85");
  //Nos movemos al segundo renglón, en la primera posición
  lcd.setCursor(0, 1);
  //se manda el siguiente texto a la pantalla
  lcd.print("Voltimetro");
  delay(1000); //esperamos un segundo para el mensaje de bienvenida
  lcd.clear(); //limpiamos la pantalla
  lcd.setCursor(0,0); //regresamos a la posición inicial
  lcd.print("Voltimetro 85");
  lcd.setCursor(15,1);  //nos movemos a la columna 15 y la ultima posición
  lcd.print("V"); //colocamos la unidad del voltaje (V)
}

void loop(){
  int valorADC = analogRead(PIN_ADC);
  delay(10); //esperamos un momento de estabilización del dato
  float voltaje = (valorADC * 3.3) / 4095.0; //convertimos el valor a voltaje
  lcd.setCursor(11,1); //nos colocamos en la parte para que el numero salga al final al lado de la "V"
  lcd.print(voltaje);
  delay(50);
}
```

**Código más estable**

Este código es más eficiente para tener una valor más estable. Aplicamos un promedio de la muestra. Con esto hacemos que el valor que se muestra se más conciso.

```C
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define PIN_ADC 34


void setup() {
  // inicializamos la pantalla para comunicación
  lcd.begin();
  // Enciende la luz de fondo pantalla
  lcd.backlight();
  //Por default comenzará a escribir en la posición x=0,y=0
  //se manda el siguiente texto a la pantalla
  lcd.print("Mecatronica 85");
  //Nos movemos al segundo renglón, en la primera posición
  lcd.setCursor(0, 1);
  //se manda el siguiente texto a la pantalla
  lcd.print("Voltimetro");
  delay(1000); //esperamos un segundo para el mensaje de bienvenida
  lcd.clear(); //limpiamos la pantalla
  lcd.setCursor(0, 0); //regresamos a la posición inicial
  lcd.print("Voltimetro 85");
  lcd.setCursor(15, 1); //nos movemos a la columna 15 y la ultima posición
  lcd.print("V"); //colocamos la unidad del voltaje (V)
}

#define MUESTRAS 60.0 // defino una cantidad de muestras que se tomaran para el promedio

void loop() {
  int valorADC = 0;     //aquí guardaremos el valor del ADC
  int suma = 0;         //acumulara el valor de las muestras del ADC
  for (byte x = 0; x < MUESTRAS; x++) {
    valorADC = analogRead(PIN_ADC);
    suma += valorADC;
    delay(5); //esperamos un momento de estabilización del dato
  }
  float promedio = suma / MUESTRAS;
  float voltaje = (valorADC * 3.3) / 4095.0; //convertimos el valor a voltaje
  lcd.setCursor(11, 1); //nos colocamos en la parte para que el numero salga al final al lado de la "V"
  lcd.print(voltaje);

}
```





----

## OLED 

check https://github.com/durydevelop/arduino-lib-oled