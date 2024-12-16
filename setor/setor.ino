#include "configuracao.h"

void setup() {
  // put your setup code here, to run once:

  int id = 0;
  float p = 1;
  float d = 2;
  float i = 3;
  uint32_t velocidade = 4;
  uint32_t tempo = 0;
  uint32_t erroAcumulado = 0;
  Configuracao setor1 = Configuracao(id, p, d, i, velocidade, tempo, erroAcumulado);

  setor1.definirErroAcumulado(2);
  setor1.obterErroAcumulado();

  setor1.obterP();
  setor1.definirP(2.1);
  
  setor1.obterI();
  setor1.definirI(3.2);
  
  setor1.obterD();
  setor1.definirD(1.2);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
