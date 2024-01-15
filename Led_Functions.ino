//***********************************************************************************************************************
/*
  LED de Status
  Vermelho    |   Significa que não está funcionando
  Verde       |   Significa que está funcionando
  Azul        |   Significa que está esperando conexão

*/
//***********************************************************************************************************************
#define STATUS_OK         0
#define STATUS_BLOCKED    1
#define STATUS_WAITING    2
uint8_t stateLed=0;
uint8_t stateLedLast=stateLed;

void setupLed(){
  digitalWrite(RGB_BUILTIN, HIGH);   // Turn the RGB LED white
  vTaskDelay(pdMS_TO_TICKS(1000);
  digitalWrite(RGB_BUILTIN, LOW);    // Turn the RGB LED off
  vTaskDelay(pdMS_TO_TICKS(1000);
}
void testeLed(){
  neopixelWrite(RGB_BUILTIN,0,0,RGB_BRIGHTNESS); // Blue
  vTaskDelay(pdMS_TO_TICKS(1000));
  neopixelWrite(RGB_BUILTIN,0,RGB_BRIGHTNESS,0); // Blue
  vTaskDelay(pdMS_TO_TICKS(1000));
  neopixelWrite(RGB_BUILTIN,RGB_BRIGHTNESS,0,0); // Blue
  vTaskDelay(pdMS_TO_TICKS(1000));
  neopixelWrite(RGB_BUILTIN,0,0,0); // Blue
}
void loopLed(){
}
void statusLed(int status){
  switch (status){
    case STATUS_OK:
      neopixelWrite(RGB_BUILTIN,0,0,RGB_BRIGHTNESS); // Blue
      stateLed=STATUS_OK;
      break;
    case STATUS_BLOCKED:
      neopixelWrite(RGB_BUILTIN,0,0,RGB_BRIGHTNESS); // Blue
      stateLed=STATUS_BLOCKED;
      break;
    case STATUS_WAITING:
      neopixelWrite(RGB_BUILTIN,0,0,RGB_BRIGHTNESS); // Blue
      stateLed=STATUS_WAITING;
      break;
    default:
      neopixelWrite(RGB_BUILTIN,0,0,0); // Black
      break;
    
  }
}