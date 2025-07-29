#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int pinservo1 = 2;
int pinservo2 = 3;
int pinservo3 = 4;
int pinservo4 = 5;
int pinservo5 = 6;

void abrir() {
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
}
void indice(char op) { //con 1 abre y con 2 cierra
  switch (op) {
    case 1:
      servo1.write(0);
      break;
    case 2:
      servo1.write(180);
      break;
  }
}

void corazon(char op) {
  switch (op) {
    case 1:
      servo2.write(0);
      break;
    case 2:
      servo2.write(180);
      break;
  }
}

void anular(char op) {
  switch (op) {
    case 1:
      servo3.write(0);
      break;
    case 2:
      servo3.write(180);
      break;
  }
}
void menique(char op) {
  switch (op) {
    case 1:
      servo4.write(0);
      break;
    case 2:
      servo4.write(180);
      break;
  }
}
void gordo(char op) {
  switch (op) {
    case 1:
      servo5.write(0);
      break;
    case 2:
      servo5.write(180);
      break;
  }
}
void cerrar() {
  indice(2);
  corazon(2);
  anular(2);
  menique(2);
  gordo(2);
}
void contar() {
  cerrar(); // en 180
  delay(1000);
  indice(1); // en 0
  delay(1000);
  corazon(1);
  delay(1000);
  anular(1);
  delay(1000);
  menique(1);
  delay(1000);
  gordo(1);
  delay(1000);
}

void regresivo() {
  abrir(); // en 0 para 5
  delay(1000);
  gordo(2); // en 180 para 4
  delay(1000);
  menique(2); // para 3
  delay(1000);
  anular(2); // para 2
  delay(1000);
  corazon(2); // para 1
  delay(1000);
  indice(2); // para 0
  delay(1000);
}
void saludo() {

  for (int i = -180; i <= 180; i++) {
    servo5.write(i); // 1 -- 1º
    delay(1);
    servo1.write(i + 36); // 37 --> 1º
    delay(1);
    servo2.write(i + 72); // 73 --> 1º
    delay(1);
    servo3.write(i + 108); // 109 --> 1º
    delay(1);
    servo4.write(i + 144); // 145 --> 1º
    delay(1);
  }
  for (int i = 180; i >= -180; i--) {
    servo4.write(i);
    delay(1);
    servo3.write(i + 36);
    delay(1);
    servo2.write(i + 72);
    delay(1);
    servo1.write(i + 108);
    delay(1);
    servo5.write(i + 144);
    delay(1);
  }
}

void pistola() {
  indice(1);
  corazon(2);
  anular(2);
  menique(2);
  gordo(1);
  delay(800);
  gordo(2);
  delay(800);
  gordo(1);
  delay(800);
  gordo(2);
  delay(800);
  gordo(1);
}
void sigsag() {
  indice(1);
  corazon(2);
  anular(1);
  menique(2);
  gordo(2);
  delay(800);
  indice(2);
  corazon(1);
  anular(2);
  menique(1);
  gordo(1);
}
void setup() {
  servo1.attach(pinservo1, 610, 2550);
  servo2.attach(pinservo2, 670, 2540);
  servo3.attach(pinservo3, 660, 2600);
  servo4.attach(pinservo4, 660, 2600);
  servo5.attach(pinservo5, 660, 2600);
  pinMode(pinservo1, OUTPUT);
  pinMode(pinservo2, OUTPUT);
  pinMode(pinservo3, OUTPUT);
  pinMode(pinservo4, OUTPUT);
  pinMode(pinservo5, OUTPUT);
  Serial.begin(9600);
  abrir();
}

void loop() {
  cerrar();
  delay(800);
  abrir();
  delay(800);
  contar();
  delay(800);
  regresivo();
  delay(800);
  saludo();
  delay(800);
  pistola();
  delay(800);
  sigsag();
  delay(800);
}
