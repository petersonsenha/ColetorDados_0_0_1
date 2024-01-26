/*
    RTC Functions   -   Como conectar horário no display 
*/
// Adicionar 

void updateRTC(byte _year, byte _month, byte _day, byte _hour, byte _minute, byte _second){
  // Atualizar os dados do RTC

  // Publicar no Display os dados do RTC
  hmi.setRTC(_year, _month, _day, _hour, _minute, _second);
}