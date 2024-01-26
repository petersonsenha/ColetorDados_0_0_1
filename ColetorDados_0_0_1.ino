//***********************************************************************************************************************
/* https://emojipedia.org/  -   Emojis : 🔘  ✅  ❌  💪🏾 🚩  ▶️   ⚙️    ℹ️
  Microcontrolador : ESP32S3N16R8
  Display : DMG80480C070_03WTC

    🚩Coletor de Dados - Comunicação com a Placa do Sensor - Versão 0.0.1                                           [27/12/2023]  ->  [//]
      ✅  0.0.1   --- [Sensor]    Comunicação com OneWire                                                                   [//]  ->  [//]
      🔘  0.0.2   --- [Display]   Função que Exibe os dados do sensor em uma variável numérica                              [27/12/2023]  ->  [//]
      🔘  0.0.3   --- [WebServer] Função que Exibe os dados do sensor em uma variável numérica                              [27/12/2023]  ->  [//]
      🔘  0.0.4   --- [ESP32]     Função que verifica a conexão entre os sensores e lista qual sensor está conectado        [27/12/2023]  ->  [//]
      🔘  0.0.5   --- [ESP32]     Função que verifica a conexão entre os sensores e lista qual sensor está conectado        [27/12/2023]  ->  [//]
      🔘  0.0.6   --- [Display]   Função que verifica qual sensor pode ser utilizado em qual canal                          [27/12/2023]  ->  [//]
      🔘  0.0.7   --- [ESP32]     Função que verifica qual sensor pode ser utilizado em qual canal                          [27/12/2023]  ->  [//]
      🔘  0.0.8   --- [Display]   Função que Exibe os dados do sensor em um canal de gráfico                                [27/12/2023]  ->  [//]
      🔘  0.0.9   --- [Display]   Criar tela para cada sensor explicando seu funcionamento                                  [27/12/2023]  ->  [//]
      🔘  0.0.10   --- [Display]   Conseguir pegar os dados de 4 tipos e mostrar no display (Bit, Byte, Int, Float)          [//]  ->  [//]
      🔘  0.0.11   --- [ESP32]     Criar modelo de fluxo de telas                                                            [//]  ->  [//]
      🔘  0.0.12   --- [ESP32]     Criar modelo de fluxo de botões e variáveis                                               [//]  ->  [//]
      
  🔘 Coletor de Dados - Experimentos - Versão 0.0.2                                                                 [//]  ->  [//]
      🔘  --- [Display]   Criar as Telas para cada Experimento [Introdução - Experimento - Questionário]            [//]  ->  [//]
      🔘  --- [WebServar] Criar as Telas para cada Experimento [Introdução - Experimento - Questionário]            [//]  ->  [//]
      🔘  --- [ESP32]     Criar OBJETO dos Experimentos de forma genérica e de forma específica                     [//]  ->  [//]
      🔘  --- [Display]   Função que solicita as informações dos experimentos e seus VP                             [//]  ->  [//]
  🔘 Coletor de Dados - Questionários - Versão 0.0.3                                                                                [//]  ->  [//]
      🔘  --- [Display]   Fazer padrão de tela de questionário                                                      [//]  ->  [//]
      🔘  --- [Display]   Organizar padrão de informações sobre a tela de questionário [ btn | Vp | page | Exp ]    [//]  ->  [//]   
      🔘  --- [Display]   Conseguir pegar os dados de 4 tipos e mostrar no display (Bit, Byte, Int, Float)          [//]  ->  [//]
      🔘  --- [Display]   Conseguir pegar os dados de 4 tipos e mostrar no display (Bit, Byte, Int, Float)          [//]  ->  [//]
      
  🔘 Coletor de Dados - Versão 0.0.4                                                                                [//]  ->  [//]
      🔘  --- [Display]   Gerar uma máquina de estados finitas para o display                                       [//]  ->  [//]
      🔘  --- [WebServer] Subir os dados para o WebServer de acordo com qual página esteja                          [//]  ->  [//]
      🔘  --- [WebServer] Criar páginas para o WebServer de acordo com qual experimento esteja                      [//]  ->  [//]
  🔘 Coletor de Dados - STATUS do Equipamento - Versão 0.0.5                                                                                [//]  ->  [//]
      ✅  --- [ESP32]     Elaborar Status de conexão para o LED RGB                                                 [//]  ->  [//]
      ✅  --- [ESP32]     Obter Tensão e Corrente do Equipamento                                                    [//]  ->  [//]
      🔘  ---                                                                             [//]  ->  [//]
  🔘 Coletor de Dados - Atualização do Display pelo ESP32   -   Versão 0.0.5                                        [//]  ->  [//]
      ✅  --- [ESP32]     Receber arquivos .bin e .icl e armazenar na memória do ESP32                              [//]  ->  [//]
      🔘  --- [Display]   Enviar arquivo .bin e .icl para o display através de script python                        [//]  ->  [//]
      🔘  --- [ESP32]     Criar função para enviar dados de atualização para o display                              [//]  ->  [//]
      🔘  --- [ESP32]     Criar gerenciador de atualização+compatibilidade do display e do firmware                 [//]  ->  [//]
      🔘  --- [ESP32]                                   [//]  ->  [//]
  
*/
//***********************************************************************************************************************
//                                          P     I     N     O     S
#define OneWire_PIN 12
#define OneWire_PIN_1 13
#define OneWire_PIN_2 14
#define OneWire_PIN_3 15  
#define OneWire_PIN_4 16
//***********************************************************************************************************************
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
const char* ssid = "WIFI CITTIUS CORP";
const char* password = "WIFI#2020AP";
void setupWifi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
//***********************************************************************************************************************
#include <DWIN.h>
#define RX_PIN_DWIN 5
#define TX_PIN_DWIN 4

