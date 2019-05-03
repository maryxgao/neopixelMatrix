#include <Adafruit_NeoPixel.h>
#define LED_PIN 11 // Pin # Arduino is connected to Neopixel
#define LED_COUNT 8 // Number of NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); // Declare NeoPixel strip object

void setup() {
  Serial.begin(115200);
  Serial.println("MiCS-5524 demo!");
  strip.begin();
  strip.show(); // initialize all pixels to off
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int reading = analogRead(A0);
  Serial.println(reading);
  if (reading > 100){
    strip.setPixelColor(0, 255, 0, 127);
  }
  else {
    strip.clear();
    strip.show();
  }

  analogWrite(LED_PIN, reading);
  delay(50);

}
