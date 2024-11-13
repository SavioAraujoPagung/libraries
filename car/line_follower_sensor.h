#ifndef sensor
#define sensor
#include <stdlib.h>

class Sensor{
    #define INICIO_SENSOR_LINHA 0
    #define FIM_SENSOR_LINHA 1
    #define BOTAO 10
    #define PINO_LEITURA_BATERIA 7
    #define PRESSIONADO LOW
  
    //atributos
    private:
        uint8_t i;
        int16_t valor; 
        int16_t calibracao[8];
        int16_t maximo[8];
        int16_t minimo[8];
        int8_t intensidadeLeds[8];
        int16_t valorBruto[8];
        uint8_t saida;
        uint8_t debug; 

        void adc_muda_porta(uint8_t porta);
        void adc_liga_gnd();
        void adc_ativa();
        uint16_t adc_read();
        void calibration_sensor();
        void read_calibration_sensor_line();
        void check_line();

    public:
        Sensor();
        void start_sensor();
        void adc_desativa();
        bool update_sensor();
        uint8_t get_intensity(uint8_t i);
        uint8_t get_debug();
        
        static float calculate_error(int16_t a, int16_t b);
        static bool in_line(int16_t sensor);
        static bool in_line(uint8_t e, uint8_t d);
};

#endif