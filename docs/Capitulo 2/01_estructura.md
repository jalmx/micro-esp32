# Estructura de código base Arduino

El código Arduino es de base es lenguaje `C/C++`, toda la sintaxis, estructura, etc. Pero, para facilitar la incursion en el ecosistema Arduino diseño un estructura base que se divide en dos funciones principales, llamada `setup()` y `loop()`. Aquí no vemos la función `main()` porque esta ha sido abstraída para evitar mayores detalles, sin embargo, si existe en el programa principal pero no lo vemos.

Regresando a la estructura de Arduino y sus funciones principales `setup()` y `loop()`


## La función setup

La finalidad de esta función es configurar pines, inicializar sensores, módulos, comunicación serial, pantallas, etc.

**Esta función es la primera en ejecutarse y solo una vez**

## La función loop

La finalidad de esta función es realizar todas las tareas colocadas aquí de manera infinita (por eso se llama loop).
Lo que vayamos a colocar aquí se repetira, realizando todas las tareas indicadas en el codigo, aqui mandamos los diferentes mensajes a pantallas, leemos constantemente los sensores, etc.

**Esta función es la ultima en ejecutarse y se repetirá de manera infinita todo el código que este aquí**

```C
// the setup function runs once when you press reset or power the board
void setup() {
  // sección de configuración e inicialización de todo tipo
}

// the loop function runs over and over again forever
void loop() {
    /*aquí todo el código que queremos que se repita por siempre;
    es decir, las tareas que desarrollara el microcontrolador y realizar por siempre
    */
}
```

**Ejemplo de código blink (encendido y apagado de un LED)**

```C
#define LED_BUILTIN 34 //for ESP32 board, if you have Arduino UNO board, you don't have to do this

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```