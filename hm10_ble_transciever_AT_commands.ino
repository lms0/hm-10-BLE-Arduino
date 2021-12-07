#include <SoftwareSerial.h>

// Send and receive between serial and hm10
// AT+HELP lists all the AT commands

SoftwareSerial BTSerial(2, 3); //RX|TX


void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600); // default baud rate
  //while(!Serial); //if it is an Arduino Micro
  delay(1000);
  BTSerial.write("AT+HELP\r\n");
}

void loop(){
  //read from the HM-10 and print in the Serial
  if(BTSerial.available())
    Serial.write(BTSerial.read());
    
  //read from the Serial and print to the HM-10
  if(Serial.available())
    BTSerial.write(Serial.read());
}