#define ADDRESS_A "1010"
#define ADDRESS_B "1020"
#define PAGES_TOTAL 46
#define DGUS_BAUD 115200

// If Using ESP 32
#if defined(ESP32)
#define DGUS_SERIAL Serial2
DWIN hmi(DGUS_SERIAL, RX_PIN_DWIN, TX_PIN_DWIN, DGUS_BAUD);

// If Using Arduino Uno
#else
DWIN hmi(4, 5, DGUS_BAUD);
#endif
//***********************************************************************************************************************
#define MODO_LEITURALIVRE   5
#define EXPERIMENTO_MAT_1   42
#define EXPERIMENTO_MAT_2   43
#define EXPERIMENTO_MAT_3   44
#define EXPERIMENTO_MAT_4   45
#define EXPERIMENTO_MAT_5   46
#define EXPERIMENTO_MAT_6   47

#define EXPERIMENTO_BIO_1   48
#define EXPERIMENTO_BIO_2   49
#define EXPERIMENTO_BIO_3   50
#define EXPERIMENTO_BIO_4   51  
#define EXPERIMENTO_BIO_5   52
#define EXPERIMENTO_BIO_6   53

#define EXPERIMENTO_FIS_1   54
#define EXPERIMENTO_FIS_2   55
#define EXPERIMENTO_FIS_3   56
#define EXPERIMENTO_FIS_4   57
#define EXPERIMENTO_FIS_5   58
#define EXPERIMENTO_FIS_6   59

#define EXPERIMENTO_QUI_1   60
#define EXPERIMENTO_QUI_2   61
#define EXPERIMENTO_QUI_3   62
#define EXPERIMENTO_QUI_4   63
#define EXPERIMENTO_QUI_5   64
#define EXPERIMENTO_QUI_6   65
//***********************************************************************************************************************
//                  T   A   S   K   S
TaskHandle_t Task1;                   //  One Wire Sensor 1
TaskHandle_t Task2;                   //  One Wire Sensor 2
TaskHandle_t Task3;                   //  One Wire Sensor 3
TaskHandle_t Task4;                   //  One Wire Sensor 4
TaskHandle_t Task5;                   //  Display
TaskHandle_t Task6;                   //  OTA

