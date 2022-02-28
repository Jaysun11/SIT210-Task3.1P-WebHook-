// This #include statement was automatically added by the Particle IDE.
#include <PietteTech_DHT.h>


const int DHTTYPE = DHT11;       
const int DHT_VCC = D4;
const int DHT_PIN = D3;          
const int DHT_GND = D2;

PietteTech_DHT DHT(DHT_PIN, DHTTYPE);

void setup()
{
  pinMode(DHT_GND, OUTPUT);
  pinMode(DHT_VCC, OUTPUT);
  digitalWrite(DHT_GND, LOW);
  digitalWrite(DHT_VCC, HIGH);
  
  Serial.begin(9600);

  
  DHT.begin();
  
  delay(1000);
}

void loop()
{


  int result = DHT.acquireAndWait(1000); // wait up to 1 sec (default indefinitely)
  float temp = DHT.getCelsius();
  
  char tempString[5];
  sprintf(tempString, "%.2f", temp);

  Serial.print("Temperature (oC): ");
  Serial.println(temp);
  
  Particle.publish("temp", tempString, PRIVATE);


  delay(3000);
}