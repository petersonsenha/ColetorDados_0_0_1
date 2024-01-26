/*
Quais Funções ainda faltam para o protocolo?
  🔘  checkSensores(EXPERIMENTO);
  🔘  getInfoStatus();
  🔘  getSerialNumber();
  🔘  getProductionData();
  🔘  getInfoTypeSensor();
  🔘  checkOneWire(Wire);
  🔘  getOperationEnable(Wire);
  🔘  getOperationValueNow(Wire);
  🔘
  🔘
  🔘
  🔘
  🔘
  🔘
  🔘
  🔘
*/
//**************************************************************************************************************************
//  Pedir os dados via OneWire, Verificar o tipo de sensor.
//  Validar o Tipo de Sensor com a aplicação,Retornar o Valor booleano:
//  TRUE se os sensores estiverem certos, FALSE se estiverem errados
bool checkSensores(int EXPERIMENTO) {
  switch (EXPERIMENTO) {
    case EXPERIMENTO_MAT_1:
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
      //**************************************************************************************************************************
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
      //**************************************************************************************************************************
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
      //**************************************************************************************************************************
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
      //**************************************************************************************************************************
    default:
      return 0;
      break;
  }
}
//**************************************************************************************************************************
byte getInfoStatus(int _wire){

}
//**************************************************************************************************************************
byte getSerialNumber(int _wire){

}
//**************************************************************************************************************************
byte getProductionData(int _wire){

}
//**************************************************************************************************************************
byte getInfoTypeSensor(int _wire){

}
//**************************************************************************************************************************
byte checkOneWire(int _wire){

}
//**************************************************************************************************************************
byte getOperationEnable(int _wire){

}
//**************************************************************************************************************************
byte getOperationValueNow(int _wire){

}
//**************************************************************************************************************************

// Protocolo - Getters & Setters [ ℹ️  INFO | ⚙️ CONFIG | ▶️ OPERATION | 🚩 ALARMS]
#define INFO_GET_STATUS                   0x10
#define INFO_GET_SERIALNUMBER             0x11
#define INFO_GET_PRODUCTION_DAY           0x12
#define INFO_GET_PRODUCTION_MONTH         0x13
#define INFO_GET_PRODUCTION_YEAR          0x14
#define INFO_GET_TYPE_SENSOR              0x15
#define INFO_SET_STATUS
#define INFO_SET_SERIALNUMBER
#define INFO_SET_PRODUCTION_DAY
#define INFO_SET_PRODUCTION_MONTH
#define INFO_SET_PRODUCTION_YEAR
#define INFO_SET_TYPE_SENSOR

#define CONFIG_GET_STATUS                 0x20
#define CONFIG_GET_TYPE                   0x21
#define CONFIG_GET_VARIABLE               0x22
#define CONFIG_GET_RESOLUTION             0x23
#define CONFIG_GET_INITIAL                0x24
#define CONFIG_GET_FINAL                  0x25
#define CONFIG_SET_STATUS
#define CONFIG_SET_TYPE
#define CONFIG_SET_VARIABLE
#define CONFIG_SET_RESOLUTION
#define CONFIG_SET_INITIAL
#define CONFIG_SET_FINAL

#define OPERATION_GET_STATUS              0x30
#define OPERATION_GET_ENABLE              0x31
#define OPERATION_GET_MODEREAD            0x32
#define OPERATION_GET_SENDTIME            0x33
#define OPERATION_GET_RESOLUTION          0x34
#define OPERATION_GET_VALUENOW            0x35
#define OPERATION_GET_                    0x36
#define OPERATION_GET_
#define OPERATION_SET_STATUS
#define OPERATION_SET_ENABLE
#define OPERATION_SET_MODEREAD
#define OPERATION_SET_SENDTIME
#define OPERATION_SET_RESOLUTION
#define OPERATION_SET_VALUENOW
#define OPERATION_SET_
#define OPERATION_SET_

#define ALARM_GET_STATUS                  0x40
#define ALARM_GET_LOWLEVEL2               0x41
#define ALARM_GET_LOWLEVEL1               0x42
#define ALARM_GET_AVERAGE                 0x43
#define ALARM_GET_HIGHLEVEL2              0x44
#define ALARM_GET_HIGHLEVEL1              0x45
#define ALARM_SET_STATUS
#define ALARM_SET_LOWLEVEL2
#define ALARM_SET_LOWLEVEL1
#define ALARM_SET_AVERAGE
#define ALARM_SET_HIGHLEVEL2
#define ALARM_SET_HIGHLEVEL1

// Lado do Mestre
#define TIME_PRESENCE 150  // 60 a 240 us
#define TIME_RESET 480     //480 us min
#define TIME_WAITRESET 15  // 15 us
#define TIME_WRITEBIT1 60  // 60 us
#define TIME_WRITEBIT0_1 15
#define TIME_WRITEBIT0_2 45
#define TIME_READSAMPLE 30

