/*
  Funções de suporte para parametrização dos sensores
*/
// Pegar o arquivo JSON/struct de Parametrização do sensor
// 
struct recogniizeSensor_Type{

};

class Sensor{
  struct infoSensor{
    byte Status;
    byte numberSerial;
    byte dayProduction;
    byte monthProduction;
    byte yearProduction;
    byte typeSensor;
  };
  struct configurationSensor{
    byte Status;
    byte typeSensor;
    byte variable;
    byte resolution;
    byte initialValue;
    byte finalValue;
  };
  struct operationSensor{
    byte Status;
    byte enableSensor;
    byte modeRead;
    byte timeSend;
    byte resolutionSensor;
  };
  struct alarmSensor{
    byte Status;
    byte lowAlarmOne;
    byte lowAlarmTwo;
    byte highAlarmOne;
    byte highAlarmTwo;
    byte averageAlarm;
  };
  public:
    void  begin();
    int   recognizeSensor();
    void  prepareSensor();
    byte getByteValue();
    int getIntValue();
    long getLongValue();
    float getFloatValue();

    //Conjunto de funções para enviar para o display
    
};