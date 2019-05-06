#include <gfxfont.h>

#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_NeoMatrix.h>

#include <gamma.h>

// which pin on the Arduino is connected to the NeoPixels?
#define PIN 6

#define SENSOR_PIN A0

#define GRID_COLS 16
#define GRID_ROWS 47
#define START_POSX 7
#define START_POSY 45

#define LUNG_BLOCKS 367
#define STOP 300 // the number at which to stop destroying lungs and restart
#define CAR_BLOCKS 18
#define NUM_BALLS 8

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(GRID_COLS, GRID_ROWS, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

#define OFF matrix.Color(0, 0, 0)
#define BLUE matrix.Color(150, 0, 150)
#define WHEELS matrix.Color(120, 120, 0)
#define CRIMSON matrix.Color(175, 0, 0)
#define GREY matrix.Color(128, 15, 0)
#define WHITE matrix.Color(255, 255, 255)

// global constants
int lung_counter = LUNG_BLOCKS;
int led = 13;
bool triggered = false;

struct ball;

void debug(const char* s, ball* b);
void initial(void);

int lungs[LUNG_BLOCKS][3] = {
  {7, 0, 0},
  {8, 0, 0},
  {7, 1, 0},
  {8, 1, 0},
  {7, 2, 0},
  {8, 2, 0},
  {7, 3, 0},
  {8, 3, 0},
  {3, 4, 0},
  {4, 4, 0},
  {7, 4, 0},
  {8, 4, 0},
  {11, 4, 0},
  {12, 4, 0},
  {2, 5, 0},
  {3, 5, 0},
  {4, 5, 0},
  {7, 5, 0},
  {8, 5, 0},
  {11, 5, 0},
  {12, 5, 0},
  {13, 5, 0},
  {2, 6, 0},
  {3, 6, 0},
  {4, 6, 0},
  {5, 6, 0},
  {7, 6, 0},
  {8, 6, 0},
  {10, 6, 0},
  {11, 6, 0},
  {12, 6, 0},
  {13, 6, 0},
  {2, 7, 0},
  {3, 7, 0},
  {4, 7, 0},
  {5, 7, 0},
  {7, 7, 0},
  {8, 7, 0},
  {10, 7, 0},
  {11, 7, 0},
  {12, 7, 0},
  {13, 7, 0},
  {1, 8, 0},
  {2, 8, 0},
  {3, 8, 0},
  {4, 8, 0},
  {5, 8, 0},
  {7, 8, 0},
  {8, 8, 0},
  {10, 8, 0},
  {11, 8, 0},
  {12, 8, 0},
  {13, 8, 0},
  {14, 8, 0},
  {1, 9, 0},
  {2, 9, 0},
  {3, 9, 0},
  {4, 9, 0},
  {5, 9, 0},
  {6, 9, 0},
  {7, 9, 0},
  {8, 9, 0},
  {9, 9, 0},
  {10, 9, 0},
  {11, 9, 0},
  {12, 9, 0},
  {13, 9, 0},
  {14, 9, 0},
  {1, 10, 0},
  {2, 10, 0},
  {3, 10, 0},
  {4, 10, 0},
  {5, 10, 0},
  {6, 10, 0},
  {7, 10, 0},
  {8, 10, 0},
  {9, 10, 0},
  {10, 10, 0},
  {11, 10, 0},
  {12, 10, 0},
  {13, 10, 0},
  {14, 10, 0},
  {0, 11, 0},
  {1, 11, 0},
  {2, 11, 0},
  {3, 11, 0},
  {4, 11, 0},
  {5, 11, 0},
  {6, 11, 0},
  {7, 11, 0},
  {8, 11, 0},
  {9, 11, 0},
  {10, 11, 0},
  {11, 11, 0},
  {12, 11, 0},
  {13, 11, 0},
  {14, 11, 0},
  {15, 11, 0},
  {0, 12, 0},
  {1, 12, 0},
  {2, 12, 0},
  {3, 12, 0},
  {4, 12, 0},
  {5, 12, 0},
  {6, 12, 0},
  {9, 12, 0},
  {10, 12, 0},
  {11, 12, 0},
  {12, 12, 0},
  {13, 12, 0},
  {14, 12, 0},
  {15, 12, 0},
  {0, 13, 0},
  {1, 13, 0},
  {2, 13, 0},
  {3, 13, 0},
  {4, 13, 0},
  {5, 13, 0},
  {6, 13, 0},
  {9, 13, 0},
  {10, 13, 0},
  {11, 13, 0},
  {12, 13, 0},
  {13, 13, 0},
  {14, 13, 0},
  {15, 13, 0},
  {0, 14, 0},
  {1, 14, 0},
  {2, 14, 0},
  {3, 14, 0},
  {4, 14, 0},
  {5, 14, 0},
  {10, 14, 0},
  {11, 14, 0},
  {12, 14, 0},
  {13, 14, 0},
  {14, 14, 0},
  {15, 14, 0},
  {0, 15, 0},
  {1, 15, 0},
  {2, 15, 0},
  {3, 15, 0},
  {4, 15, 0},
  {5, 15, 0},
  {10, 15, 0},
  {11, 15, 0},
  {12, 15, 0},
  {13, 15, 0},
  {14, 15, 0},
  {15, 15, 0},
  {0, 16, 0},
  {1, 16, 0},
  {2, 16, 0},
  {3, 16, 0},
  {4, 16, 0},
  {5, 16, 0},
  {10, 16, 0},
  {11, 16, 0},
  {12, 16, 0},
  {13, 16, 0},
  {14, 16, 0},
  {15, 16, 0},
  {0, 17, 0},
  {1, 17, 0},
  {2, 17, 0},
  {3, 17, 0},
  {4, 17, 0},
  {5, 17, 0},
  {10, 17, 0},
  {11, 17, 0},
  {12, 17, 0},
  {13, 17, 0},
  {14, 17, 0},
  {15, 17, 0},
  {0, 18, 0},
  {1, 18, 0},
  {2, 18, 0},
  {3, 18, 0},
  {4, 18, 0},
  {5, 18, 0},
  {10, 18, 0},
  {11, 18, 0},
  {12, 18, 0},
  {13, 18, 0},
  {14, 18, 0},
  {15, 18, 0},
  {0, 19, 0},
  {1, 19, 0},
  {2, 19, 0},
  {3, 19, 0},
  {4, 19, 0},
  {5, 19, 0},
  {10, 19, 0},
  {11, 19, 0},
  {12, 19, 0},
  {13, 19, 0},
  {14, 19, 0},
  {15, 19, 0},
  {0, 20, 0},
  {1, 20, 0},
  {2, 20, 0},
  {3, 20, 0},
  {4, 20, 0},
  {5, 20, 0},
  {10, 20, 0},
  {11, 20, 0},
  {12, 20, 0},
  {13, 20, 0},
  {14, 20, 0},
  {15, 20, 0},
  {0, 21, 0},
  {1, 21, 0},
  {2, 21, 0},
  {3, 21, 0},
  {4, 21, 0},
  {5, 21, 0},
  {10, 21, 0},
  {11, 21, 0},
  {12, 21, 0},
  {13, 21, 0},
  {14, 21, 0},
  {15, 21, 0},
  {0, 22, 0},
  {1, 22, 0},
  {2, 22, 0},
  {3, 22, 0},
  {4, 22, 0},
  {5, 22, 0},
  {10, 22, 0},
  {11, 22, 0},
  {12, 22, 0},
  {13, 22, 0},
  {14, 22, 0},
  {15, 22, 0},
  {0, 23, 0},
  {1, 23, 0},
  {2, 23, 0},
  {3, 23, 0},
  {4, 23, 0},
  {5, 23, 0},
  {10, 23, 0},
  {11, 23, 0},
  {12, 23, 0},
  {13, 23, 0},
  {14, 23, 0},
  {15, 23, 0},
  {0, 24, 0},
  {1, 24, 0},
  {2, 24, 0},
  {3, 24, 0},
  {4, 24, 0},
  {5, 24, 0},
  {10, 24, 0},
  {11, 24, 0},
  {12, 24, 0},
  {13, 24, 0},
  {14, 24, 0},
  {15, 24, 0},
  {0, 25, 0},
  {1, 25, 0},
  {2, 25, 0},
  {3, 25, 0},
  {4, 25, 0},
  {5, 25, 0},
  {10, 25, 0},
  {11, 25, 0},
  {12, 25, 0},
  {13, 25, 0},
  {14, 25, 0},
  {15, 25, 0},
  {0, 26, 0},
  {1, 26, 0},
  {2, 26, 0},
  {3, 26, 0},
  {4, 26, 0},
  {5, 26, 0},
  {10, 26, 0},
  {11, 26, 0},
  {12, 26, 0},
  {13, 26, 0},
  {14, 26, 0},
  {15, 26, 0},
  {0, 27, 0},
  {1, 27, 0},
  {2, 27, 0},
  {3, 27, 0},
  {4, 27, 0},
  {5, 27, 0},
  {10, 27, 0},
  {11, 27, 0},
  {12, 27, 0},
  {13, 27, 0},
  {14, 27, 0},
  {15, 27, 0},
  {1, 28, 0},
  {2, 28, 0},
  {3, 28, 0},
  {4, 28, 0},
  {5, 28, 0},
  {10, 28, 0},
  {11, 28, 0},
  {12, 28, 0},
  {13, 28, 0},
  {14, 28, 0},
  {1, 29, 0},
  {2, 29, 0},
  {3, 29, 0},
  {4, 29, 0},
  {5, 29, 0},
  {10, 29, 0},
  {11, 29, 0},
  {12, 29, 0},
  {13, 29, 0},
  {14, 29, 0},
  {1, 30, 0},
  {2, 30, 0},
  {3, 30, 0},
  {4, 30, 0},
  {5, 30, 0},
  {10, 30, 0},
  {11, 30, 0},
  {12, 30, 0},
  {13, 30, 0},
  {14, 30, 0},
  {1, 31, 0},
  {2, 31, 0},
  {3, 31, 0},
  {4, 31, 0},
  {5, 31, 0},
  {10, 31, 0},
  {11, 31, 0},
  {12, 31, 0},
  {13, 31, 0},
  {14, 31, 0},
  {1, 32, 0},
  {2, 32, 0},
  {3, 32, 0},
  {4, 32, 0},
  {5, 32, 0},
  {10, 32, 0},
  {11, 32, 0},
  {12, 32, 0},
  {13, 32, 0},
  {14, 32, 0},
  {1, 33, 0},
  {2, 33, 0},
  {3, 33, 0},
  {4, 33, 0},
  {5, 33, 0},
  {10, 33, 0},
  {11, 33, 0},
  {12, 33, 0},
  {13, 33, 0},
  {2, 34, 0},
  {3, 34, 0},
  {4, 34, 0},
  {11, 34, 0},
  {12, 34, 0},
  {13, 34, 0},
  {2, 35, 0},
  {3, 35, 0},
  {4, 35, 0},
  {11, 35, 0},
  {12, 35, 0},
  {13, 35, 0},
  {3, 36, 0},
  {12, 36, 0}
};

int car[CAR_BLOCKS][2] = {
  {3, 42},
  {4, 42},
  {5, 42},
  {3, 43},
  {4, 43},
  {5, 43},
  {2, 44},
  {3, 44},
  {4, 44},
  {5, 44},
  {6, 44},
  {2, 45},
  {3, 45},
  {4, 45},
  {5, 45},
  {6, 45},
  {3, 46},
  {5, 46}
};

void draw_lungs() {
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
  };

struct ball {
  int id = 0;

  int startx = 0;
  int starty = 0;

  int x = 0;
  int y = 0;

  int dx = 0; // in {-1, 0, 1}
  int dy = 0; // in {-1, 0, 1}

  void draw(void) {
    matrix.drawPixel(this->x, this->y, CRIMSON);
  }

  void reset(void) {
   matrix.drawPixel(this->x, this->y, OFF);

   this->x = this->startx;
   this->y = this->starty;

   this->dx = 1;
   this->dy = -1;

   this->draw();
  }

  bool move(void) {
     if (this->dx == 0) {
       debug("WHAT THE FUCK", this);
     }

     // set its current position to OFF
     matrix.drawPixel(this->x, this->y, OFF);

     // randomness
     if (random(0, 1000) < 2) {
       this->dy *= -1;
     }

     if (random(0, 1000) < 16) {
      this->dx *= -1;
     }

     // update its position
     this->x += dx;
     this->y += dy;

     int lungx;
     int lungy;

     // if we're at any of the lung blocks, adjust
     for (int i = 0; i < LUNG_BLOCKS; i++) {
       lungx = lungs[i][0];
       lungy = lungs[i][1];

       if (this->x == lungx && this->y == lungy && lungs[i][2] == 0) {
         debug("WE HIT LUNG", this);

         lung_counter--;

         if (lung_counter == STOP) {
           debug("ALL LUNGS", this);

           initial();
           triggered = false;

           matrix.fillScreen(0);
           matrix.show();

           draw_lungs();
           return false;
         }

         // mark that this lung block has been hit
         lungs[i][2] = 1;

         // flips the ball diagonally, shouldn't actually do anythin noticeable
         this->dx *= -1;
         this->dy *= -1;

         matrix.drawPixel(this->x, this->y, OFF);

         // reset the ball to the "beginning"
         this->reset();

         return true;
       }
     }

     // if we're at the edges of the grid, adjust our velocities
     if (this->x == 0 || this->x == GRID_COLS - 1) {
       debug("X FLIP", this);

       this->dx *= -1;
     }

     if (this->y == 0 || this->y == GRID_ROWS - 1) {
      debug("Y FLIP", this);
      this->dy *= -1;
     }

     this->x = max(min(this->x, GRID_COLS), 0);
     this->y = max(min(this->y, GRID_ROWS), 0);

     this->draw();

     return true;
  };


  ball(int id, int init_x, int init_y) {
    this->id = id;
    this->startx = init_x;
    this->starty = init_y;
    this->reset();
  }

  ball(int init_x, int init_y) {
    this->startx = init_x;
    this->starty = init_y;
    this->reset();
  }
};

ball* balls[NUM_BALLS];

void setup(void)
{
  Serial.begin(9600);

  pinMode(led, OUTPUT);

  for (int i = 0; i < 2; i++) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }

  delay(500);

  matrix.begin();
  matrix.setBrightness(15);
  matrix.fillScreen(0);
  matrix.show();
  delay(500);

  initial();

  for (int i = 0; i < NUM_BALLS; i++) {
    balls[i] = new ball(i, START_POSX, START_POSY);
  }

  triggered = false;
  Serial.println("INIT COMPLETE");
}


