/*
    Bluetooth Functions
      ---   Iniciar o Bluetooth 

//Biblioteca para habilitar a comunicação SERIAL
#include "BluetoothSerial.h"

//Verifica se o bluetooth esta habilitado corretamente
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

//Cria uma instância de BluetoothSerial chamado SerialBT
BluetoothSerial SerialBT;
void setupBluetooth(){
  SerialBT.begin("Tablet Coletor de Dados ");
  Serial.println("O dispositivo foi iniciado, agora você pode emparelhá-lo com bluetooth!");
}
void loopBluetooth(){
  //Verifica se algo foi recebido pela porta SERIAL
  //Se sim envie os dados recebidos via Bluetooth ao dispositivo conectado
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  //Verifica se há algo na porta SERIAL Bluetooth
  //Se sim envia os dados para o monitor SERIAL
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}
*/