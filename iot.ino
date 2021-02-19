#include <SoftwareSerial.h>

SoftwareSerial esp8266(2,3);

#define serialCommunicationSpeed 9600
#define DEBUG true
//#define STATUS = 0

//int checkStOne = 0;
//int checkStTwo = 0;
//int checkStThree = 1;
//int checkStFour = 1;


//int detectorOne = 9;
//int detectorTwo = 10;
//int detectorThree = 11;
//int detectorFour = 12;

//int lightOne = 6;
//int lightTwo = 7;
int lightThree = 8;
//int lightFour = 9;

int indicator = 13;


void setup()
{
//  pinMode(detectorOne,INPUT);
//  pinMode(detectorTwo,INPUT);
//  pinMode(detectorThree,INPUT);
//  pinMode(detectorFour,INPUT);

  
//  digitalWrite(detectorOne,LOW);
//  digitalWrite(detectorTwo,LOW);
//  digitalWrite(detectorThree,LOW);
//  digitalWrite(detectorFour,LOW);
  
//  pinMode(lightOne,OUTPUT);
//  pinMode(lightTwo,OUTPUT);
  pinMode(lightThree,OUTPUT);
//  pinMode(lightFour,OUTPUT);
  
  pinMode(indicator,OUTPUT);

  
//  digitalWrite(lightOne,HIGH);
//  digitalWrite(lightTwo,HIGH);
  digitalWrite(lightThree,HIGH);
//  digitalWrite(lightFour,HIGH);
  
  digitalWrite(indicator,HIGH);

  
  Serial.begin(serialCommunicationSpeed);
  esp8266.begin(serialCommunicationSpeed);
  
  InitWifiModule();
//  checkCircuitStatus();
  
  digitalWrite(indicator,LOW);
  delay(200);
}
void loop()
{
  if(esp8266.available())
  
  {
    delay(500);
    if(esp8266.find("+IPD,"))
    {
      delay(200);
      int connectionId = esp8266.read()-48;
        
        esp8266.find("pin=");
        int pinNumber = (esp8266.read()-48);        
        int statusLed =(esp8266.read()-48);
        delay(500);
          
        String responseData = "AT+CIPSEND=";
        responseData += connectionId;
        responseData += ",1\r\n";
        Serial.println(responseData);
        sendData(responseData , 800, DEBUG);
        
        delay(100);
        sendData(pinNumber+"\r\n",500,DEBUG);
        delay(100);
        
        digitalWrite(pinNumber, statusLed);
        
        String closeCommand = "AT+CIPCLOSE=";
        closeCommand+=connectionId;
        closeCommand+="\r\n";
        sendData(closeCommand,500,DEBUG);
        
    }
  }
//  if(digitalRead(detectorOne) != checkStOne || digitalRead(detectorTwo) != checkStTwo || digitalRead(detectorThree) != checkStThree || digitalRead(detectorFour) != checkStFour){
//    Serial.println("i am inside loop");
//    if(digitalRead(detectorOne) != checkStOne){
//      checkStOne = digitalRead(detectorOne);
//      sendStToDatabase(detectorOne, checkStOne);
//    }
//    if(digitalRead(detectorTwo) != checkStTwo){
//      checkStTwo = digitalRead(detectorTwo);
//      sendStToDatabase(detectorTwo , checkStTwo);
//    }
//    if(digitalRead(detectorThree) != checkStThree){
//      checkStThree = digitalRead(detectorThree);
//      sendStToDatabase(detectorThree , checkStThree);
//    }
//    if(digitalRead(detectorFour) != checkStFour){
//      checkStFour = digitalRead(detectorFour);
//      sendStToDatabase(detectorFour , checkStFour);
//    }
//    
//  }
//  else{
//    Serial.println("I AM NOT OK, ok?");
//    Serial.println(digitalRead(detectorTwo));  
//    delay(1000);
//  }
}


//    int changeOccured(){
//      int static StatusOfDetectorOne = 0;      
//      int static StatusOfDetectoTwo = 0;      
//      int static StatusOfDetectorThree = 0;      
//      int static StatusOfDetectorFour = 0;
//      if(digitalRead(detectorOne) != StatusOfDetectorOne){
//        StatusOfDetectorOne = digitalRead(detectorOne);
//      }
//      if(digitalRead(detectorTwo) != StatusOfDetectoTwo){
//        StatusOfDetectoTwo = digitalRead(detectorTwo);
//      }
//      if(digitalRead(detectorThree) != StatusOfDetectorThree){
//        StatusOfDetectorThree = digitalRead(detectorThree);
//      }
//      if(digitalRead(detectorFour) != StatusOfDetectorFour){
//        StatusOfDetectorFour = digitalRead(detectorFour);
//      }
//      
//    }

void sendData(String command, const int timeout, boolean debug){
    String response = "";          
    esp8266.print(command);
    long int time = millis();
    while( (time+timeout) > millis()){
      while(esp8266.available()){
        char c = esp8266.read();
        response+=c;
      }
    }
    if(DEBUG){
      Serial.print(response);
    }
//    return response;
}
void InitWifiModule(){
  sendData("AT+RST\r\n", 1500, DEBUG);
//  delay(1000);
  sendData("AT+CWMODE=1\r\n", 1000, DEBUG);
//  delay (500);
  sendData("AT+CWJAP=\"spacex#Stay Home@ClassicTech\",\"pravash1234\"\r\n", 5000, DEBUG);
//  delay (1000);
  sendData("AT+CIFSR\r\n", 600, DEBUG);
//  delay (1000);
  sendData("AT+CIPMUX=1\r\n", 600, DEBUG);
//  delay (1000);
  sendData("AT+CIPSERVER=1,80\r\n", 600, DEBUG);
//  delay(500);
}
//void checkCircuitStatus(){
//  if(digitalRead(detectorOne)){
//    checkStOne = 1;
//    sendStToDatabase(detectorOne, checkStOne);
//  }
//  if(digitalRead(detectorTwo)){
//    checkStTwo = 1;
//    sendStToDatabase(detectorTwo , checkStTwo);
//  }
//  if(digitalRead(detectorThree)){
//    checkStThree = 1;
//    sendStToDatabase(detectorThree , checkStThree);
//  }
//  if(digitalRead(detectorFour)){
//    checkStFour = 1;
//    sendStToDatabase(detectorFour , checkStFour);
//  }
//}
//void sendStToDatabase(int detector, int checkSt){
//  Serial.println("i am here");
//  Serial.println(detector);
//  Serial.println(checkSt);
//  
//}
