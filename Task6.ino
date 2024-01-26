/*
    T   A   S   K       6   -   O   T   A
*/
void Task6code(void* pvParameters) {
  Serial.println("OTA Inicializado");
  setupWifi();
  for (;;) {
    ArduinoOTA.handle();
    vTaskDelay(1);
  } 
}