
#include <Adafruit_NeoPixel.h>

#define PIN            6
#define NUMPIXELS      16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int sensorValue = 0;
int timeAccum = 0;
bool pressed = false;
int maxSitTime = 10;


void toggleLight(){

}
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
  pinMode(A1,INPUT);
  pinMode(13,OUTPUT);
}


void loop() {
  if (timeAccum > maxSitTime){
      for(int i=0;i<NUMPIXELS;i++){
        if(i%2 == 0){
          pixels.setPixelColor(i, pixels.Color(2,73,89)); // Moderately bright green color.
        }
        else{
          pixels.setPixelColor(i, pixels.Color(255,0,0)); // Moderately bright green color.
        }
        pixels.show(); // This sends the updated pixel color to the hardware.    
      }  
  }
  digitalWrite(13,255);
  delay(1000);
  digitalWrite(13,0);
  sensorValue = analogRead(A1);
  if (sensorValue > 200) {
    pressed = true;
    timeAccum = timeAccum + 1;
  }
  else{
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.    
    }    
    pressed = false;
    timeAccum = 0;
  }
}


