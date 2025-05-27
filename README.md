# TANGIBLE-PROJECT
TANGIBLE DOCUMENTATION 

**NAME OF PROJECT: OUT OF SIGHT**

## **EXPERIMENTS**

### **DIGITAL OUTPUT**

When using digital outputs we can control the inputs being taken and precisly control the digital output in which LEDs were mainly used to show an output by using a HIGH(5V) AND LOW(0V) signal.

This is a simple built LED output circuit:

![Physical LED circuit](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/IMG_20250220_125427151.jpg)

Schematics:

![LED Schematics Diagram](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/LED_SCHEMATICS.jpg)

Here is some Blink code that will turn the LED on and off though this code won't loop

```
/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  }
}
```
[^1]

This is a link to the LED [BLINK VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/VID_20250220_125439799.mp4) that will continuosly loop

Another LED output program is a fade in which the LED will loop fading on and off:

```
/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

int led = 9;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

```
[^2]

This is a link to the LED [FADE VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/Fade%20Video.mp4)

The digital LED output is very basic but could probably used in a multidude of ways such as it could be used such as a health system turning off the LED when the player has taken damage or could potentially be used as a sensor turning on if there was any motion detected.

### **ANALOG INPUT**

Analog can have a range of different inputs unlike a digital outputs which are either a ON OR OFF. Analog on the other hand can read sensors such as the light dependent resistor.

The following examples will show a circuit using a light dependent resistor and one using a potentiometer:

Here is a physical circuit of a light dependent resistor:

![Physical Light Dependent Resisitor circuit](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/1000009678.jpg)

Schematics:

![LIGHT DEPENDENT RESISTOR SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/LIGHTDEPENDENTRESISTOR_SCHEMATICS.png)

This is a link to the [LIGHT DEPENDENT RESISITOR VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/LightDependentResistor%20Video.mp4)

This is a link to the results of the [LIGHT DEPENDENT RESISTOR SERIAL PLOTTER VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/SerialMonitorLightDependentResistor.mp4)

Here is a physical potentiometer circuit:

![Physical Potentiometer](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/Potentiometer%20Circuit.jpg)

Schematics:

![POTENTIOMETER SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/POTENTIOMETER_SCHEMATICS.png)

This is a link to the [POTENTIOMETER VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/Potentionmeter%20Video.mp4)

This is a link to the results of the [POTENTIOMETER SERIAL MONITOR OUTPUT VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/PotentiometerSerialMonitor.mp4)

[^3]

Here is the code used to read the serial monitor/plotter with a light dependent resistor and potentiometer:

```
/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/analog/AnalogInput/
*/

int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
}

```

Analog could be potentially used in our game as a sensor such as detecting the brightness or possibly used as an analog joystick for controlling the character or a robot.

### **SERVOS AND MOTION**

A servo motor is a closed-loop system that uses precise position of its shaft to a specific angle which is usually between 0° to 180°.
[^5]

This is a basic servo sweep physical circuit:

![SERVO SWEEP PHYSICAL](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/Servo.jpg)

Schematics:

![SERVO SWEEP SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/SERVO_SWEEP_SCHEMATICS.png)

This is a link to the [SERVO SWEEP VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/Serco%20Sweep.mp4)

This was the code used for the servo sweep program:
```
/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
```
[^4]

This demonstrates that the shaft of the servo cna turn a full 0° to 180° 

This is a basic servo knob circuit using a potentiometer:

![SERVO POTENTIOMETER PHYSICAL DIAGRAM](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/Servo%20and%20Potentiometer.jpg)

Schematics:

![SERVO POTENTIOMETER SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/SERVO_KNOB_SCHEMATICS.png)

There are also different analog inputs to control a servo using a potentinmeter and a light dependent resistor this demonstrates the servo moving by using a potentiometer.

This is a link to the [SERVO KNOB USING A POTENTIOMETER VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/Servo%20and%20Potentiometer%20Knob.mp4)

This was the code used for the servo knob program:
```
/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
```
[^6]

This demonstrates the use of the servo can be controlled to rotate it's arm to a specific angle.

