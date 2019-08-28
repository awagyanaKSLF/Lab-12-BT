#include <SoftwareSerial.h>

#define BT_TX 2
#define BT_RX 3
#define Red 4
#define Green 5
#define Blue 6

SoftwareSerial mySerial(BT_TX, BT_RX);
String myString="";

void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  setColor(1,1,1);
}

void loop(){
  while(mySerial.available()){
    char myChar = (char)mySerial.read();
    myString+=myChar;
    if (myString == "R") 
      setColor(0,1,1);
    else if (myString == "G") 
      setColor(1,0,1);
    else if (myString == "B") 
      setColor(1,1,0);
    else if (myString == "A") {
      setColor(0,1,1);
      delay(500);
      setColor(1,0,1);
      delay(500);
      setColor(1,1,0);
      delay(500);
      setColor(1,1,1);
    }
    if(!myString.equals("")) {
      Serial.println("Received: "+myString);
      myString = "";  // clear
    }
  }
}

void setColor (int R, int G, int B){
  digitalWrite(Red,R);
  digitalWrite(Green,G);
  digitalWrite(Blue,B);
  return;
  
}