void reset() {
  pinMode(OneWire_PIN, OUTPUT);
  digitalWrite(OneWire_PIN, LOW);
  delayMicroseconds(480);
  pinMode(OneWire_PIN, INPUT_PULLUP);
  delayMicroseconds(15);
}
bool checkPresence() {
  return digitalRead(OneWire_PIN);
}

void enviarByte(byte data) {
  reset();
  if (!checkPresence()) {
    masterWriteByte(data);
    Serial.println("Reconheceu");
  }
}

bool masterReadBit() {
  pinMode(OneWire_PIN, OUTPUT);
  digitalWrite(OneWire_PIN, LOW);
  delayMicroseconds(1);
  pinMode(OneWire_PIN, INPUT_PULLUP);
  delayMicroseconds(15);
  bool aux = digitalRead(OneWire_PIN);
  delayMicroseconds(45);
  delayMicroseconds(5);
  return aux;
}

byte masterReadByte() {
  byte readByte;
  for (int i = 0; i <= 8; i++) {
    bitWrite(readByte, i, masterReadBit());
  }
  return readByte;
}

void masterWriteBit(bool bit) {
  uint8_t time = TIME_WRITEBIT0_1 + bit * TIME_WRITEBIT0_2;
  pinMode(OneWire_PIN, OUTPUT);
  digitalWrite(OneWire_PIN, LOW);
  delayMicroseconds(time);
  pinMode(OneWire_PIN, INPUT_PULLUP);
  delayMicroseconds((!bit) * TIME_WRITEBIT0_2);
}
void masterWriteByte(byte data) {
  for (int i = 0; i < 8; i++) {
    masterWriteBit(bitRead(data, 7 - i));
  }
}
void masterWriteCRC(uint8_t *data, size_t length) {
  masterWriteByte(calcularCRC(data, length));
}
void masterWriteByteWithCRC8BIT(byte data) {
  masterWriteByte(data);
  //masterWriteCRC(data, sizeof(data));
  //Serial.println("Data -> " + String(data) + "\tCRC8 -> " + String(calcularCRC(data, sizeof(data))));
}
void masterWriteByteWithRegister(byte data, byte registers) {
  masterWriteByte(registers);
  masterWriteByte(data);
  //masterWriteCRC(data,sizeof(data));
  Serial.println("Data -> " + String(data) + "\tRegister -> " + String(registers));
}
uint8_t calcularCRC(uint8_t *data, size_t length) {
  uint8_t crc = 0x00;        // Inicializa o CRC com zero
  uint8_t polinomio = 0x07;  // Polinômio gerador CRC-8-CCITT

  for (size_t i = 0; i < length; i++) {
    crc ^= data[i];  // Faz um XOR entre o byte atual e o valor do CRC

    for (uint8_t j = 0; j < 8; j++) {
      if (crc & 0x80) {
        crc = (crc << 1) ^ polinomio;  // Se o bit mais significativo do CRC for 1
      } else {
        crc <<= 1;  // Se o bit mais significativo do CRC for 0
      }
    }
  }

  return crc;
}
// Função para verificar se o CRC fornecido é válido para os dados
bool verificarCRC(uint8_t *data, size_t length, uint8_t crc_fornecido) {
  uint8_t crc_calculado = calcularCRC(data, length);
  return (crc_calculado == crc_fornecido);
}
#define REG_ONESHOT_BYTE 0xA0
#define REG_ONESHOT_CMD 0x01
bool solicitarByteFromSensor() {
  byte receivedByte;
  masterWriteByteWithRegister(REG_ONESHOT_CMD, REG_ONESHOT_BYTE);
}
void loopTesteEnviar_0_255(unsigned int _delay) {
  for (int i = 0; i < 256; i++) {
    //Serial.println("Count -> "+String(i));
    reset();
    if (!checkPresence()) {
      masterWriteByteWithRegister(i, i);
      //Serial.println("Reconheceu");
      delay(_delay);
    }
  }
}
union FloatByte {
  float floatValue;
  byte byteValue[4];
};
void masterWritefloatWithRegister(float value, byte registers) {
  FloatByte data;
  data.floatValue = value;
  masterWriteByte(registers);
  for (int i = 0; i < 4; i++) {
    masterWriteByte(data.byteValue[i]);
  }
  //masterWriteCRC(data,sizeof(data));
  Serial.println("Data -> " + String(value) + "\tRegister -> " + String(registers));
}
void enviarFloat(float _value, byte registers) {
  reset();
  if (!checkPresence()) {
    masterWritefloatWithRegister(_value, registers);
  }
}
