#include <SoftwareSerial.h>
#include <string.h> 
#include <stdlib.h>

#define FORA 10
#define QUANTIDADE_SETORES 15

class Setting {
  public:
    Configuracao(int id, float p, float d, float i, int16_t velocidade, uint32_t tempo, int32_t erroAcumulado);
    int id; //savio, idSetor
    float p;
    float d;
    float i;
    int16_t velocidade;
  
    //parte do relatorio para envio
    uint32_t tempo; //todo, savio isso aqui é a parte que enviar para o servidor o relatório feita com os dados da corrido 
    int32_t erroAcumulado;

    void insereValorCalibracao (char* chave, char* valor);

  /*essa função aqui faz leitura dos dados por JSON via string, fiz meu próprio parser*/
  public: 
    static bool calibraVeiculo(Configuracao setores[]);
    static void inicioCalibracao(Configuracao setores[]);
};