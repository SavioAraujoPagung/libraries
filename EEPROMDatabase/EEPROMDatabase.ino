/*
  Autor: Savio Araujo Pagung
*/

#include "EEPROMDatabase.h"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  char pista = '1';

  char pistas = '12334';

  Database::gravaConfiguracaoSetores(&pistas);
}
