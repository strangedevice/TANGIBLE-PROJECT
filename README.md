# TANGIBLE-PROJECT
TANGIBLE DOCUMENTATION 

**NAME OF PROJECT: ...**

## **EXPERIMENTS**

//THIS IS A LIST OF THE EXPERIMENTS THAT WE DID IN CLASS

### **DIGITAL OUTPUT**

When experimenting with the digital output of the Arduino we used LEDs to show an output.

This is a phyisically built LED output circuit:

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
*INSERT ARDUNIO LED OUTPUT VIDEO*

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

*INSERT ARDUNIO LED FADE OUTPUT VIDEO*

//Reflection on how this can be applicatied in games
The digital LED output is very basic but could probably used in a multidude of ways such as it could be used as an health system turning of the LED when taken damage.

### **ANALOGUE OUTPUT**

When experimenting with analogue... A 

Here is a circuit diagram of a light dependent resistor:

*INSERT LIGHT DEPENDENT RESISITOR SCHEMATICS*

Here is a circuit diagram of a potentiometer:

*INSERT POTENTIOMETER SCHEMATICS*

## **GAME DESIGN IDEAS**

- ANY PREVIOUS GAME IDEAS
- PENCIL DRAWINGS 

## **TESTING**

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
