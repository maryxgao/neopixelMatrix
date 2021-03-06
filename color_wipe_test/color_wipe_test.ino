#include <gfxfont.h>

#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_NeoMatrix.h>

#include <gamma.h>

#define PIN 6   // which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN 11 // Pin # Arduino is connected to Neopixel


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

void initial() {
  // from left to right, drawing vertical columns for the lungs
  matrix.drawLine(0, 11, 0, 27, WHITE); 
  matrix.drawLine(1, 8, 1, 33, WHITE); 
  matrix.drawLine(2, 5, 2, 35, WHITE); 
  matrix.drawLine(3, 4, 3, 36, WHITE); 
  matrix.drawLine(4, 4, 4, 35, WHITE); 
  matrix.drawLine(5, 6, 5, 33, WHITE); 
  matrix.drawLine(6, 9, 6, 13, WHITE); 
  matrix.drawLine(7, 0, 7, 13, WHITE); 
  matrix.drawLine(8, 0, 8, 13, WHITE); 
  matrix.drawLine(9, 9, 9, 13, WHITE); 
  matrix.drawLine(10, 6, 10, 33, WHITE); 
  matrix.drawLine(11, 4, 11, 35, WHITE); 
  matrix.drawLine(12, 4, 12, 36, WHITE);
  matrix.drawLine(13, 5, 13, 35, WHITE); 
  matrix.drawLine(14, 8, 14, 33, WHITE);
  matrix.drawLine(15, 11, 15, 27, WHITE); 

  // from up to down, drawing rows for the light blue part of car
  matrix.drawLine(3, 42, 5, 42, BLUE); 
  matrix.drawLine(4, 43, 5, 43, BLUE); 
  matrix.drawLine(2, 44, 6, 44, BLUE); 
  matrix.drawLine(2, 45, 6, 45, BLUE); 

  // individual window, two wheels
  matrix.drawPixel(3, 46, WHEELS);
  matrix.drawPixel(3, 46, WHEELS);
  matrix.drawPixel(3, 43, GREY);

  matrix.show();
}

int DARK_GREY = (int) matrix.Color(105, 105, 105);
int CRIMSON = (int) matrix.Color(153, 0, 0);
int PINKER = (int) matrix.Color(255, 153, 143);
int WHITE_INT = (int) matrix.Color(255, 255, 255);

int i = 0;


