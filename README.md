# TANGIBLE-PROJECT
TANGIBLE DOCUMENTATION 

**NAME OF PROJECT: ...**

## **EXPERIMENTS**

//THIS IS A LIST OF THE EXPERIMENTS THAT WE DID IN CLASS

### **DIGITAL OUTPUT**

When using digital outputs we can control the inputs being taken and precisly controlling the output we mainly used LEDs to show an output.

This is a simple built LED output circuit:

![Physical LED circuit](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/IMG_20250220_125427151.jpg)

Here is a circuit diagram on a LED output.

![LED Schematics Diagram](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/LED_SCHEMATICS.jpg)

Here is some Blink code that will turn the LED on and off though this code won't loop

```
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
```
[^1]
This is video of an LED blinking in a continuous loop.

![Video of an LED blinking on a reapeted loop](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Videos/VID_20250220_125439799.mp4)

Another LED output program is a fade in which the LED will loop fading on and off:

```
int led = 13;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 13 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 13:
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

*INSERT ARDUNIO LED FADE OUTPUT VIDEO*

//Reflection on how this can be applicatied in games
The digital LED output is very basic but could probably used in a multidude of ways such as it could be used such as a health system turning off the LED when the player has taken damage.

### **ANALOG**

When experimenting with analog... A 

This is a basic physical built potentiometer and light dependent resistor

Here is a physical circuit of a light dependent resistor:

![Physical Light Dependent Resisitor circuit](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/1000009678.jpg)

Here is a circuit diagram of a light dependent resistor:

*INSERT LIGHT DEPENDENT RESISITOR SCHEMATICS*

Here is a physical circuit of a potentiometer:

*INSERT POTENTIOMETER PICTURE*

Here is a circuit diagram of a potentiometer:

*INSERT POTENTIOMETER SCHEMATICS*

[^3]

//How this can potentially be applied

### **SERVOS AND MOTION**

A servo motor is a closed-loop system that uses precise position of its shaft to move to its final position.
[^5]

This is a basic circuit diagram that controls the servo sweep:

*INSERT SERVO SWEEP SCHEMATICS*

Here is the basic physical circuit built of the servo sweep:

*INSERT THE SERVO SWEEP PICTURE*

//CODE FOR THE SERVO SWEEP

[^4]

There are also different analog inputs to control a servo using a potentinmeter and a light dependent resistor.

*INSERT THE SERVO BEING CONTOLLED BY A POTENTIOMETER AND LIGHT DEPENDENT RESISTOR*

A servo can be used in a number of ways to precisly move an object such as robotic arms and RC vechiles.
//CONCLUSION AND HOW THIS COULD POTENTIALLY BE APPLIED TO THE PROJECT

### **DIGITAL INTERFACING**

### **WIRELESS COMMUNICATION**

## **GAME DESIGN IDEAS**

- ANY PREVIOUS GAME IDEAS
- PENCIL DRAWINGS

The final game project idea is a 3 player game in which an open eye will open and close the players will lose their lives if they're not holding the button down whilst the eye is looking at the player, when a player has lost a life the figure will stay down and that player will be out for the rest of the game. There will be 3 rounds with the timer getting quicker each time with the winner of the game being the last player standing.

![Game Concept Sketch](https://github.com/CaNi31/TANGIBLE-PROJECT/blob/main/Pictures/Game%20Concept.png)

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
[^4]: https://docs.arduino.cc/learn/electronics/servo-motors/
[^5]: https://howtomechatronics.com/how-it-works/how-servo-motors-work-how-to-control-servos-using-arduino/#google_vignette
