/*
Experimento Matemática 1 - Medição das Dimensões de uma sala
*******************Objetivo:*****************************
  Medir as dimensões da sala de aula
*******************Sensores:*****************************
1x          Ultrassônico
*******************Variáveis:****************************
2010        Medida de uma Parede em X
2011        Medida de uma Parede em Y
2012        Cálculo da Área
*******************Botões:*******************************
Botão 1     Faz a medida da Parede em X
Botão 2     Faz a medida da Parede em Y
Botão 3     Faz a medida da Área
*******************Funções dos botões:*******************
Botão 1     Ao ser apertado: ele captura o valor de distância e joga na variável da Parede X
Botão 2     Ao ser apertado: ele captura o valor de distância e joga na variável da Parede Y
Botão 3     Ao ser apertado: ele utiliza o valor da Parede X e da Parede Y e multiplica e mostra o valor 
*/
#define EXPERIMENTO_PAGE              42
#define VP_Parede_X                   0x2010
#define VP_Parede_Y                   0x2011
#define VP_Parede_Area                0x2012
#define VP_Button_Parede_X            0x2013
#define VP_Button_Parede_Y            0x2014
#define VP_Button_Parede_Area         0x2015

int Wire_Sensor_Ultrassonic = OneWire_PIN_1;
bool runExperimento=false;
int Parede_X=0;
int Parede_Y=0;
int Area=0;

void atualizarVariavelParedeX(){
  Parede_X = getOperationValueNow(Wire_Sensor_Ultrassonic);
  hmi.setVP_Int(VP_Parede_X,Parede_X);
}
void atualizarVariavelParedeY(){
  Parede_Y = getOperationValueNow(Wire_Sensor_Ultrassonic);
  hmi.setVP_Int(VP_Parede_Y,Parede_Y);
}
void atualizarVariavelArea(){
  Area = int(Parede_X * Parede_Y);
}

void loopCheckButtons(){
  
}

