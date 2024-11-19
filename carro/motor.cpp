#include "Arduino.h"
#include "motor.h"

#define POTENCIA_MINIMA 255
#define OUTPUT 2
#define PINO_LED 13

Motor::Motor(uint8_t pino1, uint8_t pino2, uint8_t pwm)
{
  this->_pino1 = pino1;
  this->_pino2 = pino2;
  this->_pwm = pwm;
  pinMode(this->_pino1, OUTPUT);
  pinMode(this->_pino2, OUTPUT);
  pinMode(this->_pwm, OUTPUT);
}

uint8_t Motor::get_pino1()
{
  return this->_pino1;
}

uint8_t Motor::get_pino2()
{
  return this->_pino2;
}

uint8_t Motor::get_pwm()
{
  return this->_pwm;
}

void Motor::set_power(int16_t velocidade)
{
  if (velocidade > 0)
  {
    velocidade = constrain(velocidade, 0, POTENCIA_MINIMA);
    digitalWrite(this->get_pino1(), 1);
    digitalWrite(this->get_pino2(), 0);
    analogWrite(this->get_pwm(), abs(velocidade));
  }
  else if (velocidade < 0)
  {
    velocidade = constrain(velocidade, -POTENCIA_MINIMA, 0);
    digitalWrite(this->get_pino1(), 0);
    digitalWrite(this->get_pino2(), 1);
    analogWrite(this->get_pwm(), abs(velocidade));
  }
  else
  {
    digitalWrite(this->get_pino1(), 0);
    digitalWrite(this->get_pino2(), 1);
    digitalWrite(this->get_pwm(), 1);
  }
}