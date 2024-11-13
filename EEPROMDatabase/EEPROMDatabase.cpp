#include "EEPROMDatabase.h"

static void Database::_gravarConfiguracao(char* data) {
  uint16_t posicaoMemoria = ENDERECO_BASE + sizeof(char) * sizeof(data);
  EEPROM.put(posicaoMemoria, data); 
}

static void Database::gravaConfiguracaoSetores(char** datas){
  if (datas == NULL) {
    return;
  }

  EEPROM.put(ENDERECO_SETOR_INICIAL, 0);
  EEPROM.put(ENDERECO_PULSOS_LIMITE, 0);
  EEPROM.put(ENDERECO_PULSOS_MARCACAO, 0);

  for(uint16_t i=0; i < QUANTIDADE_SETORES; i++){
    _gravarConfiguracao(datas[i]);
  }
}

static void Database::recuperaConfiguracaoSetores(char** datas){
  int zero;
  zero = 0;
  EEPROM.get(ENDERECO_SETOR_INICIAL, zero);
  EEPROM.get(ENDERECO_PULSOS_LIMITE, zero);
  EEPROM.get(ENDERECO_PULSOS_MARCACAO, zero);

  uint16_t posicaoMemoria;

  for(uint16_t i=0; i < QUANTIDADE_SETORES; i++){
    posicaoMemoria = ENDERECO_BASE + i * sizeof(datas);
    EEPROM.get(posicaoMemoria, datas[i]);
  }
}