void draw_car() {
  // from up to down, drawing rows for the light blue part of car
  matrix.drawLine(3, 42, 5, 42, BLUE);
  matrix.drawLine(4, 43, 5, 43, BLUE);
  matrix.drawLine(2, 44, 6, 44, BLUE);
  matrix.drawLine(2, 45, 6, 45, BLUE);

  // individual window, two wheels
  matrix.drawPixel(3, 46, WHEELS);
  matrix.drawPixel(5, 46, WHEELS);
  matrix.drawPixel(3, 43, GREY);
}

int cnt = 0;
int reading;

void loop(void)
{
  for (int i = 0; i < 4; i++) {
    reading = analogRead(SENSOR_PIN);
    Serial.print("READING |> ");
    Serial.println(reading);
  }

  if (reading > 150) {
    triggered = true;
    matrix.show();
  }

  if (triggered) {
    if (cnt % 2) {
      draw_car();
    }

    for (int i = 0; i < NUM_BALLS; i++) {
      if (!balls[i]->move()) {
        break;
      }
    }

    if (triggered) {
      matrix.show();
    }
    delay(100);

    cnt = (cnt + 1) % 10000;
  }
}

// HELPER FUNCTIONS
void debug(const char* s, ball* b) {
  Serial.print("DEBUG (");
  Serial.print(b->id);
  Serial.print(") |> ");
  Serial.print(s);
  Serial.print(": ");
  Serial.print(b->x);
  Serial.print(", ");
  Serial.print(b->y);
  Serial.print(": ");
  Serial.print(triggered);
  Serial.println();
}

void initial(void) {
  lung_counter = LUNG_BLOCKS;

  draw_lungs();

  draw_car();

  // reset the ball to its starting position
  for (int i = 0; i < NUM_BALLS; i++) {
    balls[i]->reset();

    // resets all lungs to having not been destroyed
    for (int j = 0; j < LUNG_BLOCKS; j++) {
      lungs[j][2] = 0;
    }
  }
}
