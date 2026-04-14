/**
 * Exemplo de como utilizar a função acender(tempoLigado), nesta biblioteca
 * A função possui um parâmetro para definir o tempo que deve estar ligado
 * 
 */








#include <Arduino.h>

#include <LED.h>

Led ledA(36);

bool jaExecutou = false; //Esta variável serve para verificar se a função já foi verificada

void setup() 
{
  //Não é necessário colocar nada no setup()
}

void loop()
{
  ledA.update(); //Este método atualiza a saídas, deve ser colocado obrigatoriamente no loop()

  if(!jaExecutou) //Verifica se o LED já foi acendido
  {
    ledA.acender(5000); //Acende o LED por 5 segundos, o valor está em milissegundos
    jaExecutou = true;  //Valida a execução e troca o valor de jaExecutou para Verdadeiro
  }
}

