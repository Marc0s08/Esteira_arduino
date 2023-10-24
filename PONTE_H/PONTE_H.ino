#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int IN1 = 4;
int IN2 = 5;

int pot = A0;
int valorPot = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(pot, INPUT);
  lcd.begin(16, 2);        // Dimensão da tela
  lcd.setBacklight(HIGH);  //Liga a luz de fundo
}

void loop() {

  //LIGAR MOTOR
  valorPot = analogRead(pot);
  valorPot = map(valorPot, 0, 1023, 0, 255);
  //lcd.clear(); // apaga o texto escrito no Display
  if (valorPot > 1) {


    analogWrite(IN1, HIGH);
    analogWrite(IN2, LOW);

    lcd.setCursor(0, 0);  // coluna 0, linha 0
    lcd.print("MOTOR  ON");
  }
  //Anti horario
  if (valorPot > 128){

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(2000);
  }
  
  //PARAR MOTOR
  if (valorPot == 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    lcd.setCursor(0, 0);     // coluna 0, linha 0
    lcd.print("MOTOR OFF");  // Insira seu texto Aqui, dentro das Aspas
  }
}
