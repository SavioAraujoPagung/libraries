#ifndef motor
#define motor

#include <Arduino.h>

class Motor 
{
  public :
    Motor (uint8_t  pino1, uint8_t  pino2, uint8_t  pwm);
    void set_power(int16_t velocidade);
    uint8_t get_pino1();
    uint8_t get_pino2();

    uint8_t pino1; 
    uint8_t pino2;
    uint8_t pwm;
};

#endif