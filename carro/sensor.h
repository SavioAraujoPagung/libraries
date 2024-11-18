#ifndef sensor
#define sensor

#include <stdlib.h>

class Sensor{
    private:
        int16_t i;
        int16_t valor; 
        int16_t calibracao[8];
        int16_t maximo[8];
        int16_t minimo[8];
        int16_t intensidadeLeds[8];
        int16_t valorBruto[8];
        int16_t saida;
        uint8_t debug; 

        void adc_muda_porta(int16_t porta);
        void adc_liga_gnd();
        void adc_ativa();
        uint16_t adc_read();
        void calibraSensor();
        void leCalibracaoSensorLinha();
        void verificaLinha();

    public:
        Sensor();
        void iniciaSensor();
        void adc_desativa();
        bool atualizaSensor();
        uint8_t obtemIntensidade(uint8_t i);
        uint8_t get_debug();
        
        static float calculate_error(int16_t a, int16_t b);
        static bool in_line(uint8_t sensor);
        static bool in_line(uint8_t e, uint8_t d);
};

#endif