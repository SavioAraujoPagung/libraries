#include "configuracao.h"

Configuracao::Configuracao(int id, float p, float d, float i, uint32_t velocidade, uint32_t tempo, uint32_t erroAcumulado) {
  this->id = id;
  this->p = p;
  this->i = i;
  this->d = d;
  this->velocidade = velocidade;
  this->tempo = tempo;
  this->erroAcumulado = erroAcumulado;
}

void Configuracao::definirPorChave (char* chave, char* valor){
    uint8_t tempUint8;
    float tempFloat;
    if(strncmp(chave,"id",2)==0){
      tempUint8 = atoi(valor);
      this->id = tempUint8;
      return;
    }
    if(strncmp(chave,"setor",5)==0){
      tempUint8 = atoi(valor);
      this->id = tempUint8;
      return;
    }
    if(strncmp(chave,"velocide",8)==0){
      tempUint8 = atoi(valor);
      this->velocidade = tempUint8;
      return;
    }
    if(strncmp(chave,"kp",2)==0){
      tempFloat = atof(valor);
      this->p = tempFloat;
      return;
    }
    if(strncmp(chave,"kd",2)==0){
      tempFloat = atof(valor);
      this->d = tempFloat;
      return;
    }
    if(strncmp(chave,"ki",2)==0){
      tempFloat = atof(valor);
      this->i = tempFloat;
      return;
    }
}

float Configuracao::obterP(){
  return this->p;
}

void Configuracao::definirP(float p){
  this->p = p;
}

float Configuracao::obterI(){
  return this->i;
}

void Configuracao::definirI(float i){
  this->i = i;
}

float Configuracao::obterD(){
  return this->d;  
}

void Configuracao::definirD(float d){
  this->d = d;
}

uint32_t Configuracao::obterTempo(){
  return this->tempo;
}

void Configuracao::definirTempo(uint32_t t){
  this->tempo = t;
}

uint32_t Configuracao::obterVelocidade(){
  return this->velocidade;
}

void Configuracao::definirVelocidade(uint32_t v){
  this->velocidade = v;
}

uint32_t Configuracao::obterErroAcumulado(){
  return this->erroAcumulado;
}

void Configuracao::definirErroAcumulado(uint32_t ea){
  this->erroAcumulado = ea;
}
