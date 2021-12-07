// For uploading the code to the Arduino, pins 0 and 1 must be free
// Once uploaded, HM 10 connected to pins 0 and 1 (Rx / Tx)

String inData = "";

void setup()
{
  Serial.begin(9600);
    
  pinMode(13, OUTPUT); // onboard LED
  digitalWrite(13, LOW); 
}

void loop()
{
  // If HM10 received something, then read
  while (Serial.available() > 0) 
  { 
    
    inData = Serial.readString();
    Serial.println(inData); // echo what's been received
    
    if (inData.equalsIgnoreCase( "OFF\r\n" ) )
    {
        digitalWrite(13, LOW); 
        Serial.write("LED OFF!");
        delay(50);
    }
  
    else if (inData.equalsIgnoreCase ( "ON\r\n" ) )
    {
        digitalWrite(13, HIGH); 
        Serial.write("LED ON!");
        delay(50);
    }
  
    else 
    {
        Serial.write("Command not found");
        delay(50);
    }
  
  
  }

  

}
