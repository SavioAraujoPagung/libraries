#include "Arduino.h"
#include "motor.h"

#define POTENCIA_MINIMA 255
#define OUTPUT 2
#define PINO_LED 13

Motor::Motor(uint8_t pino1, uint8_t pino2, uint8_t pwm)
{
  this->pino1 = pino1;
  this->pino2 = pino2;
  this->pwm = pwm;
  pinMode(this->pino1, OUTPUT);
  pinMode(this->pino2, OUTPUT);
  pinMode(this->pwm, OUTPUT);
}

uint8_t Motor::get_pino1()
{
  return this->pino1;
}

uint8_t Motor::get_pino2()
{
  return this->pino2;
}

void Motor::set_power(int16_t velocidade)
{
  if (velocidade > 0)
  {
    velocidade = constrain(velocidade, 0, POTENCIA_MINIMA);
    digitalWrite(this->get_pino1(), 1);
    digitalWrite(pino2, 0);
    analogWrite(pwm, abs(velocidade));
  }
  else if (velocidade < 0)
  {
    velocidade = constrain(velocidade, -POTENCIA_MINIMA, 0);
    digitalWrite(pino1, 0);
    digitalWrite(pino2, 1);
    analogWrite(pwm, abs(velocidade));
  }
  else
  {
    digitalWrite(pino1, 0);
    digitalWrite(pino2, 0);
    digitalWrite(pwm, 1);
  }
}