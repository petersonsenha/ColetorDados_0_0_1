//
//    FILE: INA219_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//     URL: https://github.com/RobTillaart/INA219


#include "INA219.h"
#include "Wire.h"

INA219 INA(0x40);


void setupCurrent()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("INA219_LIB_VERSION: ");
  Serial.println(INA219_LIB_VERSION);

  Wire.begin(13,12);
  if (!INA.begin()){
    Serial.println("Could not connect. Fix and Reboot");
    while(1){}
  }
  INA.setMaxCurrentShunt(1, 0.002);
  vTaskDelay(pdMS_TO_TICKS(1000));
  //  INA.setMaxCurrentShunt(2.5, 0.002);
  //  vTaskDelay(pdMS_TO_TICKS(1000));
  //  INA.setMaxCurrentShunt(5, 0.002);
  //  vTaskDelay(pdMS_TO_TICKS(1000));
  //  INA.setMaxCurrentShunt(7.5, 0.002);
  //  vTaskDelay(pdMS_TO_TICKS(1000));
  //  INA.setMaxCurrentShunt(10, 0.002);
  //  vTaskDelay(pdMS_TO_TICKS(1000));
  //  INA.setMaxCurrentShunt(15, 0.002);
  //  vTaskDelay(pdMS_TO_TICKS(1000));
  //  INA.setMaxCurrentShunt(20, 0.002);
  //  vTaskDelay(pdMS_TO_TICKS(10000);

  Serial.println(INA.getBusVoltageRange());

}


void loopCurrent()
{
  Serial.println("\n\tBUS\t\tSHUNT\t\tCURRENT\t\tPOWER\t\tOVF\t\tCNVR");
  for (int i = 0; i < 5; i++)
  {
    Serial.print("\t");
    Serial.print(INA.getBusVoltage(), 2);
    Serial.print("\t\t");
    Serial.print(INA.getShuntVoltage_mV(), 2);
    Serial.print("\t\t");
    Serial.print(0.692864*(INA.getCurrent_mA()), 2);
    Serial.print("\t\t");
    Serial.print(INA.getPower_mW(), 2);
    Serial.print("\t\t");
    Serial.print(INA.getMathOverflowFlag());
    Serial.print("\t\t");
    Serial.print(INA.getConversionFlag());
    Serial.println();
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  Serial.println("Está Conectado : "+String(INA.isConnected()));
  Serial.println("Está Calibrado : "+String(INA.isCalibrated()));
  Serial.println("Brilho : "+String(hmi.getBrightness()));
  vTaskDelay(pdMS_TO_TICKS(1000));
}


//  -- END OF FILE --
