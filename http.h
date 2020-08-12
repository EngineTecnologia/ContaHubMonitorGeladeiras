// Comunicação http com o servidor

String urlencode(String str)
{
    String encodedString="";
    char c;
    char code0;
    char code1;
    char code2;
    for (int i =0; i < str.length(); i++){
      c=str.charAt(i);
      if (c == ' '){
        encodedString+= '+';
      } else if (isalnum(c)){
        encodedString+=c;
      } else{
        code1=(c & 0xf)+'0';
        if ((c & 0xf) >9){
            code1=(c & 0xf) - 10 + 'A';
        }
        c=(c>>4)&0xf;
        code0=c+'0';
        if (c > 9){
            code0=c - 10 + 'A';
        }
        code2='\0';
        encodedString+='%';
        encodedString+=code0;
        encodedString+=code1;
        //encodedString+=code2;
      }
      yield();
    }
    return encodedString;
}

boolean EnviaJson(String uncoded_str) {

 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

//   String encoded_str = "json="+urlencode(uncoded_str);
   String encoded_str = urlencode(uncoded_str);
//   String encoded_str = "%7B+%22seq%22%3A1010%2C%22now%22%3A56555%2C%22mac%2Daddress%22%3A%22A345E7267D%22%2C%22token%22%3A%22corinthians%22%2C%22metrics%22%3A+%5B+%7B%22timestamp%22%3A500%2C%22sensor%22%3A1%2C%22value%22%3A+%2D5%2E1%7D%2C+%7B%22timestamp%22%3A501%2C%22sensor%22%3A2%2C%22value%22%3A+1%2E0%7D%2C+%7B%22timestamp%22%3A1000%2C%22sensor%22%3A3%2C%22value%22%3A+12%2E0%7D%2C%7B%22timestamp%22%3A500%2C%22sensor%22%3A4%2C%22value%22%3A+%2D1%7D%2C+%7B%22timestamp%22%3A501%2C%22sensor%22%3A5%2C%22value%22%3A+2%2E0%7D%2C+%7B%22timestamp%22%3A1000%2C%22sensor%22%3A6%2C%22value%22%3A+14%2E0%7D%2C%7B%22timestamp%22%3A500%2C%22sensor%22%3A7%2C%22value%22%3A+%2D15%2E3%7D%2C+%7B%22timestamp%22%3A501%2C%22sensor%22%3A8%2C%22value%22%3A+3%2E0%7D%2C+%7B%22timestamp%22%3A1000%2C%22sensor%22%3A9%2C%22value%22%3A+16%2E0%7D+%5D%7D%0D";
   encoded_str = "json="+encoded_str;  

   //Serial.println(uncoded_str);
   //Serial.println(encoded_str);
    
   
   HTTPClient http;   
   http.begin("http://bkp2.contahub.com/rest/contahub.cmds.IoTCmd/takeMetrics");
   http.addHeader("Content-Type","application/x-www-form-urlencoded");            
   http.addHeader("charset","UTF-8");            
   
   int httpResponseCode = http.POST(encoded_str);
    
   if(httpResponseCode == 200){
    piscaLedAmarelo();
    piscaLedAmarelo();
    String response = http.getString();                       //Get the response to the request

    Serial.print("Codigo de resposta: "); 
    Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer

    return true;
 
   }else{
 
    Serial.print("ERROR ON SENDING POST: ");
    Serial.println(httpResponseCode);
    return false;
 
   }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("ERRO NA CONEXAO WIFI");
    return false;   
 
 } 

delay(1000);


 
}
