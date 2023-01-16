---
title: Variables

---

# Variables

## ¿Qué es una variable?

Una variable desde el punto de vista computacional, es un espacio en memoria con un nombre, es decir, un espacio determinado al momento de declarar la variable, se indica su tipo y cada tipo tiene cierto espacio en memoria. 

> Es un espacio virtual el cual quedará registrado en la memoria; el cual se podrá llamar en diferentes puntos de la programación cuantas veces la necesitemos. A este espacio se le da un nombre que nos indique para qué ha sido creada. Las variables pueden tomar cualquier tipo de valor

!!! example "Variables"

    ```c
    int edad = 20; //Variable que almacena un numero, la edad
    float altura = 1.7;
    char letra = 'a';
    char* nombre = "Aprendiendo programación"; //Variable que almacena una frase (String)
    bool isAlive = true //Variable que almacena un valor booleano
    ```


## Qué es declarar una variable?

**La declaración de una variable es reservar un espacio en memoria de la computadora**.
La computadora tiene cierta cantidad de memoria, la cual es repartida entre todos los programas y los propios procesos para ejecutar el sistema operativo. Cuando ejecutamos un programa, éste comienza reservar memoria para poder trabajar.
Entonces, al declarar variables estamos consumiendo memoria, la cual vamos a utilizar en algún momento, si estamos reservando el espacio significa que en algún otro momento necesitamos recuperar lo que hemos guardado para realizar otra operación, de lo contrario no necesitamos reservar memoria si el valor solo será utilizado una única vez.

## ¿Cómo nombrar una variable?

Dentro de la programación existen **buenas practicas** para declarar variables. Estas reglas se definen a lo largo del tiempo que ha evolucionado. Estas son las reglas genéricas para (casi) todos lenguajes. 

- Deben comenzar en minúscula
- Se escriben en minúsculas, las variantes se dan cuando son más de dos palabras.
- Solo puede contener números después de la primera letra.
- Sensibles a minúsculas y mayúsculas; es decir, si declaro una variable llamada `variable1` y otra llamada `Variable1`, para la computadora son variables o espacios de memoria distintos, aun que suenen igual, con el solo hecho de cambiar una letra, ya estamos hablando de una variable distinta.
- No pueden contener espacios entre letras o palabras
- No puede comenzar con números o símbolos
- No puede contener caracteres especiales, todos son caracteres especiales menos el abecedario ingles. Ejemplo: `!"·%&-+/()=?¿...`, los únicos símbolos permitidos son `$` y `_`.
- **El nombre debe ser descriptivo**; es decir, con solo leerlo podemos deducir qué hace o para qué fue declarada
- *(Regla especial):* Todo de escribe en ingles.
- *(Regla especial)*: Si se desea escribir una variable combinando dos palabras o más, se hace comenzando la siguiente palabra con mayuscula y todo pegado, a esto se le conoce como la convención `CamelCase`.
- Ejemplos:
    - `valor`
    - `valor1`
    - `valorUno`
    - `variableNueva`