A servo can be used in a number of ways to precisly move an object such as robotic arms and RC vechiles.

### **DIGITAL INTERFACING**

Digital interfaing is very simular to digital outputs which only have two states still being on and off normally used for displaying.

This is the basic schematics of the LED strip:

![DIGITAL INTERFACING SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/LEDSTRIP_SCHEMATICS.png)

This is the code used for the LED strip:
```
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 16

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);

void setup() {
  strip.begin();           
  strip.show();            
  strip.setBrightness(50); 
}
void loop() {
  strip.setPixelColor(16, 255, 0, 255, 0);
  strip.show();
    delay(50);
}
```
[^8]

This displaying a full colour on the strip.

This is a link to the [LED STRIP VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/digital%20interface.mp4)

How this could potentially be applied to the project in simiular ways to the digital output by something triggering it such as a button to turn on the LED.

## **GAME DESIGN IDEAS**

### GAME IDEA 1

The concept of this game idea is that the 2 players would have sensors covering all over their bodies such as shoulders, knees and arms and you would hit the other player with a soft weapon that would hit the other players sensors adding a point everytime a player hits one of the sensors with a winning condition after a time period. This idea was rejected due to the complexity of the build.

### GAME IDEA 2

Another  game idea would be a shooter in which the player would shoot light from a toy gun and it would shine onto sensors for the player to gain a point using. The idea was rejected due to the difficulity level and its simularities to arcade games that are like that.

### GAME IDEA 3

Another game concept idea was a battle ships idea in which the the player would have to chase an enemy around a board to try and catch the enemy.

### FINAL GAME IDEA 

The final game project idea is a 3 player game in which an open eye will open and close the players will lose their lives if they're not holding the button down whilst the eye is looking at the player, when a player has lost a life the figure will stay down and that player will be out for the rest of the game. There will be 3 rounds with the timer getting quicker each time with the winner of the game being the last player standing.

![Game Concept Sketch](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/Game%20Concept.png)
![Game Storyboard](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/STORYBOARD_FOR_OUTOFSIGHT.jpg)
Storyboard on roughly how the game will be played out

## **TESTING**

When it came to starting the project we started with making a button circuit as that will be the main way to play the game.

![Button circuit test](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/1000010239.jpg)

Schematics of the button:

![BUTTON SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/BUTTON_SCHEMATICS.png)

This is the code that was used for the button:
```
/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
```
[^9]
So bascially whenever a button is in a OPEN state it reads as LOW on the other hand when the button is in a CLOSED state its in a HIGH state with the 5V running through the circuit which will turn the light either ON or OFF.

After making the button a servo was added onto the circuit as in our design ideas we had little figure which would go underneath the board 'hiding' from the eye when the button was held down.

![BUTTON WITH SERVO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/servo%20with%20button.jpg)

Schematics of the button and servo:

![BUTON WITH SERVO SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/BUTTON_SEVO_SCHEMATICS.png)

This is a link to the [SERVO WITH BUTOTN VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/button%20and%20servo.mp4)

Here is some code that we used to get the servo to move with the button:
```
int button = 2;   //pin of the button
#include<Servo.h> //include the servo library
Servo servo;  //create a servo object
int pos = 0;  //initial position of the servo
void  setup() {
  // put your setup code here, to run once:
  servo.attach(3);  //pin  used by the servo
  pinMode(button, INPUT_PULLUP);  //define button as  input pullup
  /*
  INPUT_PULLUP send to arduino LOW signal, so, when you press  the button, you send a LOW signal to arduino
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button) ==  LOW) { //if Value read of the button ==LOW:
    pos++;  //increases the value  of the "pos" variable each time the push button of the left is pressed
    delay(5);  //5 milliseconds of delay
    servo.write(pos); //servo goes to variable pos
  }
  if (digitalRead(button) == HIGH) { //if Value read of the button ==HIGH
    pos--;  //decreases the value of the "pos" variable each time the push button  of the right is pressed
    delay(5); //5 milliseconds of delay
    servo.write(pos);  //servo goes to variable pos
  }
}
```
[^10]
This will basically move the sevo shaft side to side depending on the button state. Sadly this idea was scrapped due to time constraints.

