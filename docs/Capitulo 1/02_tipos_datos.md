---
title: Tipos de datos
author: Alejandro Leyva
date: 2023-01-15
---

# Tipos de datos

Los tipos de datos son la manera en la que vamos a decirle al programa el tamaño de la variable y al mismo momento

|Nombre|Tipo|Tamaño|Rango|
|-|-|-|-|
|byte|`byte`|8 bits|-128 a 127 o 0 a 255|
|Carácter sin signo|`unsigned char`|1 byte|0 hasta 255|
|Carácter con signo|`char`|1 byte|-128 hasta 127
|Entero sin signo|`unsigned int`|2 o 4 bytes|0 a 65,535 o 0 a 4,294,967,295
|Entero con signo|`int`|2 o 4 bytes|-32,768 a 32,767 o -2,147,483,648 a 2,147,483,647
|Entero chico sin signo|`unsigned short`|2 bytes|0 hasta 65.535
|Entero chico con signo|`short`|2 bytes|-32.768 hasta 32.767
|Entero largo sin signo|`unsigned long`|8 bytes|0 a 18446744073709551615|
|Entero largo con signo|`long`|8 bytes|-9223372036854775808 al 9223372036854775807|
|Flotante|`float`|4 bytes|1.2E-38 a 3.4E + 38|
|Doble|`double`|8 bytes|2.3E-308 hasta 1.7E + 308|

## Comentarios

Siempre que escribimos un código queremos colocar un comentario con respecto a lo que hace el programa o dejarnos una nota para nuestro yo del futuro, obviamente estos comentarios no le interesa al compilador o al programa, es para nosotros.

Hay dos maneras de indicar un comentario, que son comentarios en línea o multilínea

### Comentarios de una sola línea

La forma de indicar un comentario de una línea es usando doble diagonal hacia adelante (`//`).

```c
// comentario de una línea
int edad = 3; // //en esta variable guardo el valor de 3
``` 

Todo lo que se escribe delante de `//` el compilador lo comienza a tomar como comentario, aun asi tenga código correcto y propio del lenguaje, dado que al saber que es un comentario lo va a ignorar.

### Comentarios multi línea

La forma de indicar un comentario multi línea es envolverlo con una diagonal con un asterisco y cierra con un asterisco y una diagnonal (`/**/`).

```c
/*
En esta sección se toma como un bloque de comentario
Todo lo que esta escrito el compilador lo ignora porque 
es una indicación para nosotros
*/
float altura = 1.782; /*también se puede ocupar como de una línea, lo importante es que este envuelto entre los símbolos correspondientes*/
``` 
