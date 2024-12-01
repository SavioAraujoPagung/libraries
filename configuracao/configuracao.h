#ifndef configuracao
#define configuracao

#include <SoftwareSerial.h>
#include <string.h>
#include <stdlib.h>

#define FORA 10
#define QUANTIDADE_SETORES 15

class Configuracao
{
private:
  int _id;
  float _p;
  float _d;
  float _i;
  uint32_t _velocidade;
  uint32_t _tempo;
  uint32_t _erroAcumulado;

public:
  Configuracao(int id, float p, float d, float i, uint32_t velocidade, uint32_t tempo, uint32_t erroAcumulado);

  void definirPorChave(char *chave, char *valor);

  float obterP();
  void definirP(float p);

  float obterI();
  void definirI(float i);

  float obterD();
  void definirD(float d);

  uint32_t obterTempo();
  void definirTempo(uint32_t t);

  uint32_t obterVelocidade();
  void definirVelocidade(uint32_t v);

  uint32_t obterErroAcumulado();
  void definirErroAcumulado(uint32_t ea);

  char **resumo();

  static bool calibraRobo(Configuracao setores[]);
};

#endif