//dht11 library
//Link dht11 https://projecthub.arduino.cc/arcaegecengiz/using-dht11-12f621
#include <dht11.h>
#define DHT11PIN 4
#define VentilatorSpeed1 8
#define VentilatorSpeed2 9
#define VentilatorSpeed3 10


dht11 DHT11;

void setup() {
  // voor seriele monitoring
  Serial.begin(9600);
  pinMode(VentilatorSpeed1, OUTPUT);
  pinMode(VentilatorSpeed2, OUTPUT);
  pinMode(VentilatorSpeed3, OUTPUT);

}

void loop() {
  // puur voor monitoring
  Serial.println();
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Vochtigheid (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("Temperatuur (C): ");
  Serial.println((float)DHT11.temperature, 2);

  //Werking zelf
  if(DHT11.temperature < 22) 
  {
    digitalWrite(VentilatorSpeed1, LOW);
    digitalWrite(VentilatorSpeed2, LOW);
    digitalWrite(VentilatorSpeed3, LOW);
  }
    if(DHT11.temperature >= 22 && DHT11.temperature < 25) 
  {
    digitalWrite(VentilatorSpeed1, HIGH);
    digitalWrite(VentilatorSpeed2, LOW);
    digitalWrite(VentilatorSpeed3, LOW);
  }
      if(DHT11.temperature >= 25 && DHT11.temperature < 28) 
  {
    digitalWrite(VentilatorSpeed1, LOW);
    digitalWrite(VentilatorSpeed2, HIGH);
    digitalWrite(VentilatorSpeed3, LOW);
  }
        if(DHT11.temperature >= 28) 
  {
    digitalWrite(VentilatorSpeed1, LOW);
    digitalWrite(VentilatorSpeed2, LOW);
    digitalWrite(VentilatorSpeed3, HIGH);
  }

}
