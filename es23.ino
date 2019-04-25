#include <gfxfont.h>

#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_NeoMatrix.h>

#include <gamma.h>

// which pin on the Arduino is connected to the NeoPixels?
#define PIN 6   

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 48, PIN,
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
  matrix.drawLine(0, 12, 0, 28, WHITE); 
  matrix.drawLine(1, 9, 1, 34, WHITE); 
  matrix.drawLine(2, 6, 2, 36, WHITE); 
  matrix.drawLine(3, 5, 3, 37, WHITE); 
  matrix.drawLine(4, 5, 4, 36, WHITE); 
  matrix.drawLine(5, 7, 5, 34, WHITE); 
  matrix.drawLine(6, 12, 6, 16, WHITE); 
  matrix.drawLine(7, 0, 7, 12, WHITE); 
  matrix.drawLine(8, 0, 8, 12, WHITE); 
  matrix.drawLine(9, 12, 9, 16, WHITE); 
  matrix.drawLine(10, 7, 10, 34, WHITE); 
  matrix.drawLine(11, 5, 11, 36, WHITE); 
  matrix.drawLine(12, 5, 12, 37, WHITE);
  matrix.drawLine(13, 6, 13, 36, WHITE); 
  matrix.drawLine(14, 9, 14, 34, WHITE);
  matrix.drawLine(15, 12, 15, 28, WHITE); 

  // from up to down, drawing rows for the light blue part of car
  matrix.drawLine(3, 43, 5, 43, BLUE); 
  matrix.drawLine(4, 44, 5, 44, BLUE); 
  matrix.drawLine(2, 45, 6, 45, BLUE); 
  matrix.drawLine(2, 46, 6, 46, BLUE); 

  // individual window, two wheels
  matrix.drawPixel(3, 47, WHEELS);
  matrix.drawPixel(3, 47, WHEELS);
  matrix.drawPixel(3, 44, GREY);

  matrix.show();
}

int DARK_GREY = (int) matrix.Color(105, 105, 105);
int CRIMSON = (int) matrix.Color(153, 0, 0);
int PINKER = (int) matrix.Color(255, 153, 143);
int WHITE_INT = (int) matrix.Color(255, 255, 255);

int i = 0;


