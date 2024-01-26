/*

*/

#define BRIGHTNESS_MAX 255
#define BRIGHTNESS_MIN 20
#define BRIGHTNESS_STEP 2
uint8_t BRIGHTNESS_Current = BRIGHTNESS_MIN;
int pageAtual = 0;
int pageLast = 0;  //Salvar na EEPROM
void buzzer() {
  hmi.beepHMI();
}
void loopDisplay() {
  pageAtual = hmi.getPage();
  //Serial.println(String(pageAtual)+" - "+String(pageLast));
  if (pageAtual != pageLast) {
    updatePage(pageLast, pageAtual);
    Serial.println(String(pageLast) + " -> " + String(pageAtual));
    pageLast = pageAtual;
    Serial.println("Mudou a Tela");
  }
  vTaskDelay(100);
}
void brilhoDisplay(byte _percentual) {  // 5A A5 04 82 00 82 01
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
long fuctionTransitionsValue[PAGES_TOTAL][PAGES_TOTAL];
void updatePage(int _pAtual, int _pLast) {
  fuctionTransitionsValue[_pAtual][_pLast];
}



void testPageAll() {  //Passa por todas as telas
  for (int i = 0; i < PAGES_TOTAL; i++) {
    hmi.setPage(i);
    vTaskDelay(pdMS_TO_TICKS(750));
  }
}
void fadeInBrigthness() {
  for (int i = BRIGHTNESS_MIN; i < BRIGHTNESS_Current; i++) {
    hmi.setBrightness(i);
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
void fadeOutBrigthness() {
  for (int i = BRIGHTNESS_Current; i > BRIGHTNESS_MIN; i--) {
    hmi.setBrightness(i);
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
void switchPageWithFadeBrightness(int pageDestiny) {
  fadeInBrigthness();
  hmi.setPage(pageDestiny);
  fadeOutBrigthness();
}
bool checkSensorWithExperiments(int modo, int porta, int ){
  if (modo == MODO_LEITURALIVRE) {
    return true;
  } else {
    switch (modo) {
      case EXPERIMENTO_MAT_1:
        return true;
        break;
      case EXPERIMENTO_MAT_2:
        return true;
        break;
      case EXPERIMENTO_MAT_3:
        return true;
        break;
      case EXPERIMENTO_MAT_4:
        return true;
        break;
      case EXPERIMENTO_MAT_5:
        return true;
        break;
      case EXPERIMENTO_MAT_6:
        return true;
        break;

      case EXPERIMENTO_BIO_1:
        return true;
        break;
      case EXPERIMENTO_BIO_2:
        return true;
        break;
      case EXPERIMENTO_BIO_3:
        return true;
        break;
      case EXPERIMENTO_BIO_4:
        return true;
        break;
      case EXPERIMENTO_BIO_5:
        return true;
        break;
      case EXPERIMENTO_BIO_6:
        return true;
        break;

      case EXPERIMENTO_FIS_1:
        return true;
        break;
      case EXPERIMENTO_FIS_2:
        return true;
        break;
      case EXPERIMENTO_FIS_3:
        return true;
        break;
      case EXPERIMENTO_FIS_4:
        return true;
        break;
      case EXPERIMENTO_FIS_5:
        return true;
        break;
      case EXPERIMENTO_FIS_6:
        return true;
        break;

      case EXPERIMENTO_QUI_1:
        return true;
        break;
      case EXPERIMENTO_QUI_2:
        return true;
        break;
      case EXPERIMENTO_QUI_3:
        return true;
        break;
      case EXPERIMENTO_QUI_4:
        return true;
        break;
      case EXPERIMENTO_QUI_5:
        return true;
        break;
      case EXPERIMENTO_QUI_6:
        return true;
        break;
    }
  }
}
void showVariableByteBySensor(int modo, int sensor, long addressVP, byte value) {
  hmi.setVP(addressVP, value);
}
void showVariableIntBySensor(int modo, int sensor, long addressVP, int value) {
  hmi.setVP_Int(addressVP, value);
}
void showVariableLongBySensor(int modo, int sensor, long addressVP, long value) {
  hmi.setVP_Long(addressVP, value);
}
void showVariableFloatBySensor(int modo, int sensor, long addressVP, float value) {
  hmi.setVP_Float(addressVP, value);
}
void showVariableByteInCurveDisplay(int modo, int sensor, byte channel, byte value){

}
//void graphChannel
//hmi.pushValueGraph(CHANNEL_UMIDADE, humidity,0x01);

// MUDAR DE TELA    -   5A  A5  04  80  03  00  04


// O que é importante programar no DWIN
// Variable Icon - 34
// alterarVariableIcon(byte numberIcon);
//
// Vídeo - https://www.youtube.com/watch?v=bemhhAqr9BM
// playVideo();
// pauseVideo();
// hideVideo();
// stopVideo();
// resumeVideo();
//
// Convert Video to Animation - https://www.youtube.com/watch?v=qC8ZJX2qIxA
//
// Animation Icon Demo - https://www.youtube.com/watch?v=5ofAa9RmP38&t=209s
//
// QRCode - vp 1000 sp 2000 - https://www.youtube.com/watch?v=svhgAlYmlZ4&t=136s
// showQRCode();
// hideQRCode();
// reduceQRCode();
// enlargeQRCode();
// chanceQRCode();
//
// Music    -   https://www.youtube.com/watch?v=9lmomCyLOek&list=PLKfWyFPPaoDoNWXWGr1tCCIvTxLw5O634&index=7
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
// Draw Graphic   -   https://www.youtube.com/watch?v=jn3_Ex4sULM

// Icon Superposition - https://www.youtube.com/watch?v=UXHSvxIYnbk
//
// Icon Rotation  - https://youtu.be/c16joloRxP8?si=RNchaEeEXoxgNImJ
//
// Rotation Adjustment - https://www.youtube.com/watch?v=eu-XjWb2rAA

// Bit Icon - https://www.youtube.com/watch?v=_QBIQVi-ZTs

// Slider Display - https://www.youtube.com/watch?v=HNq8ZOEPGhs
//

// Roller Character - https://www.youtube.com/watch?v=M5pz_mCLt2c

// Artistic Variables - https://www.youtube.com/watch?v=eqBINvGn3bY

// Pointer Icon Overlay - https://www.youtube.com/watch?v=BWNop73y9NM

// Draw Rectangle - https://youtu.be/f4gCXvWkg48?si=hnXOr1Z4HxSb_SRa

// SYNCHRO Data Return - https://www.youtube.com/watch?v=tv-ca9lGTIw

// RTC Time SET - https://www.youtube.com/watch?v=Bii0ar5f_Zg&t=3s

// Transmitting text between the display and PC or Arduino - https://www.youtube.com/watch?v=d_susa-41zM

// PopUp Menu - https://www.youtube.com/watch?v=O-AxCsQ6yCo

// Text Input - https://www.youtube.com/watch?v=dd2aR9k2ptk
// Text Display  -   https://www.youtube.com/watch?v=lCtiVFDynVM
// Difference between DGUSII text and Text display -  https://www.youtube.com/watch?v=zX4bjhzRxOc

// Roller Character -   https://www.youtube.com/watch?v=M5pz_mCLt2c

// Save data into flash - https://www.youtube.com/watch?v=7u4UsO_iW0Q
// Read-Write Fuction of Flash    -   https://www.youtube.com/watch?v=thKURgsK2gs

// SetCFG - https://www.youtube.com/watch?v=xlTQCzlsYqM

// eraseDisplay();

// Simulation Touch - https://youtu.be/fvQypjs7CE8?si=6GOwb8Pj7gt50baJ

// Multilingual Interface - https://www.youtube.com/watch?v=Pokubl0EnW0

// Brightness Adjustment  - https://www.youtube.com/watch?v=CkWxX4tRJ7g   -   https://www.youtube.com/watch?v=KoTL4wv8oFw
// Area Brightness Adjustment   -   https://www.youtube.com/watch?v=8ipvrwnOJrs

// HEX Variable Control   - https://www.youtube.com/watch?v=w02t5qjb990

// 