Later we found a better more easier to use push button than before which were some arcade buttons.

![ARCADE BUTTONS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/arcade_button.jpg)

Schematic of the arcade button:

![ARCADE SCHEMATIC](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/ARCADE_SCHEMATIC.jpg)

After, finishing off the buttons for we moved onto adding a speaker into the game to let the player know when they have failed to press the button in time.

![SPEAKER](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/speaker.jpg)

Schematics for the speaker:

![SPEAKER SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/SPEAKER_SCHEMATIC.jpg)

This is a link to the [SPEAKER VIDEO](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/speaker%20video.mp4)

Here is some basic speaker code we to test out how a speaker works.
```
void setup() {

  int SpeakerPin = 9; //DEFINE SPEAKER PIN NUMBER
  pinMode(SpeakerPin, OUTPUT);
}
void loop()
{
  tone(SpeakerPin, 440, 1000); //(PIN NUMBER, FREQUENCY, TIME)
  delay(1000)
}
```
[^11]
This code will simply make a tone in a loop.

Now that we had two seperate circuits and decided to combine the both together.

![ARCADE BUTTON & SPEAKER](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/button%20and%20speaker.jpg)

Schematic of the arcade button and speaker:
![ARCADE BUTTON AND SPEAKER](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/ARCADE_SPEAKER_SCHEMATIC.jpg)

```
int buttonPin = 2;   // button input
int buzzerPin = 9;   // buzzer input

int buttonState = 0; // checks if the button is pressed

void setup() {
  pinMode(buttonPin, INPUT);    // set button as input
  pinMode(buzzerPin, OUTPUT);   // set buzzer as output
}

void loop() {
  buttonState = digitalRead(buttonPin);   // checks the button

  if (buttonState == HIGH) {
    digitalWrite(buzzerPin, HIGH);  // turn on buzzer
    delay(500);                     // wait half a second
    digitalWrite(buzzerPin, LOW);   // turn off buzzer
    delay(200);                     // stops it from repeating too fast
  }
}
```
This is some code that when a button state changes the buzzer will either turn on or off.

We then wanted to get started with adding a LED for the eye as building a robotic eye was way beyond our skill level. Though we did run into a bit of a problem when it came to the LED which was mainly code related due to the NeoIxel product name being spelt differently.

This is a link to the [NEOPIXEL RING NOT WORKING](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/not%20working%20LED_Ring.mp4)

The improved NeoPixel Ring now working:

![WORKING NEOPIXEL ADAFRUIT RING](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/WORKING%20LED.jpg)

Schematics for the NeoPixel LED Ring:

![NEOPIXEL LED RING SCHEMATIC](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/LED_RING%20SCHEMATIC.png)

Here is the working code for the LED Ring
```
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6 //OUTPUT PIN
#define LED_COUNT 16 //LED COUNT

Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);

void setup() {
  ring.begin();           
  ring.show();            
  ring.setBrightness(50); 
}
void loop() {
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, 0, 0, 255, 0); //SHOW ONE COLOUR WHICH IS BLUE
    ring.show();
    delay(50);
  }
}
```
This code will display a full colour on the LED ring.

Then we decided to combine the LED ring, speaker and the arcade buttons together to basically complete the circuit.

![BUTTONS AND LED](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/3%20buttons.jpg)

![FINISHED CIRCUIT](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/FINAL%20CIRCUIT.jpg)

Now that the circuit is basically complete we now mainly have to code the system with the basic gameplay loop being when the colour that the eye shows that player will press their button repeating that loop until there are no players left.

```
//CONSTANTS
const int buttonPin = 2; //BUTTON INPUT PIN
const int LEDPin = 13; //LED PIN
const int buzzerPin = 9; //BUZZER PIN

//VARIABLES
int buttonState = 0; //BUTTON STATE VARIABLE
int lifeCount = 3; //PLAYER LIVES
unsigned long randomTime; //RANDOM LED TIME

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(eyePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
```

