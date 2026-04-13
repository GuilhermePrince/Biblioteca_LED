#ifndef LED_h

#define LED_h


#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * 
 * Permite ligar, desligar, ligar por um tempo determinado,
 * piscar continuamente e piscar por uma quantidade definida
 * 
 * 
 * @note O método update() deve ser utilizado continuamente dentro do loop
 */
class Led
{
    private:
        uint8_t pino;
        bool estado;
        bool apagarNoTempo;
        uint32_t apagarNoMomento;
        bool piscaLed;
        uint32_t intervaloPisca;
        uint32_t tempoAnterior;
        uint16_t repeticoes;

        /**
         * @brief Processa o desligamento temporizado.
         */
        void funcaoApagaLed();

        /**
         * @brief Processa a lógica de piscada do LED.
         */
        void funcaoPiscaLed();

    public:

        /**
         * @brief Constrói um objeto LED.
         * 
         * @param pin - Número do pino digital onde o LED está conectado.
         */
        Led(uint8_t pin);

        /**
         * @brief Liga o LED continuamente.
         */
        void acender(); 

        /**
         * @brief Liga o LED por tempo determinado
         * 
         * @param tempoLigado - Tempo em milissegundos que o LED ficará ligado
         */
        void acender(uint32_t tempoLigado);


        /**
         * @brief Desliga o LED e cancela modos automáticos
         */
        void apagar(); 

        /**
         * @brief Faz o LED piscar continuamente a cada segundo (1Hz)
         */
        void piscar();

        /**
         * @brief Faz o LED piscar continuamente com uma frequência determinada
         * 
         * @param freq - Valor de piscadas por segundo, ou seja,  a frequência em Hertz
         */
        void piscar(float freq);

        /**
         * @brief Faz o LED piscar em uma frequência determinada por um tempo determinado.
         * 
         * @param freq - Valor de piscadas por segundo, ou seja,  a frequência em Hertz.
         * @param repeticoes - Define a quantidade de repetições que o LED piscará.
         */
        void piscar(float freq, uint16_t repeticoes);

        void alternar();    //* ok

        void setEstado(bool estado);    //* ok

        uint8_t getPino();  //* ok

        void update();  //* em progresso
};






#endif