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
}
void treatBrilho(String rx){
  String rx_aux = rx.substring(1,rx.length());
  static byte brilho = byte(rx.toInt());
  Serial.println("Brilho configurado para : "+String(rx.toInt()));
  hmi.setBrightness(brilho);
  brilhoDisplay(brilho);
}
void treatPage(String rx){
  static int page = rx.toInt();
  hmi.setPage(page);
}