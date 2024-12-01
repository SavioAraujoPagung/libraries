#ifndef sensor
#define sensor

#include <stdlib.h>

#define QUANTIDADE_LEDS 8

class Sensor{
    private:
        int16_t i;
        int16_t valor; 
        int16_t calibracao[QUANTIDADE_LEDS];
        int16_t maximo[QUANTIDADE_LEDS];
        int16_t minimo[QUANTIDADE_LEDS];
        int16_t intensidadeLeds[QUANTIDADE_LEDS];
        int16_t valorBruto[QUANTIDADE_LEDS];
        int16_t saida;
        uint8_t debug; 

        void _adcMudaPorta(int16_t porta);
        void _adcLigaGnd();
        void _adcAtiva();
        uint16_t _adcRead();
        void _calibraSensor();
        void _leCalibracaoSensorLinha();
        void _verificaLinha();
        void _adcDesativa();
        uint8_t _getDebug();


    public:
        Sensor();
        void iniciaSensor();
        bool atualizaSensor();
        uint8_t obtemIntensidade(uint8_t i);
        
        static float calculaError(int16_t a, int16_t b);
        static bool naLinha(uint8_t sensor);
        static bool naLinha(uint8_t e, uint8_t d);
};

#endif