// Leitura e escrita de arquivos na flash
#include <FS.h>
#include "SPIFFS.h"

/*
* \fn escreveArquivo(String, String)
* \escreve arquivo na flash
* \param nameArq(nome do arquivo), arq(arquivo)
* \return void
*/
void escreveArquivo(String nameArq, String arq){
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
 
  File file = SPIFFS.open(nameArq, FILE_WRITE);

  if (!file) {
    Serial.println("ERRO AO ABRIR ARQUIVO PARA GRAVACAO");
    //return ;
  }
  if (file.print(arq)) {
    Serial.println("ARQUIVO GRAVADO COM SUCESSO!!!");
  } else {
    Serial.println("FALHA NA ESCRITA");
  }
  file.close();
}

/*
* \fn lerArquivo(String)
* \lê arquivo na flash
* \param nameArq(nome do arquivo)
* \return String(conteudo do arquivo)
*/
String lerArquivo(String nameArq){
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return "";
  }
  File file2 = SPIFFS.open(nameArq);
    if(!file2){
        Serial.println("FALHA AO ABRIR O ARQUIVO PARA LER");
        return "";
    }
  String content = file2.readStringUntil('\r'); //desconsidera '\r\n'
  file2.close();
  return content;
}

/*
* \fn listaArquivos(String)
* \lista arquivos
* \param diretorio(diretorio do arquivo)
* \return void
*/
void listaArquivos(String diretorio){
 
  File root = SPIFFS.open(diretorio);
  File file = root.openNextFile();

  while(file){
 
      Serial.print("FILE: ");
      Serial.println(file.name());
      file = root.openNextFile();
  }
}

/*
* \fn apagaTodosArquivos(String)
* \apaga todos os arquivos com o mesmo diretório
* \param diretorio(diretorio do arquivo)
* \return void
*/
void apagaTodosArquivos(String diretorio){
 
  File root = SPIFFS.open(diretorio);
  File file = root.openNextFile();

  while(file){
 
      Serial.print("FILE: ");
      Serial.print(file.name());
      Serial.print(" APAGADO!!!");
      SPIFFS.remove(file.name());
      file = root.openNextFile();
  }
}
