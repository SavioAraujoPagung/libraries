#include "sensor.h"
#include "motor.h"


void setup() {
  uint8_t pino1 = 9;
  uint8_t pino2 = 8;
  uint8_t pwm = 87;
  Motor motor1 = Motor(pino1, pino2, pwm);

  motor1.pino1();

  int16_t velocidade = 39;
  motor1.potencia(velocidade);


  Sensor sensorLinha = Sensor();
  sensorLinha.atualizaSensor();
  sensorLinha.iniciaSensor();
  uint8_t i = 1;
  sensorLinha.obtemIntensidade(i);
  
  uint8_t s = 1;
  sensorLinha.naLinha(s);
  
  uint8_t s2 = 2;
  sensorLinha.naLinha(s, s2);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
