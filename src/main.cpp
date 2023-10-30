#include <Arduino.h>
#define PinInterrupcion0 2
volatile int contador0 = 0;
int contadoranteror0 = 0;
int grados = 15;
int led = 7;

void interrupcion0()
{
  contador0++;
}

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  Serial.print("contador0: ");
  Serial.println(contador0);
  attachInterrupt(digitalPinToInterrupt(PinInterrupcion0), interrupcion0, RISING);
}

void loop()
{
  digitalWrite(led, LOW);
  if (contador0 != contadoranteror0)
  {
    Serial.print("contador0: ");
    Serial.println(contador0);
    contadoranteror0 = contador0;
  }
  if (contador0 >= grados)
  {
    contador0 = 0;
    digitalWrite(led, HIGH);
    delay(1000);
  }
}