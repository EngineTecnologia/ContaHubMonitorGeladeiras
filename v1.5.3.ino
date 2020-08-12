
#include "bibli.h"
#include "tasks.h"

 
Ticker TickSegundo;

String ssid; 
String senha;

WiFiClient espClient;
PubSubClient client(espClient);
WiFiManager wifiManager;

DNSServer dnsServer;

AsyncWebServer server(80);

String json = "json=";

// Contagem de 1 em 1 segundo
// Serve para leitura dos sensores e envio
void ISRwatchdog() {
  flagSensores = true;
}

//função que retorna os valores de configurações do wifi e demais parametros.
//Caso não encontre parametros gravados entra em modo AP e abre html para inserção dos parametros 
void WiFi_Manager(){

  //recupera os temporizadores gravados na flash pelo wifimanager com valores em segundos
  tempPortas = wifiManager._tempPortas.toInt();
  tempTemperatura = wifiManager._tempTemperatura.toInt();
  tempCorrente = wifiManager._tempCorrente.toInt();
  tempEnvio = wifiManager._tempEnvio.toInt();
  
  if(wifiManager._tempPortas == ""){
    tempPortas      = lerArquivo("/config/param1.txt").toInt();
    tempTemperatura = lerArquivo("/config/param2.txt").toInt();
    tempCorrente    = lerArquivo("/config/param3.txt").toInt();
    tempEnvio       = lerArquivo("/config/param4.txt").toInt();
    seqMetrics      = lerArquivo("/config/seqMetrics.txt").toInt();
    sequencial      = lerArquivo("/config/sequencial.txt").toInt();
    Serial.print("seqMetricas: ");
    Serial.println(seqMetrics);
    Serial.print("sequencial: ");
    Serial.println(sequencial);

  } else{
    escreveArquivo("/config/param1.txt",wifiManager._tempPortas);
    escreveArquivo("/config/param2.txt",wifiManager._tempTemperatura);
    escreveArquivo("/config/param3.txt",wifiManager._tempCorrente);
    escreveArquivo("/config/param4.txt",wifiManager._tempEnvio);
  }
  Serial.println("___________________________________");
  Serial.println(tempPortas);
  Serial.println(tempTemperatura);
  Serial.println(tempCorrente);
  Serial.println(tempEnvio);
  Serial.println("___________________________________");

  ssid = (String)WiFi.SSID();
  senha = (String)WiFi.psk();
  mac = WiFi.macAddress();
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("PASS: ");
  Serial.println(senha);
  Serial.print("mac: ");
  Serial.println(mac);
  
// WiFi Conecting
}

void setup(){
  
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  TickSegundo.attach(1, ISRwatchdog); 
  seqMetrics      = lerArquivo("/config/seqMetrics.txt").toInt();
  sequencial      = lerArquivo("/config/sequencial.txt").toInt();
//  Se necessário reiniciar as variáveis sequencial e seqMetricas
//  sequencial = 0;
//  seqMetrics = 0;
//  escreveArquivo("/config/sequencial.txt", (String)sequencial);
//  escreveArquivo("/config/seqMetrics.txt", (String)sequencial);

// Apaga todos arquivos da memoria flash
  apagaTodosArquivos("/json");

  pinMode(LED_AP,OUTPUT);
  pinMode(LED_TX,OUTPUT); 
  pinMode(LED_RL,OUTPUT); 
  pinMode(RELE,OUTPUT);
  pinMode(RELE_IN1,OUTPUT);
  pinMode(RELE_IN2,OUTPUT);
  pinMode(RELE_IN3,OUTPUT);
  pinMode(BOT_AP, INPUT_PULLUP);

  setupSensores();
  setupTask();
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("conectado ao WiFi");
  WiFi_Manager();
  digitalWrite(LED_AP, HIGH);
  
}

void loop(void){
//  Verifica conexão WiFi

  if(WiFi.status() != WL_CONNECTED){
     Serial.println("Tentando conexão com o WiFi...");
     WiFi.disconnect();
     WiFi.mode(WIFI_OFF);
     WiFi.mode(WIFI_STA);
     WiFi.begin(ssid.c_str(),senha.c_str());
  }
  if(!digitalRead(BOT_AP)){
      Serial.println("BOTÃO ACIONADO");
//      WiFiManager wifiManager;
      if(wifiManager.startConfigPortal("AutoConnectAP")){
        Serial.println("Conectado");
        WiFi_Manager();
        delay(1000);
      }
    }
  delay(500);
}
