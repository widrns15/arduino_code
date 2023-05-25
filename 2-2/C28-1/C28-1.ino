#include <DHT.h>
#define DHT_PIN A2
DHT dht (DHT_PIN, DHT11);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT Test ~!!");
  dht.begin(); // 온습도 센서 동작 시작
}

void loop() {
  
boolean chk = dht.read(); // 온습도 센서의 동작 체크
if(chk)
{
  Serial.print("Humidity (%): ");
  Serial.println((int)dht.readHumidity());
  Serial.print("Temperature (도): ");
  Serial.println((int)dht.readTemperature(false));
}else{
  Serial.print("Failed to read info.");
}
delay(1000);
}
