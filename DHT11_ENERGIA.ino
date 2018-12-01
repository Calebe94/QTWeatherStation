/* 
 *  Trabalho de Oficina de Programação
 *  Aluno: Maximiliano ...
 */

#include <dht.h> // Biblioteca Utilizada para a utilização do sensor DHT11

#define DHT11_PIN PD_0 // Pino PD_0 utilizado para ler o sensor DHT11

dht DHT; // Criação da Instância(classe) do DHT11

void print_temperature(); // Imprime a temperatura na Serial

void print_humidity(); // Imprime a humidade na Serial

// int main(void){ // Não é necessário main() no ARDUINO

void setup() // Função que é chamada uma única vez na inicialização do programa
{
  Serial.begin(9600); // Inicializa a UART0 para a transmição de dados
}

void loop() // while(1) // esse é o loop infinito do ARDUINO
{
  if(Serial.available() > 0) // Sempre que houver algum byte na serial ele entra aqui
  {
    char incoming_char = Serial.read(); // Lê o valor da serial e atribui na variável incoming_char 

    switch(incoming_char) // Escolho oque vou fazer com o byte recebido
    {
      case 't': // Se for 't' de "Temperature" ou "Temperatura"
        print_temperature(); // Envio o valor da temperatura lida do sensor na serial
        break;
      case 'h': // Se for 'h' de "Humidity" ou "(h)Umidade"
        print_humidity(); // Envio o valor da umidade lida do sensor na serial
        break;
    }
  }
}

// } // Fecha o main(), mas lembre-se, não existe essa função no ARDUINO

void print_temperature() // Imprime a temperatura na Serial
{
  int chk = DHT.read11(DHT11_PIN); // Leio o Sensor de temperatura
  if (!isnan(DHT.temperature)) // Verifico se o sensor retornou algum valor
  {
    Serial.println(DHT.temperature); // Se há algum valor eu envio pela serial
  }
}

void print_humidity() // Imprime a temperatura na Serial
{
  int chk = DHT.read11(DHT11_PIN); // Leio o Sensor de temperatura
  if (!isnan(DHT.humidity))  // Verifico se o sensor retornou algum valor
  {
    Serial.println(DHT.humidity); // Se há algum valor eu envio pela serial
  }
}
