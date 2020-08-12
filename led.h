// Manipulação dos leds do dispositivo

#define LED_VERMELHO  5 //led estado do rele LED VERMELHO
#define LED_VERDE     2 //led modo STA/AP LED VERDE
#define LED_AMARELO   4 //led transmissão dados LED AMARELO

void setupLed(){
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
}

void piscaLedVermelho(){
  digitalWrite(LED_VERMELHO, HIGH);
  delay(150);
  digitalWrite(LED_VERMELHO, LOW);
  delay(150);
}

void piscaLedAmarelo(){
  digitalWrite(LED_AMARELO, HIGH);
  delay(150);
  digitalWrite(LED_AMARELO, LOW);
  delay(150);
}

void piscaLedVerde(){
  digitalWrite(LED_VERDE, HIGH);
  delay(150);
  digitalWrite(LED_VERDE, LOW);
  delay(150);
}

void acendeLedVerde(){
	digitalWrite(LED_VERDE, HIGH);
}
void acendeLedVermelho(){
  digitalWrite(LED_VERMELHO, HIGH);
}
void acendeLedAmarelo(){
  digitalWrite(LED_AMARELO, HIGH);
}

void apagaLedVerde(){
  digitalWrite(LED_VERDE, LOW);
}
void apagaLedVermelho(){
  digitalWrite(LED_VERMELHO, LOW);
}
void apagaLedAmarelo(){
  digitalWrite(LED_AMARELO, LOW);
}
