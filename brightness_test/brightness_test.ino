#include <gfxfont.h>

#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_NeoMatrix.h>

#include <gamma.h>

// which pin on the Arduino is connected to the NeoPixels?
#define PIN 6   

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 47, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

#define OFF matrix.Color(0, 0, 0)
#define WHITE matrix.Color(255, 255, 255)
#define BLUE matrix.Color(70, 130, 180)
#define WHEELS matrix.Color(32, 32, 32)
#define GREY matrix.Color(190, 190, 190)

#define MOVE_LEN 379

void setup(void)
{
  Serial.begin(9600);
  
  delay(500);
  
  matrix.begin();
  matrix.setBrightness(20);
  matrix.fillScreen(WHITE);
  matrix.show();
  
  Serial.println("GOT DISPLAYED INITIAL");
}

void loop(void)
{ 
  
}  
