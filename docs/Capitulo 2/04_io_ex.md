# Ejercicios con IO

## Display de 7 Segmentos

Realizar el siguiente ejercicio, como se ve en la imagen

![](../assets/videos/contador_btn.gif)

<details markdown="1">
<summary>Código</summary>

```C
const int A = 25;
const int B = 26;
const int C = 27;
const int D = 14;
const int E = 12;
const int F = 19;
const int G = 18;
const int BTN_INC = 34;
const int BTN_DEC = 35;
const int BTN_RS = 32;

void display(int a, int b, int c, int d, int e, int f, int g);

void display(int a, int b, int c, int d, int e, int f, int g)
{
  digitalWrite(A, a);
  digitalWrite(B, b);
  digitalWrite(C, c);
  digitalWrite(D, d);
  digitalWrite(E, e);
  digitalWrite(F, f);
  digitalWrite(G, g);
}

void setup()
{
  Serial.begin(115200);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

// the loop function runs over and over again forever
int count = 0;
void loop()
{
  if (digitalRead(BTN_INC) == 1)
  {
    delay(250);
    if (count < 15)
      count++;
  }
  else if (digitalRead(BTN_DEC) == 1)
  {
    delay(250);
    if (count > 0)
      count--;
  }
  else if (digitalRead(BTN_RS) == 1)
  {
    delay(250);
    count = 0;
  }

  if (count == 0)
    display(1, 1, 1, 1, 1, 1, 0); // 0
  if (count == 1)
    display(0, 1, 1, 0, 0, 0, 0); // 1
  if (count == 2)
    display(1, 1, 0, 1, 1, 0, 1); // 2
  if (count == 3)
    display(1, 1, 1, 1, 0, 0, 1); // 3
  if (count == 4)
    display(0, 1, 1, 0, 0, 1, 1); // 4
  if (count == 5)
    display(1, 0, 1, 1, 0, 1, 1); // 5
  if (count == 6)
    display(1, 0, 1, 1, 1, 1, 1); // 6
  if (count == 7)
    display(1, 1, 1, 0, 0, 0, 0); // 7
  if (count == 8)
    display(1, 1, 1, 1, 1, 1, 1); // 8
  if (count == 9)
    display(1, 1, 1, 0, 0, 1, 1); // 9
  if (count == 10)
    display(1, 1, 1, 0, 1, 1, 1); // A
  if (count == 11)
    display(0, 0, 1, 1, 1, 1, 1); // B
  if (count == 12)
    display(1, 0, 0, 1, 1, 1, 0); // C
  if (count == 13)
    display(0, 1, 1, 1, 1, 0, 1); // D
  if (count == 14)
    display(1, 0, 0, 1, 1, 1, 1); // E
  if (count == 15)
    display(1, 0, 0, 0, 1, 1, 1); // F
  
  delay(10);
}
```
</details>
