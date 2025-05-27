#include <Adafruit_NeoPixel.h>

//PIN ASSIGNMENTS
const int neoPixelPin = 6;
const int buttonPins[3] = {2, 3, 4}; //PINS FOR THE BUTTONS FOR PLAYER 1, 2, 3
const int buzzerPin = 9;

//CONSTANT VARIABLES
const int numPlayers = 3; //TOTAL PLAYER COUNT
const int numLeds = 16; //NUMBER OF LEDS IN THE NEOPIXEL
const int maxLives = 3; //LIFE COUNT FOR EACH PLAYER

//NEOPIXEL
Adafruit_NeoPixel pixels(numLeds, neoPixelPin, NEO_GRBW + NEO_KHZ800);

uint32_t playerColors[3] = 
{
  pixels.Color(255, 0, 0),   //PLAYER 1 - RED
  pixels.Color(0, 255, 0),   //PLAYER 2 - GREEN
  pixels.Color(0, 0, 255)    //PLAYER 3 - BLUE
};

//PLAYER
int lives[numPlayers]; //TRACKS THE PLAYERS LIVES
bool isAlive[numPlayers]; //TRACKS IF THE PLAYER IS STILL IN THE GAME

void setup() 
{
  Serial.begin(9600); //START THE SERIAL MONITOR FOR DEBUGGING
  pixels.setBrightness(80); // BRIGHTNESS OF THE LED
  pixels.begin(); //START THE LED RING
  pixels.clear();
  pixels.show();

  for (int i = 0; i < numPlayers; i++) 
  {
    pinMode(buttonPins[i], INPUT_PULLUP); //BUTTON SETUP
  }

  pinMode(buzzerPin, OUTPUT);

  startGame();
}

void loop() {
  //MAIN GAME LOOP
  //CHECK IF THERE IS ONLY ONE PLAYER OR NONE ALIVE
  if (countActivePlayers() <= 1) 
  {
    announceWinner();
    waitForRestart();      //WAIT FOR THE BUTTON THE RESTART
    startGame();           //START GAME
    return;
  }

  int chosenPlayer = selectRandomAlivePlayer(); //PICK A RANDOM PLAYER
 
  Serial.print("Eye is watching Player ");
  Serial.println(chosenPlayer + 1);

  showPlayerColor(chosenPlayer); //DISPLAY THE PLAYER COLOUR
  delay(random(1000, 1500)); //RANDOM DELAY BEFORE ALLOWING INPUT

  unsigned long startMillis = millis();
  bool pressedInTime = false;

  //REACTION WINDOW
  while (millis() - startMillis < 2000) //2 SECOND REACTION WINDOW
  {
    for (int i = 0; i < numPlayers; i++) //LOOP UNTIL THERE ARE NO PLAYERS
    {
      if (isAlive[i] && digitalRead(buttonPins[i]) == LOW) 
      {
        if (i == chosenPlayer) //IF THE CHOSEN PLAYER PRESSES AN INPUT
        {
          pressedInTime = true;
        } else //CHECK IF A PLAYER PRESSES THE BUTTON OUTSIDE THEIR TURN
        {
          lives[i]--;
          Serial.print("Player ");
          Serial.print(i + 1);
          Serial.print(" pressed out of turn! Lives left: ");
          Serial.println(lives[i]);

          if (lives[i] <= 0) //CHECK IF THE PLAYER HAS ANYMORE LIVES LEFT
          { 
            isAlive[i] = false;
            Serial.print("Player ");
            Serial.print(i + 1);
            Serial.println(" eliminated!");
          }

          tone(9, 80, 300); //PENALITY TONE THE SPEAKER WILL OUTPUT
        }
      }
    }
  }

  //CLEAR LIGHTS AFTER THE REACTION WINDOW
  pixels.clear();
  pixels.show();

  //RESULTS OF EACH ROUND
  if (pressedInTime) //IF THE PLAYER PRESSED THE CORRECT BUTTON
  {
    Serial.print("Player ");
    Serial.print(chosenPlayer + 1);
    Serial.println(" survived.");
    tone(9, 160, 50); //TONE TO SIGNAL A NEW ROUND HAS STARTED/SUCCESS
  } else //PLAYER WILL LOSE A LIFE IF THEY MISS THE BUTTON
  {
    lives[chosenPlayer]--;
    Serial.print("Player ");
    Serial.print(chosenPlayer + 1);
    Serial.print(" missed! Lives left: ");
    Serial.println(lives[chosenPlayer]);

    if (lives[chosenPlayer] <= 0) //IF A PLAYERS LIFE HAS REACHED 0 THEN THEY ARE ELIMINATED
    {
      isAlive[chosenPlayer] = false;
      Serial.print("Player ");
      Serial.print(chosenPlayer + 1);
      Serial.println(" eliminated!");
    }

    tone(9, 80, 300); //UNSUCCESSFUL TONE
  }
}

//THIS WILL SHOW THE COLOUR OF THE SELECTED PLAYER
void showPlayerColor(int player) 
{
  pixels.clear();
  for (int i = 0; i < numLeds; i++) 
  {
    pixels.setPixelColor(i, playerColors[player]);
  }
  pixels.show();
}

//THIS WILL SELECT A RANDOM PLAYER AT RANDOM
int selectRandomAlivePlayer() 
{
  while (true)
  {
    int p = random(numPlayers);
    if (isAlive[p]) return p;
  }
}

//THIS WILL CHECK HOW MANY PLAYER ARE ALIVE
int countActivePlayers() 
{
  int count = 0;
  for (int i = 0; i < numPlayers; i++) 
  {
    if (isAlive[i]) count++;
  }
  return count;
}

//THIS WILL ANNOUNCE THE PLAYER AND WILL DISPLAY THAT PLAYER COLOUR ON THE RING
void announceWinner() 
{
  for (int i = 0; i < numPlayers; i++) 
  {
    if (isAlive[i]) 
    {
      Serial.print("Player ");
      Serial.print(i + 1);
      Serial.println(" wins!");
      flashWinnerColor(i);
      break;
    }
  }
}

//THIS WILL FLASH THE WINNER COLOUR 
void flashWinnerColor(int player) {
  for (int j = 0; j < 6; j++) {
    pixels.clear();
    pixels.show();
    delay(300);
    for (int i = 0; i < numLeds; i++) {
      pixels.setPixelColor(i, playerColors[player]);
    }
    pixels.show();
    delay(300);
  }
}

//WAIT FOR ANY PLAYER TO RESTART THE GAME BY PRESSING ANY OF THE BUTTONS
void waitForRestart() 
{
  Serial.println("Press any button to restart...");
  while (true) 
  {
    for (int i = 0; i < numPlayers; i++) 
    {
      if (digitalRead(buttonPins[i]) == LOW) 
      {
        Serial.println("Restarting...");
        delay(1000);
        return;
      }
    }
  }
}

//THIS WILL START/RESTART THE GAME
void startGame() 
{
  for (int i = 0; i < numPlayers; i++) 
  {
    lives[i] = maxLives;
    isAlive[i] = true;
  }

  pixels.clear();
  pixels.show();
  Serial.println("Game Start!");
}