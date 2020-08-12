//Bibliotecas, constantes e variáveis do sistema

#include <WiFiManager.h>

// Bibliotecas e definições

#define LED_AP       2 //led modo STA/AP LED VERDE
#define LED_TX       4 //led transmissão dados LED AMARELO
#define LED_RL       5 //led estado do rele LED VERMELHO
#define BOT_AP      15 //botao de entrada no modo AP
#define RELE        18 //relê porta 4
#define RELE_IN1    19
#define RELE_IN2    21
#define RELE_IN3    13

#define dns_port  53


//-----Bibliotecas Servidor---- 
#if defined(ESP8266)
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#else
#include <WiFi.h>          //https://github.com/esp8266/Arduino
#endif

//needed for library
#include <DNSServer.h>
#if defined(ESP8266)
#include <ESP8266WebServer.h>
#else
#include <WebServer.h>
#endif
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <PubSubClient.h>
#include <WiFiClient.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "DNSServer.h"
#include <HTTPClient.h>
#include <Ticker.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ThingSpeak.h> 

boolean flagSensores = false;
boolean flagRecordMetrics = false;
short int countTemp = 0;
short int countCorrente = 0;
short int countEnvio = 0;
short int countPorta = 0;
String metricas = "";
String auxMetricas = "";
String jSon = "";
String head = "";
String mac = "";
int cEnvia = 0;

long int sequencial = 0;
long int seqMetrics = 0;
short int tempPortas;
short int tempTemperatura;
short int tempCorrente;
short int tempEnvio;

float temp_1;
float temp_2;
float temp_3;
int porta_1;
int porta_2;
int porta_3;














































//Chaves de Acesso ao Thingspeak
unsigned long myChannelNumber = 1110320 ; //update
const char * myWriteAPIKey = "E4Q2ZSU7631V6XIN"; //update
WiFiClient client_TS;
