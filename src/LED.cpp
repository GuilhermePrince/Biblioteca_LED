#include "LED.h"

Led::Led(uint8_t pin) :
    pino(pin), 
    estado(LOW),
    apagarNoTempo(false),
    apagarNoMomento(false),
    piscaLed(false),
    intervaloPisca(0),
    tempoAnterior(0),
    repeticoes(0)
{
    pinMode(pino, OUTPUT);
}

void Led::acender()
{
    estado = HIGH;
    apagarNoTempo = false;
    piscaLed = false;
}

void Led::acender(uint32_t tempoLigado)
{
    estado = HIGH;
    apagarNoTempo = true;
    apagarNoMomento = millis() + tempoLigado;

    piscaLed = false;
}

void Led::apagar()
{
    estado = LOW;
    apagarNoTempo = false;
    piscaLed = false;
}


void Led::alternar()
{
    estado = !estado;
    apagarNoTempo = false;
    piscaLed = false;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
    apagarNoTempo = false;
    piscaLed = false;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::piscar()
{
    piscaLed = true;
    intervaloPisca = 500;
    tempoAnterior = millis();
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;

}

void Led::piscar(float freq)
{
    if(freq == 0) return;
    piscaLed = true;
    intervaloPisca = (1000.0f / (2.0f * freq));
    tempoAnterior = millis();
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}

void Led::piscar(float freq, uint16_t repeticoes)
{
    if(freq == 0) return;
    piscaLed = true;
    intervaloPisca = (1000.0f / (2.0f * freq));
    tempoAnterior = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
    apagarNoTempo = false;

}

void Led::update()
{
    if(piscaLed)  funcaoPiscaLed();

    if(apagarNoTempo)   funcaoApagaLed();

    digitalWrite(pino, estado);
}



void Led::funcaoApagaLed()      //*Funcao privada para deixar o codigo limpo, desliga a funcao acender(tempoLigado)
{
     if(millis() >= apagarNoMomento)
        {
            estado = LOW;
            apagarNoTempo = false;
        }
}

void Led::funcaoPiscaLed()      //*Funcao privada para deixar o codigo limpo, desliga a funcao piscar() e suas sobrecargas
{
    if(millis() - tempoAnterior >= intervaloPisca) 
        {
            estado = !estado;
            tempoAnterior = millis();
            if(repeticoes > 0)
            {
                repeticoes--;
                if(repeticoes == 0)
                {
                    piscaLed = false;
                    estado = LOW;
                }
            }
        }
        

}



