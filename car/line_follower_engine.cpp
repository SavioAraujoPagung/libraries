#include "Arduino.h"
#include "line_follower_engine.h"

#define MINIMUMPOWER 255
#define OUTPUT 2 
#define PINO_LED 13

Engine::Engine(uint8_t  pin_one, uint8_t  pin_two, uint8_t  pwm)
{
    this->_pin_one = pin_one;
    this->_pin_two = pin_two;
    this->_pwm = pwm;
    pinMode(this->_pin_one, OUTPUT);
    pinMode(this->_pin_two, OUTPUT);
    pinMode(this->_pwm, OUTPUT);
}

uint8_t Engine::get_pin_one()
{
  return this->_pin_one;
}

uint8_t Engine::get_pin_two()
{
  return this->_pin_two;
}

void Engine::SetPower(int16_t _spped)
{
    if (_spped > 0)
    {
        this->set_speed(1);
        return;
    }

    if (_spped < 0)
    {
        return;
    }
}