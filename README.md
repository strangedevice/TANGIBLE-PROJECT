# TANGIBLE-PROJECT
TANGIBLE DOCUMENTATION 

**NAME OF PROJECT: ...**

## **EXPERIMENTS**

THIS IS A LIST OF THE EXPERIMENTS THAT WE DID IN CLASS

### **DIGITAL OUTPUT**

When experimenting with the digital output of the Arduino we used LEDs to show an output.

* *INSERT ARDUNIO LED OUTPUT DIAGRAM* *

Here is some Blink code that will make the LED which will turn the LED on and off:

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