We began with what constants and variables that we might need in the project

```
void loop() {
  randomTime = random(2000, 5000);  //RANDOM TIME BETWEEN 2 TO 5 SECONDS

  delay(randomTime); //RANDOM DELAY FOR THE LED TO TURN ON

  digitalWrite(LEDPin, HIGH); //TURN ON LED

  //CHECK IF THE BUTTON WAS PRESSED
  unsigned long startMillis = millis();
  while (millis() - startMillis < 2000) { //2 SECOND REACTION TIME
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      //CHECK IF THE PLAYER PRESSED THE BUTTON IN TIME
      digitalWrite(LEDPin, LOW); //LED OFF
      Serial.println("Player avoided being seen!");
      return;  //ROUND END NEW ROUND BEGIN
    }
  }
  //CHECK IF PLAYER PRESSED BUTTON IF NOT RUN THIS
  if (buttonState == LOW) {
    digitalWrite(LEDPin, LOW); //LED OFF
    lifeCount--; //LIFE GONE
    tone(buzzerPin, 1000, 500);  //SPEAKER FOR FEEDBACK
    Serial.println("Player lost a life!");
  }

  //CHECK IF PLAYER HAS LOST ALL OF THEIR LIVES IF SO END GAME
  if (lifeCount <= 0) {
    gameOver();
  }
}
```
We then began to write out the main piece of the program what this code basically does is it'll wait for a random amount of time for the LED to turn on it'll then check if you pressed it in the reaction window checking by outputting in the serial monitor. With the addition of a check to see whether the player has pressed the button or not and a check when a player has lost all of their lives to end the game.

Though at the moment we don't currently have a check for if another player presses their button outside of their turn or a way to restart the game yet with the addition of the LED ring.

```
#include <Adafruit_NeoPixel.h>
const int LEDPin = 6;

Adafruit_NeoPixel pixels(numLeds, neoPixelPin, NEO_GRBW + NEO_KHZ800);

uint32_t playerColors[3] = {
  pixels.Color(255, 0, 0),   //RED PLAYER 1
  pixels.Color(0, 255, 0),   //GREEN PLAYER 2
  pixels.Color(0, 0, 255)    //BLUE PLAYER 3
};
```
This is the basic set-up that the LED ring will be using displaying a different colour for each player.

Now that the LED has been setup we want to now dispay the player colour when a random player gets selected by the program

```
void showPlayerColor(int player) { //DISPLAY PLAYER RANDOM COLOUR
  pixels.clear();
  for (int i = 0; i < numLeds; i++) {
    pixels.setPixelColor(i, playerColors[player]); //SET TO CURRENT PLAYER COLOUR
  }
  pixels.show();
}
```

Now we need a proper winning and lossing state for the game

```
//CHECK THE CURRENT PLAYER COUNT
int countActivePlayers() {
  int count = 0;
  for (int i = 0; i < numPlayers; i++) {
    if (isAlive[i]) count++;
  }
  return count;
}

//ANNOUNCE THE WINNING PLAYER
void announceWinner() {
  for (int i = 0; i < numPlayers; i++) {
    if (isAlive[i]) {
      Serial.print("Player "); //DEBUG FOR THE SERIAL MONITOR TO CHECK THAT IT'S WORKING AS INTEDED
      Serial.print(i + 1);
      Serial.println(" wins!");
      flashWinnerColor(i);
      break;
    }
  }
}

//DISPLAY WINNER COLOUR
void flashWinnerColor(int player) {
  for (int j = 0; j < 6; j++) {
    pixels.clear();
    pixels.show();
    delay(300);
    for (int i = 0; i < numLeds; i++) {
      pixels.setPixelColor(i, playerColors[player]);
    }
    pixels.show();
  }
}
```

This is a lot of the main program done now all is really needed is to add some additional checks with the buttons being pressed and possibly a way to restart the game.

```
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
```
This is a more cleaned up version of the results from each round with the additon of checking if a different player pressed the button instead of the chosen player with the addition of a successful tone and now a way to restart the game.

