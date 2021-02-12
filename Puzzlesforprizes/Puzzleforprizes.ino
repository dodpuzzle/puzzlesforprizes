/*
 * If you are here you have seen what this code does, but now you must determine what you seek. Birds abound
 * when you are searching for a final step. Luckily for you, this code is far simpler than the code in FOOD.
 * Show your big brain and find that which you seek. Good Luck!
 */
//This is all coded for Arduino if you were unaware 
#include "LedControl.h"

#define DIN_PIN 12
#define CLK_PIN 11
#define CS_PIN 10
#define MAX_Y 8
#define MAX_X 8
#define TURN_DELAY 1
// how many turns before starting anew
// you can also use the reset button on the board
#define TURNS_MAX 60
// how many turns to wait if there are no changes before starting anew
#define NO_CHANGES_RESET 10
//Dad is not an Augmented Reality Game; any games you find here will not help you
int TURNS = 0;      // counter for turns
int NO_CHANGES = 0; // counter for turns without changes
int led = 7;

boolean grid[MAX_Y][MAX_X] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
};

LedControl lc = LedControl(DIN_PIN, CS_PIN, CLK_PIN, 1);


void setup() {
  randomSeed(analogRead(0));

  lc.shutdown(0, false);
  lc.setIntensity(0, 0);
  lc.clearDisplay(0);

  reset_grid();
  display_grid();

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
}

