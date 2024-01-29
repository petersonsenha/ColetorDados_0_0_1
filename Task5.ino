/*
    T   A   S   K       5   -   Serial
*/
String rx;
void Task5code(void* pvParameters) {
  for (;;) {
    if(Serial.available()){
      rx = Serial.readStringUntil('\r\n');
      treatSerial(rx);
    }
    vTaskDelay(1);
    rx="";
  } 
}
void treatSerial(String rx){
  if(rx.startsWith("B")){treatBrilho(rx.substring(1,rx.length()));}
  if(rx.startsWith("P")){treatPage(rx.substring(1,rx.length()));}
  rx="";
}
void treatBrilho(String rx){
  String rx_aux = rx.substring(1,rx.length());
  byte brilho = byte(rx.toInt());
  Serial.println("Brilho configurado para : "+String(rx.toInt()));
  hmi.setBrightness(brilho);
  brilhoDisplay(brilho);
}
void treatPage(String rx){
  hmi.beepHMI();
  String rx_aux = rx.substring(1,rx.length());
  int page = byte(rx.toInt());
  Serial.println("Indo para página : "+String(page));
  hmi.setPage(page);
  rx="";
}