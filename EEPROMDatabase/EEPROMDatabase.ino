#include "EEPROMDatabase.h"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  char dataVelocidade = "velociadade: 12";
  char dataErrorAcomulado = "errorAcomulado: 15";

  char **data; 
  data = malloc (1 * sizeof (char *));
  for (int i = 0; i < 2; ++i) 
  {
    data[i] = malloc (20 * sizeof (char));
  }

  data[0] = &dataVelocidade;
  data[1] = &dataErrorAcomulado;

  Database::gravaConfiguracaoSetores(data);
}
