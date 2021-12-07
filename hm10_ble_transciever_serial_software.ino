#include <SoftwareSerial.h> // for using other pins than 0 and 1 as USART

SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
String inData = "";

void receivedAction (String action)
{
    Serial.println(action.length());
    if (action.equalsIgnoreCase( "OFF\r\n" )  )
    {
        digitalWrite(13, LOW); 
        HM10.write("LED OFF!");
        delay(50);
    }
  
    else if (action.equalsIgnoreCase ( "ON\r\n" ) )
    {
        digitalWrite(13, HIGH); 
        HM10.write("LED ON!");
        delay(50);
    }
  
    else 
    {
        Serial.println("Command not found");
        delay(50);
    }
}

void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial starts at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  
  pinMode(13, OUTPUT); // onboard LED
  digitalWrite(13, LOW);

  HM10.write("Hello from HM 10!");
  HM10.listen();  // listen the HM10 port

}

void loop()
{

  // If HM10 received something, then read
  if (HM10.available() > 0) 
  { 
    
    inData = HM10.readString();  
    HM10.println(inData);

    receivedAction(inData);
  
  }
}
