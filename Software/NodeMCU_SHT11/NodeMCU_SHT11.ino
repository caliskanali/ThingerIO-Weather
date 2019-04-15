#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>
#include <SHT1x.h>


long timer = 0;


#define USERNAME "xxxxxxxx"
#define DEVICE_ID "xxxxxxxx"
#define DEVICE_CREDENTIAL "xxxxxxxx"

#define SSID "xxxxxxxx"
#define SSID_PASSWORD "xxxxxxxx"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// Specify data and clock connections and instantiate SHT1x object
#define dataPin  D7
#define clockPin D6
SHT1x sht1x(dataPin, clockPin);

  float temp_c;
  float temp_f;
  float humidity;

  
void setup() {
  

  thing.add_wifi(SSID, SSID_PASSWORD);


thing["SHTtemp"] >> outputValue(temp_c);
thing["SHThumi"] >> outputValue(humidity);


}

void loop() {


  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  humidity = sht1x.readHumidity();
 
  
  thing.handle();
  
}