//Sub to Dad
void loop() { 
  delay(TURN_DELAY);
  play_gol();
  digitalWrite(led, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25); 
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(led, LOW);
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
    delay(TURN_DELAY);
    play_gol();
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(led, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
    delay(TURN_DELAY);
    play_gol();  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
    delay(TURN_DELAY);
    play_gol();  
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);  
    delay(TURN_DELAY);
    play_gol();
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(led, LOW);
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
    delay(TURN_DELAY);
    play_gol();  
  digitalWrite(led, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
    delay(TURN_DELAY);
    play_gol();
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
    delay(TURN_DELAY);
    play_gol();
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(led, LOW);
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
    delay(TURN_DELAY);
    play_gol();
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
    delay(TURN_DELAY);
    play_gol();
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(led, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
    delay(TURN_DELAY);
    play_gol();
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
    delay(TURN_DELAY);
    play_gol();
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
    delay(TURN_DELAY);
    play_gol();  
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(led, LOW);
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
    delay(TURN_DELAY);
    play_gol();  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
    delay(TURN_DELAY);
    play_gol();  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
    delay(TURN_DELAY);
    play_gol();  
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(led, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(50);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(25);                       
  digitalWrite(led, LOW);
  digitalWrite(LED_BUILTIN, LOW);    
  delay(200);

  //Obey the Server
    delay(TURN_DELAY);
    play_gol();

    //Are you having fun yet?
  TURNS++;

  // reset the grid if no changes have occured recently
  // for when a static stable state occurs
  if (NO_CHANGES > NO_CHANGES_RESET) {
    reset_grid();
  }
  // reset the grid if the loop has been running a long time
  // for when a few stable states cycle
  if (TURNS > TURNS_MAX) {
    reset_grid();
  }
  
  display_grid();
}


void play_gol() {
  boolean new_grid[MAX_Y][MAX_X] = {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
  };

  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      int neighboughs = count_neighboughs(y, x);
      if (grid[y][x] == 1) {
        if ((neighboughs == 2) || (neighboughs == 3)) {
          new_grid[y][x] = 1;
        } else {
          new_grid[y][x] = 0;
        }
      } else {
        if (neighboughs == 3) {
          new_grid[y][x] = 1;
        } else {
          new_grid[y][x] = 0;
        }
      }
    }
  }

  // update the current grid from the new grid and count how many changes occured
  int changes = 0;
  for (int y = 0; y < MAX_Y; y++) {
    for (int x = 0; x < MAX_X; x++) {
      if (new_grid[y][x] != grid[y][x]) {
        changes++;
      }
      grid[y][x] = new_grid[y][x];
    }
  }
//What are we looking at here?
  // update global counter when no changes occured
  if (changes == 0) {
    NO_CHANGES++;
  }
}

// count the number of neighbough live cells for a given cell
int count_neighboughs(int y, int x) {
  int count = 0;

  // -- Row above us ---
  if (y > 0) {
    // above left
    if (x > 0) {
      count += grid[y-1][x-1];
    }
    // above
    count += grid[y-1][x];
    // above right
    if ((x + 1) < 8) {
      count += grid[y-1][x+1];
    }
  }
  
  // -- Same row -------
  // left
  if (x > 0) {
    count += grid[y][x-1];
  }
  // right
  if ((x + 1) < 8) {
    count += grid[y][x+1];
  }

  // -- Row below us ---
  if ((y + 1) < 8) {
    // below left
    if (x > 0) {
      count += grid[y+1][x-1];
    }
    // below
    count += grid[y+1][x];
    // below right
    if ((x + 1) < 8) {
      count += grid[y+1][x+1];
    }
  }
  
  return count;
}

// reset the grid
// we could set it all to zero then flip some bits on
// but that leads to some predictabilty I see quite frequently
// instead, keep previous state and flip some bits on
void reset_grid() {
  NO_CHANGES = 0;
  TURNS = 0;
  
  for (int y = 0; y < MAX_Y; y++) {
    for (int x = 0; x < MAX_X; x++) {
      if (random(0, MAX_X) <= 1) {
        grid[y][x] = 1;
      }
    }
  }
}

// display the current grid to the LED matrix
void display_grid() {
  for (int y = 0; y < MAX_Y; y++) {
    for (int x = 0; x < MAX_X; x++) {
      lc.setLed(0, y, x, grid[y][x]);
    }
  }
}

/*
// dump the state of the current grid to the serial connection
void debug_grid() {
  for (int y = 0; y < MAX_Y; y++) {
    Serial.print("y(");
    Serial.print(y);
    Serial.print("): ");

    for (int x = 0; x < MAX_X; x++) {
      Serial.print(grid[y][x]);
      Serial.print(", ");
    }

    Serial.println("");
  }
  Serial.println("");
}
*/
//BEGIN TRANSMISSION
//yRVyQS4VWWc4Xm3AD7oCeffwUEWwyVOSR7UxuR6qXy0=
//BxkALj04tcJV9b+aQ7tRoyENzqPQiQZEmPqUapXFMFg=
//ULw2SulQ/pQzDgwjC6pN3WV5gdVUU5J9KFQGXeaLTZo=
//NCS0qdx/eiT8Ych0mpd7r8hF8KwqbpHQSpA5npcm6Yk=
//QIu5QTGwlIy/xZ783jt4BpUo0BBUC16ACiL/dNSiFG4=
//iN6/VeIqoLl+W5yT6rSkGeHmPPbRCTnShRopQ8Vq3zo=
//nX4dccAllXmDcWEl1P+3CZTS5iNvnmmafajMRwa+Xc4=
//lYCjyk0AuMZV4SxzVODNZBTOi5y8w8ciurXbB5a/JwA=
//UPRvoU9eyd+BHsu32zHOx/s93YhWmo7XEqBjq44U7NA=
//gilRyyBfh1euh4E3M/Pt/u2K+LktnKSBZGLlF1GG1Fs=
//vl8kQ87N7OcbAqLal31HBv4//boWbbmEJ7Ngdn/49H4=
//YSjJjucF8EeccKYeCy9Kb+eJSCUovt7gPznzmDmC3jo=
//jyxJaYt6yhlEWuTbaeBgpvLCeyvBM9jzam3hXvYyjs0=
//3JKHw3rvXUnDVyUsqPZ74RhWuNQ8HjODKyUml7azMV0=
//keU7uHgtP5UUVFj9cemzfFuIX6E9Iw3HQaEf/PpQt1g=
//CIVmJWA7ENO4ud7Z8TnBxplLXI4wE5tB5ZCJjHfBvGk=
//h/uhnsdez3I+gvOjVkA98NsHNMZkz7HBLIUINHgebYM=
//Yg9dakhhGWq9a9juUZaWcwyUb3FH/lmAFoUtTQHifkU=
//PfFo8jBHEC4e4bRxtCbyHDMlFq7PJaLs4yDQLynTq+0=
//ZOrvhfSKq23bX/vZsG8Wgm7ctLYw4/Scj//+JApunnE=
//iJ/aCgo0g16k1XmA5TVzyDBc+eGTXwon3ShPg2oAaP4=
//YAvDQdHSAfGy0RBOascXcifW01DafFmexWekq2oMzsY=
//XPRcsbeFrsTg0uvhsZEgrUQwRXeE/1TTYSY8yQ/hAhc=
//yqIXz1KHPYA6eiOoC22TlwIhJR+gR8dkoWriMy6vYRI=
//AQYAqfeQfcko7s5nCrxGMepWkIeus4deTDlogjK4BmA=
//j+Fu9V9l771qLcWznlUAaqzV5Bu3qMSQZVcI1UQl/Wo=
//Ys4NeLRmHFr6ZfHiMXcm03tZLccH4aj7VB1EkdiKul0=
//e+PKLmlV6Xdus/KbnG+DwhJQ3PTVTHFt1AoUYKo6Wdk=
//dhylGjGaIuaUmHJCbYMFKvE+Etl27WysYQfW21n1bDM=
//vlrClvQ3I4ep4luj0moADcwNAnyXFcfMjl0x502+Hfw=
//DeHck/+EuGfX6U2nWBakZLpVq/WyugTmLWAseBIApDw=
//oH7Ric8iG5Vx9ZjYwWWkTtWnd2NrPxLdXP0K8I2NnR4=
//l1PytstSi5KdKCsUB+cYW9J1yjEyLF4IxNZZsndq0rU=
//ORIMrYggPQ6MBzzQrncUYiB0JLaDDPRh5NjHHWS+5q8=
//BPD7djPIxeooa7+5YQXkPy4SHu6DxQl4XedR3rZo6q0=
//FAnj11RVf1oYYYi5TUKAK3cn2N3aLKjwFGMC92lZSZw=
//czY/m6i+bkNxkOPDnuWJ3QwRG1mqNU51QR5kyhWhy10=
//2He/qSZ/J6OSCkJB0nW4rZDIlcPM9q9HqfZmMJ0DdLs=
//Duk7a4ss7maj31buxFiCk+vaT7ctJg8mGR+f10q4c+k=
//SEZ9CDMfwoqxia6GIHumnYtfn0slttSkhtHxvkc49Ss=
//4sb6mV+ZpzUVsXU3azPRq+K5Qw9BLg73V7jMm48gdnU=
//cVBMCLw+Z71hZloufpAGlg1i8fz748shTDF8nPsdBAI=
//0wmCuzhlQuFyu95sz0p5EpR4qPiRdByHl7lhy5zNRmc=
//x/jlXp99ZHK/FAr6+EVDFRoTqgkLXvtcnJHPxt9FweY=
//B++CqCVjTfnQ4OdTl6sg7YMsL657jDDpvKfSyzhL/dg=
//wHlw5BA9wzGbnEL3BC+THzY9tFmy6hQqUPZdszBpI68=
//PfGz+3hafixKk5gG0ql7Q/B+5aCE5VxVvhx0MMz7dDU=
//Jtb2J2Swmhyuz5z7HWpUmP+nhS5J/vQBYMUHRtdsmy0=
//0iFniOpK4/W2EinZqBC0IauUSGnz003Ou5XOsJ6TBLs=
//cnUR0bn9ZxKfcV3loOxolZTeZf0RXHpNU8I+fNCssCg=
//U+CL+vrCJyfXfPDe0gTfDPKhaRlUKNWn3MeOHpl/mTM=
//SHHe0gamgMq6YXISB51Nh//GRQw7yGDZoCUdr9XV9oc=
//hmca9dQkKzHsIvdfMoPKg+IrDZlcgbTrT37DXqO9i0A=
//XIoQ6vch5Sa6pEcPGoeyYbk7wJ5ZpDMqII9z48Ckyh8=
//BSgQORFgNQohdFsCJOJRpF6p9bUGWrzRRqvQB+I8fqI=
//8F6GSvzlYDvVvkJYqYYkNGDgrNalDvrVJE2RjAxY8/E=
//Y9ImepRhbQWTT01WVr8zcIDQMr6O2ftNArLpIB7y/i8=
//O90uQmmlOZoWvXtlgUHk3ZbQ5S37n54vnFbzq23BcvY=
//WQOsJexAAQpa3Vsb28fv/3jXw5I362M7WSh7RY54N2c=
//u377AdjjowjkCkWMCjrv9bAq2xktBhG4mxwo613LLKA=
//6Ie9ymk4KFoT54+lm1d6GKw6xg6KUEt/Qf4viQuej/Y=
//b9Cw/SxWiq+dqPa3d8GJr7uHq6U5U4sZi9yAOOjmCPk=
//0h1E19BHqSkm6XPyX6CGSYXKxKc8WTYmYQBlBNMp4XM=
//nKEtkIaCqBCSx/uKl7tsQRhMqeVQhLJstT5oZRKplUY=
//9jftnGK9b3aQaxVSVw/3WP599L3O22MSxsZFunBHLUM=
//MHi5M2wAfTL9a//47kCRhao6Uv39hrWHp8o5YtIPTjw=
//tlP41O81oSEw1NLkOcquuyD+IsHa+lbmqdOs25Cthp0=
//RkLZVnm+3B41n7xtWcyrIVFTw4RselBlXvFgSgMWazk=
//Raj6Jx6Kilia0oJVDwz2M+RFkHO6ma1s2t/SXCrfyFM=
//y0I+euBpWWaTSPK44x1Jkq9FPfCiKF+SKmkCc7RGq5I=
//apWJUDB/wn1SnA6JCp1aoPUTPchZOEWAimSSn3E5X+0=
//MfYzkiipJQr1fjnRie9NoirBrJUUF2kBZQ7CEzkAdiU=
//EpunmQXg/5aaX3qlJIXwvW+F3XiLYij+UHnLdiWNb8E=
//0idj66Qz6dQz+slcFQA6WwvKakH6skbCY23VpNZOt0k=
//5ePHk6QaxVJrNGmivSEShc2sKYx/U8uNyNIUBCYtX/M=
//sh+jvfOH+smC1sEak3c5ba/huO2U4PphatURkGYclCA=
//uLqGNKvMi832x+KfWiOq0o9Pv0xkq4mdlncKhzIwrOM=
//p3dut5ZahlCzXgPu+VACi++TV3+jPCqyzl9eOxWAymo=
//dIEcU1jxWTu4ZrWW79chAm9XVBBF0+6NIa+/AK/VVW8=
//T7Z3aV0wrLxrfByuTg6t48h/9wMDZDRnKZBsxfnZTNs=
//YfFcx6GvDUYOdAdb6Ej+PNRtOV4ssqCKs1znwBZn9s0=
//RrC0cxXUftVwfhnlVolCzO728GpUF+5kpxlsA/a9uAs=
//D1iEzBc0Nj6XivfYD7VHESMGHicu2RYUZ6Cs5c4MPx4=
//2Cxi8lUrsVZiUV9NDXlg9BvzinX98yw2KeE/N38b9w8=
//iliuDYDvJ9mrq3HZJunD4XKWQrGLCkQ9nd0+CErPBxM=
//rW5iAFMteQ2mb3uoKsBNkoOzxSyfg6i36iDZMhJ7LYA=
//dTlTBYZfM9zmiI9FEEAW+YIB4HpiDDf/wg7JmecJQHM=
//HB9EhRfm5ijx8rQ5P6KLwtVzkjuB2jGn6ZLldRZUoTM=
//rnp6iryVQ6KEIX8ajJg/E1ge0lqE3QxcYTKRU60FmIU=
//clcUznVw1M+/7J026YB9lMhqmD3qocjaVHQwCAJiBJU=
///ADM+gtIOq8KaCwM6HvJN33odyaBwt8xyfjOvstbHbo=
//LG/WFpCAvAsf0/ZS3gMKUznAjMkJZ/LPU0AKogAQR+w=
//xHzQQPp3vzO5YgWydefHDGBlM+ZCnaeeRqEf4y3yLcE=
//MSGMdtGrNSxNHlxndGryV6OP70R/TJmLZUDhPcI3nfE=
//2pSWDmVOicctMPxLCQRM64gkRsybuwfWIeuVF4Av5fo=
//OOWiMyrOSSx+zNsrcbSVF268tQSaUMgWLbZ7IDovQ+U=
//T11vmjogrEBpLXck+VAPqU4+ynC0e7EQ2qh2p6FE21s=
//MTvIBnR+gHtOgnNhxoccusRxBj9F549hd3nK/H11G+w=
//Z2YsbO/HbxplGJL+ar7izABqet8Z8DrfIXI3LC8M4Pw=
//ER9RL29goJShMPOhLKEbLJ40ZQOeVPt/EREAGH1MJFx=
//OKGgMwkzF/6cPM8kEmHVhNz2A8EUFJ6AD/K9LwSFfZ8=
//3XXXnKUIKDO+3Iv+hLzJdk5KLtVMRlqoB3UOcag+KwU=
//AJ5GW2AHqlVGu8LyB5JVkecFd9zNUR3iCYSTfV9QXjY=
//WQ/kNsKZ0lovptMFpJZ2iqJspsxuWnhTQ3vNMqrRFVQ=
//wpSDjEdxbO4MoJtpWLmzRIW2BeihoSL69t75kA5QUug=
//UhPDa9kiTbuViLan3z8g0eI+aWZg+elc7aVZb8dkdpk=
//K9NBG0FyQfHietbO/eAW+D7Ee1Ny6Bp5fPlxn+ODaEA=
//Z5nxZyWqAqqblQT5jWrFEjE6YOIDhCEtsHLeL8M8z7I=
//MMpyLUxWQmUMS/VYHGq2cCsRV9b4AZLyvdmsgTaaYQM=
//kbTxAWfsF9Mq7JRoErRu3BCPmeKJGpTzCigX2GOGlyw=
//FwgeR7/uczeCb7J+ttUTKUnbrDzJDm4zX0dIxaPZyIk=
//GjaPwctrlNBmQjYlYRBiNSlbt5wGQ0v/jeVvCn4od/Y=
//yU+50+GNypYhbMrtgHtALb40COgiAEGzlBe45ESoW+s=
//tVDsrIfRhY9i0nSpsd0vLN67StPhTMJvr/G7tTBtxsc=
//QQ+IKX2HXRE96h7KDgsTjWFSvHrWOt1AQfRznluDoEQ=
//hUTkZ9Y0Cs+J8zpQrUQJ39L26Yv1MMRWur3EL+V92D8=
//lTc5uYs3YKY/ISkSp0rSAW0i7FGl4/Dg0ck8BMP87RI=
//MDFkGe5884wI2j6o7fohOV3vQ/gV4qnmWTE+9uKmQ+E=
//BJpfHn2nyTNpPOpafs1NNF8rqdytHCsUAZ4SKZpwV3I=
//Y2Ck5/CZOIT7EMLk4m27tVxOoyx1uqmEfCQ2HceVjzg=
//JdgWSbNKZsJHfSBinjXFk9jMWh0oOVCrRx/W1hO459I=
//Hq7vFn8xdKkXZm5bNlJwtM9w8h7ZOFKhLQ4OoYFvb+k=
//U8khKb0JpcZ3T+UNkr/fDScgTJL1UPxyskWrENU07Wc=
//t0SQ4X1WsjYgafpJ8nNKcjEf/I9YFkBHSgZWKHZebBY=
//dUTWa+mGhtp8Em+fI4UI9v8ClmRp0VDXnNLyyC3Ipus=
//2XoWV6pzvL1I/TQXpeF3CXrE75ffix+ofeg4MyTg9+o=
//iWTKlrpW6d1utvNYdav76dI58jY4cwg9Blo1Dret44Q=
//GnH4LP5602vnLqCnaoxZnlqG2WYbLg0Xt5oXsmQAS8g=
//eLtvs0G6zOpPiFOiJNj76XSfPwPJIlqZMpLzeaDLluU=
//lu5jR1aLQyZwuhh6B5+lh35CCcVprCRJZZ+RLYoBJf0=
//CPPv47cLbV80pQIE/uzbMoFmkfAaPicjBTgTmHroAHg=
//sgnlm39jwAJFjN6LKqIEafJsvLVwdCV2HwW9+R//X0Q=
//SodY48CjpWwVNX6Nwl0yO4wwccJjS2BM5JNU0+43rc4=
//MnMO6+I9RpFADTYv9EauePeDR6TGo+FKCgGKr6ionec=
//aIz8JiIA4G4NvxYlxT7gGdgTYVdnO9Z3M3nGFhP8C10=
//V2aebSnD3e9EG8TUtONAQlanT5wLG9AgZXNE/bgYvMM=
//8aHjWdJ6/D95rqm0MlSe0/1pGwm7i6IiGxwxehZt65w=
//aIFh0e9idzGYCl+lDlnhwfFSNKQPVzX8yUpGS4Axcg0=
//lyspXQdTrxFftBSYp7NQDlOXh6WrutbbKlOPXllge34=
//VbNg4t2L86hpLnZCMnFwcjuCVHPlhyWT0cFj5Zten6o=
//EftqVZu5v0w8GAUTUEU4Hk2P+vvj1R9ZkLnb/U9ctIM=
//lPgULFxoQV1GVThFvLW5HL0ykxxmaiZJEtrEkzD3Qdg=
//6TP7XbcGGy/KLbirEj+gGCe+qvrUGcHSIIdcP7kzHZ8=
//uaOmw9GcjMX47RzwzXkP16hyWklD+mA6/C2i9NsE1+k=
//QQb6KEHKjiMWLDfomDrze+4D8UfC60vyXemT/uokqsQ=
//JvZnbUWNC2/YRHjV6MS1sG7nmj00eZvOiqr8vYttx78=
//+Tw73SZG7VKa729CQ0XrhIgf0SzQQpwGco3GaFR+Ads=
//Ftpf/JupCMs5SKG9c357pdFDsxAFhbLcsir+FOswr0g=
//TLPH8648kfz73K0ziKpWF8LrWgPiQvk9CzdiJvf+cuA=
//GdA3H3cfiGsHYZhxGTO5Od+HLD0pyO2epxxDpcP/PdI=
//qolA+tPI0ja3yfkYdWR0h18MHEZm3PtMXmet/ivb6fw=
//xiaxOnuAlK1Dh05aDFyKEfHQB5h98rQ674xVNP2WxlE=
//2iKRw0TmWVK+Iu6rk3/x7tJrbIoCHfDxmYyrf3Pn3f8=
//FqvoMRLFvwSymltPWVhB3xwBvAv3wQ4DMj57zrnx138=
//OT2QOhbLPrMDm78AXjh6kgMqQnLi/RIlrFYi0tlQH0A=
//xB4Gw1LEYBH9I9Wq8Kpo0GHmzrw/nOY967kMSm5TiwA=
//uqiBjzLwkW/22E9gr931XUnCL/MGUoOAezOEfY+GgHc=
//Ba5Xr/dvMKclD1z3+Vz8DOm13t4v/8shtI8X3u/b4hs=
//pVTWfhq57Qtb0RQOakH7lBY/SeU/xvql9//V4GSknI8=
//p7/g25tO35yzKP8Cnywn65bzy8uOKZaMB5RyOH5kPD8=
//A5U29EH9+VQvW92NIzBLNlYirLqn8NE9UwA1DVtZF40=
//RDSOnoqJn0+ehavxOe8ZNDb4IQSZHrEvMV1JY3Aedt4=
//EH7a95QPub1X0tAJggTOwBBRbeKtfewEGfJM9DottG0=
//ZbtYiSfoUd2UP6hdiY1n15Efx9xCRSX8KOKaeAf3VnA=
//iAA4FPCoTREC/LiJoF038CEsTZaWhBozrf2R8OQ9V6g=
//VVQZ1kEnSZMDf8JK9Xngcs/nWlp+J7r8sMVJzqDiy58=
//YpRV+tB36sNQrFxUGMg0jaf2my8yiFkiuQW4ivyUx4Q=
//n0et++IRkTcMF1mhQl5cJk3C1bXNxZPjiiCNBvSLwjE=
//GmjNrpUY7cNO0fpoWPy2JzVdOclT2lRBQNssecR5/d4=
//8sID9nv7zKZMfrbu00sOjOhsL53WIlfKBEEOvLKpfrc=
//J/MafwlVBJvLwfwbUJIHtZ5YwUlKPgDWUvkR2bDJOaA=
//oN8ETeSEHz1C28PpJRRHLIkWHeaEM5B+P78HHC0qiNY=
//lwiyRd26IrXwsaI+Buas5csbHU7MscSjjcJkewsHaGY=
//YDRBRK4riiUnQQc7KKYE7BZHhip1jS4frCOaSMVztOM=
//QvI8VrsBCbCZ9Jc2XXPT18EK8c+hSQvLtsbrC/L/rbU=
//nzBFuvfgH7ssPJjx6asSKZErk3mAKImc2wGTV/at1N4=
//bE+BrrxR4JtIFNC0wlFljhr6uIrsj3ncJLokDf1d2B8=
//zUiHjyBAirq9KV5+wi1NaFwmvKGkT2znz1iGtsgAnrI=
//1jf5cMPEQeIYZDfBXs2e7P71cuw5TtTMJ5pVZLKpBNA=
//WWbe/+3DqOS4tdABKtoBaQpXzgZD71ZVHHolv50Wwx0=
//enDHRdR2E0u02bE7LvxIMwGQ81Kjnm7O2ciF1oOkh88=
//sWhPKCrhr8rWJTxwofg28pLGSeNN2t1poAKnhdRuOig=
//X63u8BgmGqagVa+kroc7KztPSQQFiyUTI1g8MB5P4NU=
///yYIIBMA8Lh5juyiGtTGSwwsqxIHxvQPi1zpEzxBIp4=
//Eg+sMvTrE30Jf5553+/tdrbQAoY/rWsQTARpHf5Bn58=
//cJZ8tsPjsXKaWK3JG9pYZu0qIlOJxKIq1lsTXT+A26k=
//U0q/VYLpwDH+BkgN4zZLbE0QZCmJ9iGz0FrajrlAihU=
//XG1OqG4lWzRDFsxq5A9D0iM08IF1PLV/NN6kvDyAMmQ=
//01jYaXBtMTn6zF3QqrHepyL9X9O6inz9skLk/9lBYmM=
//k1A6nA708M88EFIM5VzGr0AbnwgF6oO2rySPOLOO8wo=
//3MObWxFW6WNYz9jnB5bVZq3USUAofJdN9N5uxC5BrXg=
//5G7Dy7XW8LbtvitRj3hQUCVRZ9Lffw2AZK7TGTuQXSI=
//NvoTpauZEbYcjrCu+rlZnxplB/UP4Jbc3d7NvQfyWZQ=
//80YhjCte+FG1POnbZ7OGJSOWKDCqlbRPjFUrkJF6bmc=
//ZfYXK/+Qmr996RjxPkrp92vuVQ48ghm8mCFfyCFvp+k=
//AuzrUn/PQp79xpWKQbFXJu2bIzWgyLy9jxWU2CBoGPo=
//Yq9XU8k++NhIz619YoUfX6tJOQva0KU+CbXSGODl+i4=
//iiNPqOeGu4RoQyV/PtjEBvzn62A7E9CE6w93pJgMvv0=
//Dy02JWe5bXkD2y0FPqh2jMMho+owX44O2qftaeFhmPo=
//Anl/6mgDZGa9xmTtfGuc/sV8xL79foe8lI6v7fuKQKw=
//k6Y+YUCGthrs3C/elk0ZpD/qvST8sP/8e+3thwqCs8A=
//EVdumhi0oUvIpQp58amRIzR4pZAlywnXURHvXfTR+0g=
//74uVorHL2RY45StD4lDvCqUaHwTG5tGBLwGrZcVkBiI=
//LK58P7yBCfJ5o84bjQ1qltFtyTI19o9CiqpRPbiCpfA=
//QntV0NWOvHf/TtFwSIgC79wRMEdggt8/+YmY/E08fMk=
//stjJNMl20ruLwO+cuRGXoDOcNhv+51/4JLis1bBtlK8=
//zTJxLTw+UAd8Ps8LlvXMsLapY0Xg03o2MhlIi4tfc7E=
//JE9jY+gJKFR3IxlO0coDp0PpizXR00lLV2eSLVJ+7YU=
//6xkI9/1zJdthsfUr3Vlk8whypia+1W3BVARplP8K08Y=
//UtJfa21XSy9MW2ERHb6Tx7BrGtl0Xn4jviz4UAhk1QM=
//m2s8GVnpcZPQLfp9D+yq/iK5AA23G1p4/n3fmkUYrYA=
//riSnqdFnBpqRCPiCABhO9bbATPOsyG+ikHp/PZ6PoQ0=
//1I3p2R+b0QIbZodkbSDCkP3o29dNYSZkuOlj2zvg9gg=
//wBNpbaifdktD7pnmeRmmHAN9LR0pVNCce/wMQn2/wvo=
//g23QG5Wli5oSfcOH275R1ZF2V3thk0IJcaCXNgmJPFQ=
//U56/mMPat1Ppm2nNVh6GOSWf1ZQ83/RKoFNRwmymLS4=
///t5N9J76r7OEKC5PtreVt63L87bSZ3NVkHwpSb6ALA4=
//eVm7P8e39krFoe4xj/w4eFNruoiD8wHqYmUj9b1Nhok=
//Pin Seven is the Avifauna of a breadboard