[THIS IS A LINK TO A DEMONSTRATION OF THE GAME BEING CARRIED OUT](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/FINAL%20CIRCUIT.jpg)

## **TECHNICAL DOCUMENTATION**

**PICTURE**

![FINAL PROJECT](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/FINAL.jpg)

**SCHEMATICS**

![FINAL SCHEMATIC](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/FINAL_SCHEMATIC.jpg)

**CODE**

This is the final cleaned up code.

```
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
```
[^12] [^13] [^14] [^15] [^16] [^17] [^18]
## **MANUAL**

**HOW TO OPERATE THE GAME**

- How to operate the game 

- Press any button to start 

- Press the corresponding colour to the LED colour 

- Continue to press until the success buzzer goes off 

- Continue until the game ends 

- Press any button to restart 

- 3 players but can be player solo to see how long you can last

**RULES OF THE GAME**

- Each player has 3 lives 

- Press your button when the LED matches the colour

- If you fail to press your button in time you will lose a life

- Don't press your colour outside of your turn or you will lose a life

- Keep going until the last player remains 

- The LED will flash the colour of the winning player 

**HEALTH AND SAFETY**

- Don't push down on the buttons to hard 

- Don’t touch the LED or the wiring may come out

- Don't mess with the wires or move the box around too much

## **PLAYTESTING**

[THIS IS A LINK TO PART 1 OF THE PLAYTEST](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/PLAYTEST_1.mov)

[THIS IS A LINK TO PART 2 OF THE PLAYTEST](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/PLAYTEST_2.mov)

[THIS IS A LINK TO PART 3 OF THE PLAYTEST](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/PLAYTEST_3.mov)

[THIS IS A LINK TO PART 4 OF THE PLAYTEST](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/PLAYTEST_4.mov)

## **EVALUATION**

The game is on a base level is playable with a few setbacks such as sometimes the buttons can be pretty unresponsive such as the blue button in particular working on occasion and sometimes the other buttons require multiple presses to recogonise the input. It's not the most engaging game for a short while pressing buttons and seeing a colour can be engaing for a bit but long term not so much. Adding in previous rejected ideas such as the figures going under the board to make the visuals more intresting and maybe an actual robotic eye. It's very small so it's easy to carry around but it probably isn't the most accessible to colour blind people.

**REFERENCES**

[^1]: https://docs.arduino.cc/built-in-examples/basics/Blink/
[^2]: https://docs.arduino.cc/built-in-examples/basics/Fade/
[^3]: https://docs.arduino.cc/built-in-examples/analog/AnalogInput/
[^4]: [https://docs.arduino.cc/learn/electronics/servo-motors/](https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep/)
[^5]: https://howtomechatronics.com/how-it-works/how-servo-motors-work-how-to-control-servos-using-arduino/#google_vignette
[^6]: https://www.arduino.cc/en/Tutorial/Knob/
[^7]: https://www.allaboutcircuits.com/projects/using-the-arduinos-analog-io/
[^8]: https://learn.adafruit.com/adafruit-neopixel-uberguide?view=all
[^9]: https://docs.arduino.cc/built-in-examples/digital/Button/
[^10]: https://projecthub.arduino.cc/bruno_opaiva/controling-servo-motors-with-buttons-and-arduino-bcb3b6
[^11]: https://docs.arduino.cc/language-reference/en/functions/advanced-io/tone/
[^12]: https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalread/
[^13]:https://docs.arduino.cc/built-in-examples/digital/Debounce/
[^14]:https://docs.arduino.cc/language-reference/en/functions/advanced-io/tone/
[^15]:https://learn.adafruit.com/adafruit-pam8302-mono-2-5w-class-d-audio-amplifier/pinouts
[^16]:https://www.instructables.com/How-to-use-a-Buzzer-Arduino-Tutorial/
[^17]:https://roboticsbackend.com/arduino-push-button-tutorial/
[^18]:https://medium.com/@elonskolnik/arduino-uno-tutorial-neopixel-ring-setup-9fafc099c89a
