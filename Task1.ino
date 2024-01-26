/*
    T   A   S   K       1   -   MODO LIVRE CANAL 1
*/
void Task1code(void* pvParameters) {
  for (;;) {
    while(hmi.getPage()==EXPERIMENTO_MAT_1){
      // Ordenar os sensores
      // --- Ler o tipo de Sensor de cada porta e definir qual será lido

      // Verificar os Sensores
      // --- Quantos sensores que precisam fazer leitura?
      // --- Quais são os sensores que precisam fazer leituras?

      // Verificar os estados dos Sensores
      // --- Ler mensagem de STATUS da Operação do Sensor
      // --- Ler mensagem do Valor da Operação do Sensor
      


      // Verificar os Botões da Tela
      // --- Rodar a análise das respostas aqui
      // Atualizar as variáveis VP
      // --- Verifica quantas variáveis tem disponíveis
      // --- Verifica quais são as variáveis que estão disponíveis
      
      // Atualizar os Gráficos 
    }
    vTaskDelay(1);    
  } 
}