int myArray[MOVE_LEN][4] = {
                     { 7, 45, DARK_GREY, 2000},
                     // state 2
                     { 7, 45, OFF, 0},
                     { 8, 44, DARK_GREY, 2000},
                      // state 3
                     { 8, 44, OFF, 0},
                     { 9, 43, DARK_GREY, 2000},
                      // state 4
                     { 9, 43, OFF, 0},
                     {10, 42, DARK_GREY, 2000},
                      // state 5
                     {10, 42, OFF, 0},
                     {11, 41, DARK_GREY, 2000},
                      // state 6, every 2
                     {11, 41, OFF, 0},
                     {12, 40, DARK_GREY, 2000}, 
                     {12, 40, OFF, 0},
                     {12, 30, DARK_GREY, 2000},
                     {12, 39, OFF, 0},
                     {12, 38, DARK_GREY, 2000},
                     {12, 38, OFF, 0},
                     {12, 37, DARK_GREY, 2000},
                     {12, 37, OFF, 0},
                     {12, 36, CRIMSON, 750},
                     // first lung unit dissapears
                     {12, 36, OFF, 2000},
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 2000},
                     {8, 43, OFF, 0},
                     {8, 42, DARK_GREY, 2000},
                     {8, 42, OFF, 0},
                     {8, 41, DARK_GREY, 2000},
                     {8, 41, OFF, 0},
                     {7, 40, DARK_GREY, 2000},
                     {7, 40, OFF, 0},
                     {6, 39, DARK_GREY, 2000},
                     // state 19
                     {6, 39, OFF, 0},
                     {5, 38, DARK_GREY, 2000},
                     {5, 38, OFF, 0},
                     {4, 37, DARK_GREY, 2000},
                     {4, 37, OFF, 0},
                     {3, 36, CRIMSON, 750},
                     // second unit dissapears
                     {3, 36, OFF, 2000},
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 2000},
                     // state 26
                     {8, 43, OFF, 0},
                     {8, 42, DARK_GREY, 2000},
                     {8, 42, OFF, 0},
                     {9, 41, DARK_GREY, 2000},
                     {9, 41, OFF, 0},
                     {9, 40, DARK_GREY, 2000},
                     {9, 40, OFF, 0},
                     {9, 39, DARK_GREY, 2000},
                     {9, 39, OFF, 0},
                     {9, 38, DARK_GREY, 2000},
                     {9, 37, OFF, 0},
                     {9, 36, DARK_GREY, 2000},
                     {9, 36, OFF, 0},
                     {9, 35, DARK_GREY, 2000},
                     {9, 35, OFF, 0},
                     {9, 34, DARK_GREY, 2000},
                     {9, 34, OFF, 0},
                     {10, 33, CRIMSON, 750},
                     // third lung dissapears 
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     {8, 44, OFF, 0}, 
                     {9, 43, DARK_GREY, 2000},
                     {9, 43, OFF, 0},
                     {10, 42, DARK_GREY, 2000},
                     // state 40
                     {10, 42, OFF, 0},
                     {11, 41, DARK_GREY, 2000},
                     {11, 41, OFF, 0},
                     {12, 40, DARK_GREY, 2000},
                     {12, 40, OFF, 0},
                     {12, 39, 5, 2000},
                     {12, 40, OFF, 0},
                     {12, 39, 5, 2000},
                     // state 44
                     {12, 39, OFF, 0},
                     {12, 38, DARK_GREY, 2000},
                     {12, 38, OFF, 0},
                     {12, 37, CRIMSON, 750},
                     // 4th unit dissapears
                     {12, 38,  OFF, 0},
                     {12, 37,  DARK_GREY, 2000},
                     {7, 45,  DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     {8, 44, OFF, 0},
                     {9, 43, DARK_GREY, 2000},
                     {9, 43, OFF, 0},
                     {10, 42, DARK_GREY, 2000},
                     {10, 42, OFF, 0},
                     {10, 41, DARK_GREY, 2000},
                     {10, 41, OFF, 0},
                     {11, 40, DARK_GREY, 2000},
                     {11, 40, OFF, 0},
                     {11, 39, DARK_GREY, 2000},
                     {11, 39, OFF, 0},
                     {11, 38, DARK_GREY, 2000},
                     {11, 38, OFF, 0},
                     {11, 37, DARK_GREY, 2000},
                     {11, 37, OFF, 0},
                     {11, 36, DARK_GREY, 2000},
                     {11, 36, OFF, 0},
                     {11, 35, CRIMSON, 750},
                     // lung unit dissapears
                     {11, 35, OFF, 2000},
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 2000},
                     {8, 43, OFF, 0},
                     {8, 42, DARK_GREY, 2000},
                     {8, 42, OFF, 0},
                     {8, 41, DARK_GREY, 2000},
                     {8, 41, OFF, 0},
                     {8, 40, DARK_GREY, 2000},
                     {8, 40, OFF, 0},
                     {7, 39, DARK_GREY, 2000},
                     {7, 39, OFF, 0},
                     {6, 38, DARK_GREY, 2000},
                     {6, 38, OFF, 0},
                     {5, 37, DARK_GREY, 2000},
                     {5, 37, OFF, 0},
                     {5, 36, DARK_GREY, 2000},
                     {5, 36, OFF, 0},
                     {4, 35, CRIMSON, 750},
                     // lung unit dissapears
                     {4, 35, OFF, 2000},
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 45, DARK_GREY, 2000},
                     {8, 45, OFF, 0},
                     {9, 45, DARK_GREY, 2000},
                     {9, 45, OFF, 0},
                     {10, 44, DARK_GREY, 2000},
                     {10, 44, OFF, 0},
                     {11, 43, OFF, 0},
                     // state 77
                     {11, 43, OFF, 0},
                     {12, 42, DARK_GREY, 2000},
                     {12, 42, OFF, 0},
                     {12, 41, DARK_GREY, 2000},
                     {12, 41, OFF, 0},
                     {12, 40, DARK_GREY, 2000},
                     {12, 40, OFF, 0},
                     {12, 39, DARK_GREY, 2000},
                     {12, 39, OFF, 0},
                     {12, 38, DARK_GREY, 2000},
                     {12, 38, OFF, 0},
                     {12, 37, DARK_GREY, 2000},
                     {12, 37, OFF, 0},
                     {12, 36, DARK_GREY, 2000},
                     {12, 36, OFF, 0},
                     {12, 35, DARK_GREY, 2000},
                     {12, 35, OFF, 0},
                     {12, 34, CRIMSON, 2000},
                     // 6th lung dissapears
                     {12, 34, OFF, 2000},
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     // start of state 89
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 2000},
                     // state 90
                     {8, 43, OFF, 0},
                     {8, 42, DARK_GREY, 2000},
                     {8, 42, OFF, 0},
                     {9, 41, DARK_GREY, 2000},
                     {9, 41, OFF, 0},
                     {10, 40, DARK_GREY, 2000},
                     {10, 40, OFF, 0},
                     {11, 39, DARK_GREY, 2000},
                     {11, 39, OFF, 0},
                     {11, 38, DARK_GREY, 2000},
                     {11, 38, OFF, 0},
                     {11, 37, DARK_GREY, 2000},
                     {11, 37, OFF, 0},
                     {11, 36, DARK_GREY, 2000},
                     {11, 36, OFF, 0},
                     {11, 35, DARK_GREY, 2000},
                     {11, 35, OFF, 0},
                     {11, 34, CRIMSON, 750},
                     // 7th lung dissapears
                     {11, 34, OFF, 2000},
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 2000},
                     {8, 43, OFF, 0},
                     {7, 42, DARK_GREY, 2000},
                     {7, 42, OFF, 0},
                     {7, 41, DARK_GREY, 2000},
                     {7, 41, OFF, 0},
                     {6, 40, DARK_GREY, 2000},
                     {6, 40, OFF, 0},
                     {5, 39, DARK_GREY, 2000},
                     {5, 39, OFF, 2000},
                     {4, 38, DARK_GREY, 2000},
                     {4, 38, OFF, 0},
                     {3, 37, DARK_GREY, 2000},
                     {3, 37, OFF, 0},
                     {3, 36, CRIMSON, 750},
                     //8th lung dissapears
                     {3, 36, OFF, 2000},
                     //state 112
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 2000},
                     {8, 43, OFF, 0},
                     {8, 42, DARK_GREY, 2000},
                     {8, 42, OFF, 0},
                     {7, 41, DARK_GREY, 2000},
                     {7, 41, OFF, 0},
                     {6, 40, DARK_GREY, 2000},
                     {6, 40, OFF, 0},
                     {5, 39, DARK_GREY, 2000},
                     {5, 39, OFF, 0},
                     {4, 38, DARK_GREY, 2000},
                     {4, 38, OFF, 0},
                     {3, 37, DARK_GREY, 2000},
                     {3, 37, OFF, 0},
                     {4, 36, DARK_GREY, 2000},
                     {4, 36, OFF, 0},
                     {4, 35, CRIMSON, 750},
                     //9th dissapears
                     {4, 35, OFF, 2000},
                     {7, 45, DARK_GREY, 2000},
                     {7, 45, OFF, 0},
                     {8, 44, DARK_GREY, 2000},
                     {8, 44, OFF, 0},
                     {9, 43, DARK_GREY, 2000},
                     {9, 43, OFF, 0},
                     {10, 42, DARK_GREY, 2000},
                     {10, 42, OFF, 0},
                     {11, 41, DARK_GREY, 2000},
                     {11, 41, OFF, 0},
                     {12, 40, DARK_GREY, 2000},
                     {12, 40, OFF, 0},
                     {13, 39, DARK_GREY, 2000},
                     {13, 39, OFF, 0},
                     {13, 38, DARK_GREY, 2000},
                     {13, 38, OFF, 0},
                     {13, 37, DARK_GREY, 2000},
                     {13, 37, OFF, 0},
                     {13, 36, DARK_GREY, 2000},
                     {13, 36, OFF, 0},
                     {13, 35, CRIMSON, 750},
                     {13, 35, OFF, 2000},
                     

// changes pixel at x,y to color
void movePixel(int x, int y, int color) {
}


void setup(void)
{
  Serial.begin(9600);
  Serial1.begin(115200);
  Serial1.println("MiCS-5524 demo!");
  
  delay(2000);
  
  matrix.begin();
  matrix.setBrightness(80);
  matrix.fillScreen(0);
  matrix.show();

  pinMode(LED_PIN, OUTPUT);
  
  initial();
  
  Serial.println("GOT DISPLAYED INITIAL");
}

void loop(void)
{ 
  Serial.println("GOT TO LOOP");
  int reading = analogRead(A0);
  Serial1.println(reading);
  if (reading > 100) {
    if (i == 0) {
      initial(); 
      } 
    else {
      movePixel(myArray[i][0], myArray[i][1], myArray[i][2]);
      delay(myArray[i][3]);
      }
    i = (i + 1) % MOVE_LEN;
  }
  else {
    matrix.fillScreen(0);
    matrix.show();
  }
  
  analogWrite(LED_PIN, reading);
  delay(50);
  
}  
