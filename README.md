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

This is a link to the Servo Sweep video: [Servo Sweep Video](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/Serco%20Sweep.mp4)

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

This is a basic servo knob circuit using a potentiometer:

![SERVO POTENTIOMETER PHYSICAL DIAGRAM](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/Servo%20and%20Potentiometer.jpg)

This is a basic servo knob schematic diagram using a potentiometer:

![SERVO POTENTIOMETER SCHEMATICS](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/SERVO_KNOB_SCHEMATICS.png)

There are also different analog inputs to control a servo using a potentinmeter and a light dependent resistor.

This is a link to the Servo Potentiometer Video: [Servo Potentiometer Video](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/Servo%20and%20Potentiometer%20Knob.mp4)

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

A servo can be used in a number of ways to precisly move an object such as robotic arms and RC vechiles.
//CONCLUSION AND HOW THIS COULD POTENTIALLY BE APPLIED TO THE PROJECT

### **DIGITAL INTERFACING**

### **WIRELESS COMMUNICATION**

## **GAME DESIGN IDEAS**

### GAME IDEA 1

The concept of this game idea is that the 2 players would have sensors covering all over their bodies such as shoulders, knees and arms and you would hit the other player with a soft weapon that would hit the other players sensors adding a point everytime a player hits one of the sensors with a winning condition after a time period. This idea was rejected due to the complexity of the build.

### GAME IDEA 2

Another  game idea would be a shooter in which the player would shoot light from a toy gun and it would shine onto sensors for the player to gain a point using. The idea was rejected due to the difficulity level and its simularities to arcade games that are like that.

### GAME IDEA 3

Another game concept idea was a battle ships idea in which the the player would have to chase an enemy around a board to try and catch the enemy.

### GAME IDEA 4

### FINAL GAME IDEA 

The final game project idea is a 3 player game in which an open eye will open and close the players will lose their lives if they're not holding the button down whilst the eye is looking at the player, when a player has lost a life the figure will stay down and that player will be out for the rest of the game. There will be 3 rounds with the timer getting quicker each time with the winner of the game being the last player standing.

![Game Concept Sketch](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/Game%20Concept.png)
![Game Storyboard](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/STORYBOARD_FOR_OUTOFSIGHT.jpg)

## **TESTING**

When it came to starting the project we started with making a button circuit as that will be the main way to play the game.

![Button circuit test](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/1000010239.jpg)

- TESTING IDEAS
- CODE LISTINGS
- CIRCUIT DIAGRAMS

## **TECHNICAL DOCUMENTATION**

- FINAL CIRCUIT DIAGRAMS AND CODE 

## **MANUAL**

- HOW TO OPERATE THE GAME
- RULES OF THE GAME
- HEALTH AND SAFETY WARNINGS

## **PLAYTESTING**

**REFERENCES**

[^1]: https://docs.arduino.cc/built-in-examples/basics/Blink/
[^2]: https://docs.arduino.cc/built-in-examples/basics/Fade/
[^3]: https://docs.arduino.cc/built-in-examples/analog/AnalogInput/
[^4]: [https://docs.arduino.cc/learn/electronics/servo-motors/](https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep/)
[^5]: https://howtomechatronics.com/how-it-works/how-servo-motors-work-how-to-control-servos-using-arduino/#google_vignette
[^6]: https://www.arduino.cc/en/Tutorial/Knob/
[^7]: https://www.allaboutcircuits.com/projects/using-the-arduinos-analog-io/