void ativarTasks() {
  xTaskCreatePinnedToCore(
    Task1code, /* Task function. */
    "Task1",   /* name of task. */
    10000,     /* Stack size of task */
    NULL,      /* parameter of the task */
    1,         /* priority of the task */
    &Task1,    /* Task handle to keep track of created task */
    1);        /* pin task to core 0 */

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
    Task2code, /* Task function. */
    "Task2",   /* name of task. */
    10000,     /* Stack size of task */
    NULL,      /* parameter of the task */
    1,         /* priority of the task */
    &Task2,    /* Task handle to keep track of created task */
    1);        /* pin task to core 1 */
  xTaskCreatePinnedToCore(
    Task3code,
    "Task3",
    10000,
    NULL,
    2,
    &Task3,
    0);

  xTaskCreatePinnedToCore(
    Task4code,
    "Task4",
    10000,
    NULL,
    2,
    &Task4,
    1);
  xTaskCreatePinnedToCore(
    Task5code,
    "Task5",
    10000,
    NULL,
    2,
    &Task5,
    1);
  xTaskCreatePinnedToCore(
    Task6code,
    "Task6",
    10000,
    NULL,
    3,
    &Task6,
    0);
}
//***********************************************************************************************************************
int experimentoAtual() {
  switch (hmi.getPage()) {
    case EXPERIMENTO_MAT_1:
      return EXPERIMENTO_MAT_1;
      //checkSensores(EXPERIMENTO_MAT_1);
      break;
    case EXPERIMENTO_MAT_2:
      return EXPERIMENTO_MAT_2;
      break;
    case EXPERIMENTO_MAT_3:
      return EXPERIMENTO_MAT_3;
      break;
    case EXPERIMENTO_MAT_4:
      return EXPERIMENTO_MAT_4;
      break;
    case EXPERIMENTO_MAT_5:
      return EXPERIMENTO_MAT_5;
      break;
    case EXPERIMENTO_MAT_6:
      return EXPERIMENTO_MAT_6;
      break;
    
    case EXPERIMENTO_BIO_1:
      return EXPERIMENTO_BIO_1;
      break;
    case EXPERIMENTO_BIO_2:
      return EXPERIMENTO_BIO_2;
      break;
    case EXPERIMENTO_BIO_3:
      return EXPERIMENTO_BIO_3;
      break;
    case EXPERIMENTO_BIO_4:
      return EXPERIMENTO_BIO_4;
      break;
    case EXPERIMENTO_BIO_5:
      return EXPERIMENTO_BIO_5;
      break;
    case EXPERIMENTO_BIO_6:
      return EXPERIMENTO_BIO_6;
      break;

    case EXPERIMENTO_FIS_1:
      return EXPERIMENTO_FIS_1;
      break;
    case EXPERIMENTO_FIS_2:
      return EXPERIMENTO_FIS_2;
      break;
    case EXPERIMENTO_FIS_3:
      return EXPERIMENTO_FIS_3;
      break;
    case EXPERIMENTO_FIS_4:
      return EXPERIMENTO_FIS_4;
      break;
    case EXPERIMENTO_FIS_5:
      return EXPERIMENTO_FIS_5;
      break;
    case EXPERIMENTO_FIS_6:
      return EXPERIMENTO_FIS_6;
      break;

    case EXPERIMENTO_QUI_1:
      return EXPERIMENTO_QUI_1;
      break;
    case EXPERIMENTO_QUI_2:
      return EXPERIMENTO_QUI_2;
      break;
    case EXPERIMENTO_QUI_3:
      return EXPERIMENTO_QUI_3;
      break;
    case EXPERIMENTO_QUI_4:
      return EXPERIMENTO_QUI_4;
      break;
    case EXPERIMENTO_QUI_5:
      return EXPERIMENTO_QUI_5;
      break;
    case EXPERIMENTO_QUI_6:
      return EXPERIMENTO_QUI_6;
      break;
    default:
      return 0;
      break;
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupLed();
  //testeLed();
  //setupCurrent();
  hmi.restartHMI();
  hmi.beepHMI();
  switchPageWithFadeBrightness(1);
  hmi.setBrightness(10);
  ativarTasks();
}
void loop() {
  // put your main code here, to run repeatedly:
  disableLoopWDT();
}