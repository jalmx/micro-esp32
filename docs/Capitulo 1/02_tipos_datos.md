---
title: Tipos de datos
author: Alejandro Leyva
date: 2023-01-15
---

# Tipos de datos

Los tipos de datos son la manera en la que vamos a decirle al programa el tamaño de la variable y al mismo momento

| Nombre | Tipo| Tamaño | Rango |
| --- | --- | --- | --- |
| byte | `byte` | 8 bits = 1 byte | -128 a 127 o 0 a 255|
| Carácter sin signo | `unsigned char` | 1 byte | 0 hasta 255|
| Carácter con signo | `char` | 1 byte | -128 hasta 127 |
| Entero corto sin signo | `unsigned short int` o `unsigned short` | 2 bytes| 0 a 65,535 |
| Entero corto con signo | `short int` | 2 bytes| -32,768 a +32,767 |
| Entero con signo | `int` | 4 bytes| -2,147,483,648 a +2,147,483,647 |
| Entero largo | `long int` | 4 bytes| -2,147,483,648 a +2,147,483,647 |
| Entero largo sin signo | `long long int` | 8 bytes| 9,223,372,036,854,775,808 al +9,223,372,036,854,775,807 |
| Flotante | `float` | 4 bytes| -3.4³⁸ al  +3.4³⁸  |
| Doble | `double` | 8 bytes|-1.7³⁰⁸ al +1.7³⁰⁸ |
| Doble largo | `long double` | 12 bytes|-1.9⁴⁹³² al +1.9⁴⁹³² |

!!! nota
    El tipo de dato que aplicara esta en función de que tan grande sera el valor que contendrá. Es decir, **si el valor no pasará de 255 y entero, podemos usar un tipo `char`, pero si el valor que podrá ser hasta 1,000,000 pues seleccionamos el tipo `long int`**.

```c
char i = 0;
int valor = 20000;
float altura = 1.8;
```

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

### Comentarios multilínea

La forma de indicar un comentario multi línea es envolverlo con una diagonal con un asterisco y cierra con un asterisco y una diagonal (`/**/`).

Una de las ventajas es que se puede colocar codigo en cualquier parte sin ser parte del codigo.

```c
/*
* En esta sección se toma como un bloque de comentario
* Todo lo que esta escrito el compilador lo ignora porque 
* es una indicación para nosotros
*/

int valor = 5; /*también se puede ocupar como de una línea, lo importante es que este envuelto entre los símbolos correspondientes*/

float /*tipo de variable*/ altura /*nombre de variable*/ = 1.782; 
``` 

