#include <Adafruit_NeoPixel.h>
 
#define PIN     6
#define LED_NUM 40
 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);
 
 
void setup() 
{
  leds.begin(); // This initializes the NeoPixel library.
}
 
 
 
void loop() 
{
  for (int i = 0; i < LED_NUM; i++) 
  {
  leds.setPixelColor(i, leds.Color(10, 0, 0));
  leds.show();
  delay(250);
 
  leds.setPixelColor(i, leds.Color(0, 10, 0));
  leds.show();
  delay(250);
 
  leds.setPixelColor(i, leds.Color(0, 0, 10));
  leds.show();
  delay(250);
  }
}
