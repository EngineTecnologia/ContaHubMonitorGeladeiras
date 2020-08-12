//#define TMP_01  23 //temperatura_1
//#define TMP_02  22 //temperatura_2
//#define TMP_03  14 //temperatura_3

#define PRT_01  25 //porta_1
#define PRT_02  26 //porta_2
#define PRT_03  27 //porta_3

#define AMP_01  32  // GPIO32 (acs712_1)
#define AMP_02  33  // GPIO33 (acs712_2)
#define AMP_03  34  // GPIO34 (acs712_3)

// GPIO onde o DS18B20 esta conectado
#define oneWireBus1  23
#define oneWireBus2  22
#define oneWireBus3  14

#define   ADC_CONV    0.001220703125    // para resolução de 12 bits (5/4096)
//#define   ADC_CONV    0.0048828125        // para resolução de 10 bits (5/1024)
#define   T_OFFSET    2.5               // Tensão de offset
#define   SENSI       100               // Sensibilidade do sensor
#define   RAIZ_2      1.4142135623730   // RAIZ DE 2
#define   RES_ADC     ADC_WIDTH_BIT_12  // Resolução de 12 bits
//#define   RES_ADC     ADC_WIDTH_BIT_10  // Resolução de 10 bits

//------Bibliotecas Sensores----
#include <driver/adc.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Inicia instância da oneWire para comunicar com qquer dispositivo OneWire
OneWire oneWire1(oneWireBus1);
OneWire oneWire2(oneWireBus2);
OneWire oneWire3(oneWireBus3);

// Passa as referencia do oneWire para o sensor de temperatura Dallas
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);
DallasTemperature sensors3(&oneWire3);

void inicializa_adc();

void setupSensores(){
//  pinMode(TMP_01, INPUT);
//  pinMode(TMP_02, INPUT);
//  pinMode(TMP_03, INPUT);
  pinMode(PRT_01, INPUT);
  pinMode(PRT_02, INPUT);
  pinMode(PRT_03, INPUT);
  pinMode(AMP_01, INPUT);
  pinMode(AMP_02, INPUT);
  pinMode(AMP_03, INPUT);

  inicializa_adc();

  //Inicializa o termômetro
  sensors1.begin();
  sensors2.begin();
  sensors3.begin();
}


//------- Códigos dos sensores-------
void inicializa_adc(){
  adc1_config_width(RES_ADC);  //define resolução de 12-bits (0 a 4095) para as portas do adc1

  //**** DEFINIÇÕES DAS TENSÕES MÁXIMAS EM CADA PORTA
  //adc1_config_channel_atten(ADC1_CHANNEL_0,ADC_ATTEN_DB_0); //define atenuação de 0db (1.1v) para o canal 0 GPIO36
  //adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11); //define atenuação de 11db (3.3v) para o canal 0 GPIO36
  //adc1_config_channel_atten(ADC1_CHANNEL_3,ADC_ATTEN_DB_0); //define atenuação de 0db (1.1v) para o canal 0 GPIO39
  adc1_config_channel_atten(ADC1_CHANNEL_3, ADC_ATTEN_DB_11); //define atenuação de 11db (3.3v) para o canal 0 GPIO39
  //adc1_config_channel_atten(ADC1_CHANNEL_4,ADC_ATTEN_DB_0); //define atenuação de 0db (1.1v) para o canal 0 GPIO32
  adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11); //define atenuação de 11db (3.3v) para o canal 0 GPIO32
  //adc1_config_channel_atten(ADC1_CHANNEL_5,ADC_ATTEN_DB_0); //define atenuação de 0db (1.1v) para o canal 0 GPIO33
  adc1_config_channel_atten(ADC1_CHANNEL_5, ADC_ATTEN_DB_11); //define atenuação de 11db (3.3v) para o canal 0 GPIO33
  //adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_0); //define atenuação de 0db (1.1v) para o canal 0 GPIO34
  adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11); //define atenuação de 11db (3.3v) para o canal 0 GPIO34
  //adc1_config_channel_atten(ADC1_CHANNEL_7,ADC_ATTEN_DB_0); //define atenuação de 0db (1.1v) para o canal 0 GPIO35
  //adc1_config_channel_atten(ADC1_CHANNEL_7, ADC_ATTEN_DB_11); //define atenuação de 11db (3.3v) para o canal 0 GPIO35
}
