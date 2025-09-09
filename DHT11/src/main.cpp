#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 15       
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("❌ Lỗi đọc cảm biến DHT11!");
    return;
  }

  Serial.print("🌡 Nhiệt độ: ");
  Serial.print(t);
  Serial.print(" °C  |  💧 Độ ẩm: ");
  Serial.print(h);
  Serial.println(" %");

  delay(2000);  
}
