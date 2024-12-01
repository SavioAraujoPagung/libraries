#include "configuracao.h"

Configuracao::Configuracao(int id, float p, float d, float i, uint32_t velocidade, uint32_t tempo, uint32_t erroAcumulado)
{
  this->_id = id;
  this->_p = p;
  this->_i = i;
  this->_d = d;
  this->_velocidade = velocidade;
  this->_tempo = tempo;
  this->_erroAcumulado = erroAcumulado;
}

void Configuracao::definirPorChave (char *chave, char *valor)
{
  uint8_t tempUint8;
  float tempFloat;
  if (strncmp(chave, "id", 2) == 0)
  {
    tempUint8 = atoi(valor);
    this->_id = tempUint8;
    return;
  }
  if (strncmp(chave, "setor", 5) == 0)
  {
    tempUint8 = atoi(valor);
    this->_id = tempUint8;
    return;
  }
  if (strncmp(chave, "velocide", 8) == 0)
  {
    tempUint8 = atoi(valor);
    this->_velocidade = tempUint8;
    return;
  }
  if (strncmp(chave, "kp", 2) == 0)
  {
    tempFloat = atof(valor);
    this->_p = tempFloat;
    return;
  }
  if (strncmp(chave, "kd", 2) == 0)
  {
    tempFloat = atof(valor);
    this->_d = tempFloat;
    return;
  }
  if (strncmp(chave, "ki", 2) == 0)
  {
    tempFloat = atof(valor);
    this->_i = tempFloat;
    return;
  }
}

float Configuracao::obterP()
{
  return this->_p;
}

void Configuracao::definirP(float p)
{
  this->_p = p;
}

float Configuracao::obterI()
{
  return this->_i;
}

void Configuracao::definirI(float i)
{
  this->_i = i;
}

float Configuracao::obterD()
{
  return this->_d;
}

void Configuracao::definirD(float d)
{
  this->_d = d;
}

uint32_t Configuracao::obterTempo()
{
  return this->_tempo;
}

void Configuracao::definirTempo(uint32_t t)
{
  this->_tempo = t;
}

uint32_t Configuracao::obterVelocidade()
{
  return this->_velocidade;
}

void Configuracao::definirVelocidade(uint32_t v)
{
  this->_velocidade = v;
}

uint32_t Configuracao::obterErroAcumulado()
{
  return this->_erroAcumulado;
}

void Configuracao::definirErroAcumulado(uint32_t ea)
{
  this->_erroAcumulado = ea;
}

char **Configuracao::resumo()
{
  char **res;

  res = (char **)malloc(7 * sizeof(char *));
  if (res == NULL)
  {
    return NULL;
  }

  for (int index = 0; index < 7; index++)
  {
    res[index] = (char *)malloc(20 * sizeof(char *));
    if (res[index] == NULL)
    {
      printf("Erro ao alocar memória para a linha %d\n", index);
      return NULL;
    }

    switch (index)
    {
    case 0:
      sprintf(res[index], "id:%d", this->_id);
      break;
    case 1:
      sprintf(res[index], "p:%.2f", this->_p);
      break;
    case 2:
      sprintf(res[index], "i:%.2f", this->_i);
      break;
    case 3:
      sprintf(res[index], "d:%.2f", this->_d);
      break;
    case 4:
      sprintf(res[index], "velocidade:%d", this->_velocidade);
      break;
    case 5:
      sprintf(res[index], "tempo:%d", this->_tempo);
      break;
    case 6:
      sprintf(res[index], "i:%d", this->_erroAcumulado);
      break;
    }
  }

  return res;
}
