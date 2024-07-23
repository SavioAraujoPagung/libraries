#ifndef EEPROMDatabase
#define EEPROMDatabase

#include <EEPROM.h>
#include <stdio.h>

#define ENDERECO_BASE 200
#define ENDERECO_SETOR_INICIAL 198
#define ENDERECO_PULSOS_LIMITE 196
#define ENDERECO_PULSOS_MARCACAO 194

#define QUANTIDADE_SETORES 15

class Database
{
  private: 
    static void gravarConfiguracao(char* data);

  public: 
    static void gravaConfiguracaoSetores(char** datas);
    static void recuperaConfiguracaoSetores(char** datas);
};



#endif