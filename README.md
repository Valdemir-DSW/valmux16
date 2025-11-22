# valmux16
It facilitates the use of analog multiplexers (MUX).

```
/*
  Exemplo de uso da biblioteca VALMUX16
  -------------------------------------
  Este exemplo mostra como utilizar o multiplexador de 16 canais
  para expandir o número de entradas analógicas do seu Arduino.
  
  Com ele, você pode ligar vários multiplexadores e, por exemplo,
  adicionar dezenas de entradas extras ao seu projeto.
*/

#include <VALMUX16.h>

// Configuração dos pinos de seleção do MUX
VALMUX16 mux(2, 3, 4, 5); // pinos S0, S1, S2, S3 do MUX

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando VALMUX16...");

  // Define a quantidade de multiplexadores conectados
  mux.setMuxCount(2); // exemplo com 2 multiplexadores

  // Define os pinos de Enable para cada multiplexador
  mux.setEnable(0, 6); // MUX 0 com Enable no pino 6
  mux.setEnable(1, 7); // MUX 1 com Enable no pino 7

  // Define o pino ADC interno do Arduino que irá ler os sinais do MUX ( sim a saída de todos os multiplexadores é ligada no mesmo ponto )
  mux.setInternalAdcPin(A0);

  // Inicializa o MUX
  mux.begin();

  Serial.println("VALMUX16 pronto!");
}

void loop() {
  // Lê o valor linear do MUX. Pode especificar até 32 entradas se tiver 2 MUXs
  int valor = mux.readLinear(10); // lê a entrada 10 (considerando todos os MUXs)

  // Mostra o valor lido no Serial Monitor
  Serial.print("Valor lido no canal 10: ");
  Serial.println(valor);

  delay(200); // aguarda 200ms
}

/*
  Como funciona:

  - readLinear(n): recebe o número linear do canal que você quer ler.
    Se você tem 2 multiplexadores de 16 canais, os canais lineares vão de 0 a 31.

  - setMuxCount(n): define quantos multiplexadores você tem ligados.

  - setEnable(idx, pino): define o pino de enable de cada multiplexador.

  - setInternalAdcPin(pino): define qual pino do Arduino será usado para leitura analógica.

 
*/

```
Também é possível anexar o modulo ADC externo, por exemplo, o modo ADS-1115. Veja isso nos exemplos de como utilizar fonte ADC externa.

<img width="260" height="248" alt="image" src="https://github.com/user-attachments/assets/465a2d15-b211-48a1-81b0-8a3d0dcd9b1a" />

