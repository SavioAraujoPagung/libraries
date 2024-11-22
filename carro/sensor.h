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

        void adc_muda_porta(int16_t porta);
        void adc_liga_gnd();
        void adc_ativa();
        uint16_t adc_read();
        void calibra_sensor();
        void le_calibracao_sensor_linha();
        void verifica_linha();
        void adc_desativa();
        uint8_t get_debug();


    public:
        Sensor();
        void inicia_sensor();
        bool atualiza_sensor();
        uint8_t obtem_intensidade(uint8_t i);
        
        static float calcula_error(int16_t a, int16_t b);
        static bool na_linha(uint8_t sensor);
        static bool na_linha(uint8_t e, uint8_t d);
};

#endif