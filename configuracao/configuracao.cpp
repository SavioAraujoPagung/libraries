#include "configuracao.h"

Configuracao::Configuracao(int id, float p, float d, float i, uint32_t velocidade, uint32_t tempo, uint32_t erroAcumulado)
{
  this->id = id;
  this->p = p;
  this->i = i;
  this->d = d;
  this->velocidade = velocidade;
  this->tempo = tempo;
  this->erroAcumulado = erroAcumulado;
}

void Configuracao::definirPorChave(char *chave, char *valor)
{
  uint8_t tempUint8;
  float tempFloat;
  if (strncmp(chave, "id", 2) == 0)
  {
    tempUint8 = atoi(valor);
    this->id = tempUint8;
    return;
  }
  if (strncmp(chave, "setor", 5) == 0)
  {
    tempUint8 = atoi(valor);
    this->id = tempUint8;
    return;
  }
  if (strncmp(chave, "velocide", 8) == 0)
  {
    tempUint8 = atoi(valor);
    this->velocidade = tempUint8;
    return;
  }
  if (strncmp(chave, "kp", 2) == 0)
  {
    tempFloat = atof(valor);
    this->p = tempFloat;
    return;
  }
  if (strncmp(chave, "kd", 2) == 0)
  {
    tempFloat = atof(valor);
    this->d = tempFloat;
    return;
  }
  if (strncmp(chave, "ki", 2) == 0)
  {
    tempFloat = atof(valor);
    this->i = tempFloat;
    return;
  }
}

float Configuracao::obterP()
{
  return this->p;
}

void Configuracao::definirP(float p)
{
  this->p = p;
}

float Configuracao::obterI()
{
  return this->i;
}

void Configuracao::definirI(float i)
{
  this->i = i;
}

float Configuracao::obterD()
{
  return this->d;
}

void Configuracao::definirD(float d)
{
  this->d = d;
}

uint32_t Configuracao::obterTempo()
{
  return this->tempo;
}

void Configuracao::definirTempo(uint32_t t)
{
  this->tempo = t;
}

uint32_t Configuracao::obterVelocidade()
{
  return this->velocidade;
}

void Configuracao::definirVelocidade(uint32_t v)
{
  this->velocidade = v;
}

uint32_t Configuracao::obterErroAcumulado()
{
  return this->erroAcumulado;
}

void Configuracao::definirErroAcumulado(uint32_t ea)
{
  this->erroAcumulado = ea;
}

char **Configuracao::resumo()
{
  char **res;

  res = (char **)malloc(7 * sizeof(char *));
  if (res == NULL)
  {
    printf("Erro ao alocar memória para a linha %d\n", i);
    return NULL;
  }

  for (int i = 0; i < 7; i++)
  {
    res[i] = (char *)malloc(20 * sizeof(char *));
    if (res[i] == NULL)
    {
      printf("Erro ao alocar memória para a linha %d\n", i);
      return NULL;
    }

    switch (i)
    {
    case 0:
      sprintf(res[i], "id:%d", this->id);
      break;
    case 1:
      sprintf(res[i], "p:%.2f", this->p);
      break;
    case 2:
      sprintf(res[i], "i:%.2f", this->i);
      break;
    case 3:
      sprintf(res[i], "d:%.2f", this->d);
      break;
    case 4:
      sprintf(res[i], "velocidade:%d", this->velocidade);
      break;
    case 5:
      sprintf(res[i], "tempo:%d", this->tempo);
      break;
    case 6:
      sprintf(res[i], "i:%d", this->erroAcumulado);
      break;
    }
  }

  return res;
}
