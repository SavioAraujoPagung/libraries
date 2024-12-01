#ifndef EEPROMDatabase
#define EEPROMDatabase

#include <EEPROM.h>
#include <stdio.h>

class Database
{
private:
  static void _gravarConfiguracao(char *data);

public:
  static void gravaConfiguracaoSetores(char **datas);
  static void recuperaConfiguracaoSetores(char **datas);
};

#endif