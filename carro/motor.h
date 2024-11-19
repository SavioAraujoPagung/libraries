#ifndef motor
#define motor

#include <Arduino.h>

class Motor 
{
  public :
    Motor (uint8_t  _pin_one, uint8_t  _pin_two, uint8_t  pwm);
    void SetPower(int16_t _speed);
    uint8_t get_pin_one();
    uint8_t get_pin_two();

    uint8_t set_speed(int16_t _spped);
    uint8_t _pin_one; 
    uint8_t _pin_two;
    uint8_t _pwm;
};


#endif