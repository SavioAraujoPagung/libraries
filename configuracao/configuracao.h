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
  int id;
  float p;
  float d;
  float i;
  uint32_t velocidade;
  uint32_t tempo;
  uint32_t erroAcumulado;

public:
  Configuracao(int id, float p, float d, float i, uint32_t velocidade, uint32_t tempo, uint32_t erroAcumulado);

  void definir_por_chave(char *chave, char *valor);

  float obter_p();
  void definir_p(float p);

  float obter_i();
  void definir_i(float i);

  float obter_d();
  void definir_d(float d);

  uint32_t obter_tempo();
  void definir_tempo(uint32_t t);

  uint32_t obter_velocidade();
  void definir_velocidade(uint32_t v);

  uint32_t obter_erro_acumulado();
  void definir_erro_acumulado(uint32_t ea);

  char **resumo();

  static bool calibra_robo(Configuracao setores[]);
};

#endif