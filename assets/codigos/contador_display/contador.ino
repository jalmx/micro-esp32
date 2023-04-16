const int A = 25;
const int B = 26;
const int C = 27;
const int D = 14;
const int E = 12;
const int F = 19;
const int G = 18;

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

void loop()
{

  display(1, 1, 1, 1, 1, 1, 0); // 0
  delay(500);
  display(0, 1, 1, 0, 0, 0, 0); // 1
  delay(500);
  display(1, 1, 0, 1, 1, 0, 1); // 2
  delay(500);
  display(1, 1, 1, 1, 0, 0, 1); // 3
  delay(500);
  display(0, 1, 1, 0, 0, 1, 1); // 4
  delay(500);
  display(1, 0, 1, 1, 0, 1, 1); // 5
  delay(500);
  display(1, 0, 1, 1, 1, 1, 1); // 6
  delay(500);
  display(1, 1, 1, 0, 0, 0, 0); // 7
  delay(500);
  display(1, 1, 1, 1, 1, 1, 1); // 8
  delay(500);
  display(1, 1, 1, 0, 0, 1, 1); // 9
  delay(500);
  display(1, 1, 1, 0, 1, 1, 1); // A
  delay(500);
  display(0, 0, 1, 1, 1, 1, 1); // B
  delay(500);
  display(1, 0, 0, 1, 1, 1, 0); // C
  delay(500);
  display(0, 1, 1, 1, 1, 0, 1); // D
  delay(500);
  display(1, 0, 0, 1, 1, 1, 1); // E
  delay(500);
  display(1, 0, 0, 0, 1, 1, 1); // F
  delay(500);
}
