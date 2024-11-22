#include "EEPROMDatabase.h"

#define ENDERECO_BASE 200
#define ENDERECO_SETOR_INICIAL 198
#define ENDERECO_PULSOS_LIMITE 196
#define ENDERECO_PULSOS_MARCACAO 194
#define QUANTIDADE_SETORES 15

static void Database::gravar_configuracao(char *data)
{
  uint16_t posicaoMemoria = ENDERECO_BASE + sizeof(char) * sizeof(data);
  EEPROM.put(posicaoMemoria, data);
}

static void Database::grava_configuracao_setores(char **datas)
{
  if (datas == NULL)
  {
    return;
  }

  EEPROM.put(ENDERECO_SETOR_INICIAL, 0);
  EEPROM.put(ENDERECO_PULSOS_LIMITE, 0);
  EEPROM.put(ENDERECO_PULSOS_MARCACAO, 0);

  for (uint16_t i = 0; i < QUANTIDADE_SETORES; i++)
  {
    gravar_configuracao(datas[i]);
  }
}

static void Database::recupera_configuracao_setores(char **datas)
{
  int zero;
  zero = 0;
  EEPROM.get(ENDERECO_SETOR_INICIAL, zero);
  EEPROM.get(ENDERECO_PULSOS_LIMITE, zero);
  EEPROM.get(ENDERECO_PULSOS_MARCACAO, zero);

  uint16_t posicaoMemoria;

  for (uint16_t i = 0; i < QUANTIDADE_SETORES; i++)
  {
    posicaoMemoria = ENDERECO_BASE + i * sizeof(datas);
    EEPROM.get(posicaoMemoria, datas[i]);
  }
}
