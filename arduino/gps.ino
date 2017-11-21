#include <SoftwareSerial.h>
#include <TimeLib.h>
#include <TinyGPS++.h>


static const int RXPin = 4, TXPin = 3;

TinyGPSPlus gps;

SoftwareSerial Serial_GPS(RXPin, TXPin);

void setup()
{
  //Baud rate Arduino
  Serial.begin(115200);
  //Baud rate Modulo GPS
  Serial_GPS.begin(9600);

  Serial.println(F("Module GPS GY-NEO6MV2"));
  Serial.print(F("TinyGPS++ v. ")); 
  Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println();
}

void loop(){

  while (Serial_GPS.available() > 0){
    if (gps.encode(Serial_GPS.read())){
      Serial.print(gps.location.lat(), 6); //latitude
      Serial.print(F(","));
      Serial.println(gps.location.lng(), 6); //longitude
    }
  }
}
