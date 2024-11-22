#ifndef EEPROMDatabase
#define EEPROMDatabase

#include <EEPROM.h>
#include <stdio.h>

class Database
{
private:
  static void gravar_configuracao(char *data);

public:
  static void grava_configuracao_setores(char **datas);
  static void recupera_configuracao_setores(char **datas);
};

#endif