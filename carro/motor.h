#ifndef motor
#define motor

#include <Arduino.h>

class Motor 
{
  public :
    Motor (uint8_t  pino1, uint8_t  pino2, uint8_t  pwm);
    void potencia(int16_t velocidade);
    uint8_t pino1();
    uint8_t pino2();
    uint8_t pwm();
  
  private:
    uint8_t _pino1; 
    uint8_t _pino2;
    uint8_t _pwm;
};

#endif