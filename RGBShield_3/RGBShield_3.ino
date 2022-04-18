#include <Adafruit_NeoPixel.h>
 
#define PIN     6
#define LED_NUM 40
 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);
 
 
void setup() 
{
  leds.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}
 
 
void loop() 
{
  //you can make the colours 255 but that is bright
  int redRandom = random(10);
  int greenRandom = random(10);
  int blueRandom = random(10);
  int ledRandom = random(LED_NUM);
  leds.setPixelColor(ledRandom, leds.Color(redRandom, greenRandom, blueRandom));
  leds.show();
  delay(50);
}