int myArray[MOVE_LEN][4] = {
                     { 7, 46, DARK_GREY, 500},
                     // state 2
                     { 7, 46, OFF, 0},
                     { 8, 45, DARK_GREY, 500},
                      // state 3
                     { 8, 45, OFF, 0},
                     { 9, 44, DARK_GREY, 500},
                      // state 4
                     { 9, 44, OFF, 0},
                     {10, 43, DARK_GREY, 500},
                      // state 5
                     {10, 43, OFF, 0},
                     {11, 42, DARK_GREY, 500},
                      // state 6, every 2
                     {11, 42, OFF, 0},
                     {12, 41, DARK_GREY, 500}, 
                     {12, 41, OFF, 0},
                     {12, 40, DARK_GREY, 500},
                     {12, 40, OFF, 0},
                     {12, 39, DARK_GREY, 500},
                     {12, 39, OFF, 0},
                     {12, 38, DARK_GREY, 500},
                     {12, 38, OFF, 0},
                     {12, 37, CRIMSON, 750},
                     // first lung unit dissapears
                     {12, 37, OFF, 500},
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     {8, 45, OFF, 0},
                     {8, 44, DARK_GREY, 500},
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 500},
                     {8, 43, OFF, 0},
                     {8, 42, DARK_GREY, 500},
                     {8, 42, OFF, 0},
                     {7, 41, DARK_GREY, 500},
                     {7, 41, OFF, 0},
                     {6, 40, DARK_GREY, 500},
                     // state 19
                     {6, 40, OFF, 0},
                     {5, 39, DARK_GREY, 500},
                     {5, 39, OFF, 0},
                     {4, 38, DARK_GREY, 500},
                     {4, 38, OFF, 0},
                     {3, 37, CRIMSON, 750},
                     // second unit dissapears
                     {3, 37, OFF, 500},
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     {8, 45, OFF, 0},
                     {8, 44, DARK_GREY, 500},
                     // state 26
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 500},
                     {8, 43, OFF, 0},
                     {9, 42, DARK_GREY, 500},
                     {9, 42, OFF, 0},
                     {9, 41, DARK_GREY, 500},
                     {9, 41, OFF, 0},
                     {9, 40, DARK_GREY, 500},
                     {9, 40, OFF, 0},
                     {9, 39, DARK_GREY, 500},
                     {9, 38, OFF, 0},
                     {9, 37, DARK_GREY, 500},
                     {9, 37, OFF, 0},
                     {9, 36, DARK_GREY, 500},
                     {9, 36, OFF, 0},
                     {9, 35, DARK_GREY, 500},
                     {9, 35, OFF, 0},
                     {10, 34, CRIMSON, 750},
                     // third lung dissapears 
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     {8, 45, OFF, 0}, 
                     {9, 44, DARK_GREY, 500},
                     {9, 44, OFF, 0},
                     {10, 43, DARK_GREY, 500},
                     // state 40
                     {10, 43, OFF, 0},
                     {11, 42, DARK_GREY, 500},
                     {11, 42, OFF, 0},
                     {12, 41, DARK_GREY, 500},
                     {12, 41, OFF, 0},
                     {12, 40, 5, 500},
                     {12, 41, OFF, 0},
                     {12, 40, 5, 500},
                     // state 44
                     {12, 40, OFF, 0},
                     {12, 39, DARK_GREY, 500},
                     {12, 39, OFF, 0},
                     {12, 38, CRIMSON, 750},
                     // 4th unit dissapears
                     {12, 39,  OFF, 0},
                     {12, 38,  DARK_GREY, 500},
                     {7, 46,  DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     {8, 45, OFF, 0},
                     {9, 44, DARK_GREY, 500},
                     {9, 44, OFF, 0},
                     {10, 43, DARK_GREY, 500},
                     {10, 43, OFF, 0},
                     {10, 42, DARK_GREY, 500},
                     {10, 42, OFF, 0},
                     {11, 41, DARK_GREY, 500},
                     {11, 41, OFF, 0},
                     {11, 40, DARK_GREY, 500},
                     {11, 40, OFF, 0},
                     {11, 39, DARK_GREY, 500},
                     {11, 39, OFF, 0},
                     {11, 38, DARK_GREY, 500},
                     {11, 38, OFF, 0},
                     {11, 37, DARK_GREY, 500},
                     {11, 37, OFF, 0},
                     {11, 36, CRIMSON, 750},
                     // lung unit dissapears
                     {11, 36, OFF, 500},
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     {8, 45, OFF, 0},
                     {8, 44, DARK_GREY, 500},
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 500},
                     {8, 43, OFF, 0},
                     {8, 42, DARK_GREY, 500},
                     {8, 42, OFF, 0},
                     {8, 41, DARK_GREY, 500},
                     {8, 41, OFF, 0},
                     {7, 40, DARK_GREY, 500},
                     {7, 40, OFF, 0},
                     {6, 39, DARK_GREY, 500},
                     {6, 39, OFF, 0},
                     {5, 38, DARK_GREY, 500},
                     {5, 38, OFF, 0},
                     {5, 37, DARK_GREY, 500},
                     {5, 37, OFF, 0},
                     {4, 36, CRIMSON, 750},
                     // lung unit dissapears
                     {4, 36, OFF, 500},
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 46, DARK_GREY, 500},
                     {8, 46, OFF, 0},
                     {9, 46, DARK_GREY, 500},
                     {9, 46, OFF, 0},
                     {10, 45, DARK_GREY, 500},
                     {10, 45, OFF, 0},
                     {11, 44, OFF, 0},
                     // state 77
                     {11, 44, OFF, 0},
                     {12, 43, DARK_GREY, 500},
                     {12, 43, OFF, 0},
                     {12, 42, DARK_GREY, 500},
                     {12, 42, OFF, 0},
                     {12, 41, DARK_GREY, 500},
                     {12, 41, OFF, 0},
                     {12, 40, DARK_GREY, 500},
                     {12, 40, OFF, 0},
                     {12, 39, DARK_GREY, 500},
                     {12, 39, OFF, 0},
                     {12, 38, DARK_GREY, 500},
                     {12, 38, OFF, 0},
                     {12, 37, DARK_GREY, 500},
                     {12, 37, OFF, 0},
                     {12, 36, DARK_GREY, 500},
                     {12, 36, OFF, 0},
                     {12, 35, CRIMSON, 500},
                     // 6th lung dissapears
                     {12, 35, OFF, 500},
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     // start of state 89
                     {8, 45, OFF, 0},
                     {8, 44, DARK_GREY, 500},
                     // state 90
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 500},
                     {8, 43, OFF, 0},
                     {9, 42, DARK_GREY, 500},
                     {9, 42, OFF, 0},
                     {10, 41, DARK_GREY, 500},
                     {10, 41, OFF, 0},
                     {11, 40, DARK_GREY, 500},
                     {11, 40, OFF, 0},
                     {11, 39, DARK_GREY, 500},
                     {11, 39, OFF, 0},
                     {11, 38, DARK_GREY, 500},
                     {11, 38, OFF, 0},
                     {11, 37, DARK_GREY, 500},
                     {11, 37, OFF, 0},
                     {11, 36, DARK_GREY, 500},
                     {11, 36, OFF, 0},
                     {11, 35, CRIMSON, 750},
                     // 7th lung dissapears
                     {11, 35, OFF, 500},
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     {8, 45, OFF, 0},
                     {8, 44, DARK_GREY, 500},
                     {8, 44, OFF, 0},
                     {7, 43, DARK_GREY, 500},
                     {7, 43, OFF, 0},
                     {7, 42, DARK_GREY, 500},
                     {7, 42, OFF, 0},
                     {6, 41, DARK_GREY, 500},
                     {6, 41, OFF, 0},
                     {5, 40, DARK_GREY, 500},
                     {5, 40, OFF, 500},
                     {4, 39, DARK_GREY, 500},
                     {4, 39, OFF, 0},
                     {3, 38, DARK_GREY, 500},
                     {3, 38, OFF, 0},
                     {3, 37, CRIMSON, 750},
                     //8th lung dissapears
                     {3, 37, OFF, 500},
                     //state 112
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     {8, 45, OFF, 0},
                     {8, 44, DARK_GREY, 500},
                     {8, 44, OFF, 0},
                     {8, 43, DARK_GREY, 500},
                     {8, 43, OFF, 0},
                     {7, 42, DARK_GREY, 500},
                     {7, 42, OFF, 0},
                     {6, 41, DARK_GREY, 500},
                     {6, 41, OFF, 0},
                     {5, 40, DARK_GREY, 500},
                     {5, 40, OFF, 0},
                     {4, 39, DARK_GREY, 500},
                     {4, 39, OFF, 0},
                     {3, 38, DARK_GREY, 500},
                     {3, 38, OFF, 0},
                     {4, 37, DARK_GREY, 500},
                     {4, 37, OFF, 0},
                     {4, 36, CRIMSON, 750},
                     //9th dissapears
                     {4, 36, OFF, 500},
                     {7, 46, DARK_GREY, 500},
                     {7, 46, OFF, 0},
                     {8, 45, DARK_GREY, 500},
                     {8, 45, OFF, 0},
                     {9, 44, DARK_GREY, 500},
                     {9, 44, OFF, 0},
                     {10, 43, DARK_GREY, 500},
                     {10, 43, OFF, 0},
                     {11, 42, DARK_GREY, 500},
                     {11, 42, OFF, 0},
                     {12, 41, DARK_GREY, 500},
                     {12, 41, OFF, 0},
                     {13, 40, DARK_GREY, 500},
                     {13, 40, OFF, 0},
                     {13, 39, DARK_GREY, 500},
                     {13, 39, OFF, 0},
                     {13, 38, DARK_GREY, 500},
                     {13, 38, OFF, 0},
                     {13, 37, DARK_GREY, 500},
                     {13, 37, OFF, 0},
                     {13, 36, CRIMSON, 750},
                     {13, 36, OFF, 500},
                     
                     // begin dramatic ending
                     {1, 32, PINKER, 0},
                     {1, 33, PINKER, 0},
                     {1, 34, PINKER, 0},
                     {2, 32, PINKER, 0},
                     {2, 33, PINKER, 0},
                     {2, 34, PINKER, 0},
                     {2, 35, PINKER, 0},
                     {2, 36, PINKER, 0},
                     {3, 32, PINKER, 0},
                     {3, 33, PINKER, 0},
                     {3, 34, PINKER, 0},
                     {3, 35, PINKER, 0},
                     {4, 32, PINKER, 0},
                     {4, 33, PINKER, 0},
                     {4, 34, PINKER, 0},
                     {4, 35, PINKER, 0},
                     {5, 32, PINKER, 0},
                     {5, 33, PINKER, 0},
                     {5, 34, PINKER, 0},
                     {10, 32, PINKER, 0},
                     {10, 33, PINKER, 0},
                     {11, 32, PINKER, 0},
                     {11, 33, PINKER, 0},
                     {11, 34, PINKER, 0},
                     {12, 32, PINKER, 0},
                     {12, 33, PINKER, 0},
                     {12, 34, PINKER, 0},
                     {13, 32, PINKER, 0},
                     {13, 33, PINKER, 0},
                     {13, 34, PINKER, 0},
                     {13, 35, PINKER, 0},
                     {14, 32, PINKER, 0},
                     {14, 33, PINKER, 1000},
                     // state 137
                     {0, 25, PINKER, 0},
                     {0, 26, PINKER, 0},
                     {0, 27, PINKER, 0},
                     {0, 28, PINKER, 0},
                     {1, 26, PINKER, 0},
                     {1, 27, PINKER, 0},
                     {1, 28, PINKER, 0},
                     {1, 29, PINKER, 0},
                     {1, 30, PINKER, 0},
                     {1, 31, PINKER, 0},
                     {2, 26, WHITE_INT, 0},
                     {2, 27, PINKER, 0},
                     {2, 28, PINKER, 0},
                     {2, 29, PINKER, 0},
                     {2, 30, PINKER, 0},
                     {2, 31, CRIMSON, 0}, 
                     {3, 26, PINKER, 0},
                     {3, 27, PINKER, 0},
                     {3, 28, PINKER, 0},
                     {3, 29, PINKER, 0},
                     {3, 30, PINKER, 0},
                     {3, 31, PINKER, 0},
                     {4, 25, PINKER, 0},
                     {4, 26, PINKER, 0},
                     {4, 27, PINKER, 0},
                     {4, 28, PINKER, 0},
                     {4, 29, PINKER, 0},
                     {4, 30, PINKER, 0},
                     {4, 31, PINKER, 0},
                     {5, 26, PINKER, 0},
                     {5, 27, PINKER, 0},
                     {5, 28, PINKER, 0},
                     {5, 29, PINKER, 0},
                     {5, 30, PINKER, 0},
                     {5, 31, PINKER, 0},
                     {10, 26, PINKER, 0},
                     {10, 27, PINKER, 0},
                     {10, 28, PINKER, 0},
                     {10, 29, PINKER, 0},
                     {10, 30, PINKER, 0},
                     {10, 31, PINKER, 0},
                     {11, 26, WHITE_INT, 0},
                     {11, 27, PINKER, 0},   
                     {11, 28, PINKER, 0},
                     {11, 29, PINKER, 0},
                     {11, 30, PINKER, 0},
                     {11, 31, PINKER, 0},
                     {12, 26, PINKER, 0},
                     {12, 27, PINKER, 0},
                     {12, 28, PINKER, 0},
                     {12, 29, PINKER, 0},
                     {12, 30, PINKER, 0},
                     {12, 31, PINKER, 0},
                     {13, 25, PINKER, 0},
                     {13, 26, PINKER, 0},
                     {13, 27, PINKER, 0},
                     {13, 28, PINKER, 0},
                     {13, 29, PINKER, 0},
                     {13, 30, PINKER, 0},
                     {13, 31, CRIMSON, 0},
                     {14, 26, PINKER, 0},
                     {14, 27, PINKER, 0},
                     {14, 28, PINKER, 0},
                     {14, 29, PINKER, 0},
                     {14, 30, PINKER, 0},
                     {14, 31, PINKER, 0},
                     {15, 26, PINKER, 0},
                     {15, 27, PINKER, 0},
                     {15, 28, PINKER, 0},      
                     {1, 32, CRIMSON, 0},
                     {1, 33, CRIMSON, 0},
                     {1, 34, CRIMSON, 0},
                     {2, 32, CRIMSON, 0},
                     {2, 33, CRIMSON, 0},
                     {2, 34, CRIMSON, 0},
                     {2, 35, CRIMSON, 0},
                     {2, 36, CRIMSON, 0},
                     {3, 32, CRIMSON, 0},
                     {3, 33, CRIMSON, 0},
                     {3, 34, CRIMSON, 0},
                     {3, 35, CRIMSON, 0},
                     {4, 32, CRIMSON, 0},
                     {4, 33, CRIMSON, 0},
                     {4, 34, CRIMSON, 0},
                     {4, 35, CRIMSON, 0},
                     {5, 32, PINKER, 0},
                     {5, 33, CRIMSON, 0},
                     {5, 34, CRIMSON, 0},
                     {10, 32, CRIMSON, 0},
                     {10, 33, CRIMSON, 0},
                     {11, 32, PINKER, 0},
                     {11, 33, CRIMSON, 0},
                     {11, 34, CRIMSON, 0},
                     {12, 32, CRIMSON, 0},
                     {12, 33, CRIMSON, 0},
                     {12, 34, CRIMSON, 0},
                     {13, 32, CRIMSON, 0},
                     {13, 33, CRIMSON, 0},
                     {13, 34, CRIMSON, 0},
                     {13, 35, CRIMSON, 0},
                     {14, 32, CRIMSON, 0},
                     {14, 33, CRIMSON, 1000} };
                      // state 138
                    

// chamges pixel at x,y to color
void movePixel(int x, int y, int color) {
}


void setup(void)
{
  Serial.begin(9600);
  
  delay(50);
  
  matrix.begin();
  matrix.setBrightness(50);
  matrix.fillScreen(0);
  matrix.show();
  
  initial();
  
  Serial.println("GOT DISPLAYED INITIAL");
}

void loop(void)
{ 
  Serial.println("GOT TO LOOP");
  if (i == 0) {
    initial();
  } else {
    movePixel(myArray[i][0], myArray[i][1], myArray[i][2]);
    delay(myArray[i][3]);
  }
  i = (i + 1) % MOVE_LEN;
  
}  
