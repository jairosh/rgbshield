#include <Adafruit_NeoPixel.h>
 
#define PIN   6
#define LED_NUM 40
 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);
 
 
void setup() 
{
  leds.begin(); // This initializes the NeoPixel library.
}
 
 
 
void led_set(uint8_t R, uint8_t G, uint8_t B) 
{
  for (int i = 0; i < LED_NUM; i++) 
  {
    leds.setPixelColor(i, leds.Color(R, G, B));
    leds.show();
    delay(150);
  }
}
 
void loop() {
 
  led_set(10, 0, 0);//red
  led_set(0, 0, 0);
 
  led_set(0, 10, 0);//green
  led_set(0, 0, 0);
 
  led_set(0, 0, 10);//blue
  led_set(0, 0, 0);
 
}
