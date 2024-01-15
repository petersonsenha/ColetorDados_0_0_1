/*

*/

#define BRIGHTNESS_MAX  255
#define BRIGHTNESS_MIN  20
#define BRIGHTNESS_STEP 2
uint8_t BRIGHTNESS_Current= BRIGHTNESS_MIN;
int pageAtual=0;
int pageLast=0; //Salvar na EEPROM
void buzzer(){
  hmi.beepHMI();
}
void loopDisplay(){
  pageAtual = hmi.getPage();
  //Serial.println(String(pageAtual)+" - "+String(pageLast));
  if(pageAtual != pageLast){
    updatePage(pageLast,pageAtual);
    Serial.println(String(pageLast)+" -> "+String(pageAtual));
    pageLast=pageAtual;
    Serial.println("Mudou a Tela");
  }
}
void brilhoDisplay(byte _percentual){ // 5A A5 04 82 00 82 01
  hmi.beepHMI();
  hmi.setBrightness(_percentual);
  Serial2.write(0xA5);
  Serial2.write(0x5A);
  Serial2.write(0x04);
  Serial2.write(0x82);
  Serial2.write(0x00);
  Serial2.write(0x82);
  Serial2.write(_percentual);
}
long  fuctionTransitionsValue[PAGES_TOTAL][PAGES_TOTAL];
void updatePage(int _pAtual, int _pLast){
  fuctionTransitionsValue[_pAtual][_pLast];
}



void testPageAll(){                           //Passa por todas as telas
  for(int i=0;i<PAGES_TOTAL;i++){
    hmi.setPage(i);
    vTaskDelay(pdMS_TO_TICKS(750));
  }
}
void fadeInBrigthness(){
  for(int i=BRIGHTNESS_MIN;i<BRIGHTNESS_Current;i++){
    hmi.setBrightness(i);
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
void fadeOutBrigthness(){
  for(int i=BRIGHTNESS_Current;i>BRIGHTNESS_MIN;i--){
    hmi.setBrightness(i);
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
void switchPageWithFadeBrightness(int pageDestiny){
  fadeInBrigthness();
  hmi.setPage(pageDestiny);
  fadeOutBrigthness();
}
void graphChannel
//hmi.pushValueGraph(CHANNEL_UMIDADE, humidity,0x01);

// O que é importante programar no DWIN
// Variable Icon - 34
// alterarVariableIcon(byte numberIcon);
//
// Vídeo - 
// playVideo();
// pauseVideo();
// hideVideo();
// stopVideo();
// resumeVideo();
// 
// QRCode - vp 1000 sp 2000
// showQRCode();
// hideQRCode();
// reduceQRCode();
// enlargeQRCode();
// chanceQRCode();
// 
// Image Animation - https://www.youtube.com/watch?v=IArN3T2LFB0
// ICL Generation -> 
//
// Icon Page Tran - https://www.youtube.com/watch?v=Dm5RbSn_vMY
// Icon -> 48.icl
// Icon Page Tran (Display Control) 
// Seleciona a área 
// Sliding Icon sel

// Curve Display - https://www.youtube.com/watch?v=rKTbUHRNPGg
// up/down vertical - 1008 (int)
// up/down horintal - 1009 (low byte)
// showCurve();
// hideCurve();
// changeColor();
// changeLineWidth();
// up
//
// Icon Superposition - https://www.youtube.com/watch?v=UXHSvxIYnbk
// 

// Rotation Adjustment - https://www.youtube.com/watch?v=eu-XjWb2rAA
//

// Slider Display - https://www.youtube.com/watch?v=HNq8ZOEPGhs
//

// Roller Character - https://www.youtube.com/watch?v=M5pz_mCLt2c

// Artistic Variables - https://www.youtube.com/watch?v=eqBINvGn3bY

// Pointer Icon Overlay - https://www.youtube.com/watch?v=BWNop73y9NM

// Draw Rectangle - https://youtu.be/f4gCXvWkg48?si=hnXOr1Z4HxSb_SRa

// SYNCHRO Data Return - https://www.youtube.com/watch?v=tv-ca9lGTIw

// RTC Time SET - https://www.youtube.com/watch?v=Bii0ar5f_Zg&t=3s

// Transmitting text between the display and PC or Arduino - https://www.youtube.com/watch?v=d_susa-41zM

// eraseDisplay();