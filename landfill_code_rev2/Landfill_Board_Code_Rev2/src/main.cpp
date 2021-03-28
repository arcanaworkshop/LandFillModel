#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


const int yellow_pin = 2;
const int red_pin = 3;
#define STRIP_PIN 10
#define LED_COUNT 4

Adafruit_NeoPixel strip(LED_COUNT, STRIP_PIN);

// Define 74hc165 Pins
/* How many shift register chips are daisy-chained.
*/
#define NUMBER_OF_SHIFT_CHIPS   1

/* Width of data (how many ext lines).
*/
#define DATA_WIDTH   NUMBER_OF_SHIFT_CHIPS * 8

/* Width of pulse to trigger the shift register to read and latch.
*/
#define PULSE_WIDTH_USEC   5

/* Optional delay between shift register reads.
*/
#define POLL_DELAY_MSEC   5

int ploadPin        = 5;  // Connects to Parallel load pin the 165
int clockEnablePin  = 6;  // Connects to Clock Enable pin the 165
int dataPin         = 7; // Connects to the Q7 pin the 165
int clockPin        = 8; // Connects to the Clock pin the 165

void setup() {

  // Initialize our digital pins...
  pinMode(ploadPin, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, INPUT);

  // set initial state of register
  digitalWrite(clockPin, LOW); 
  digitalWrite(ploadPin, HIGH);

  // start neo pixel string
  strip.begin();
  strip.show();

  // set state of two LEDs
  pinMode(yellow_pin, OUTPUT);  
  pinMode(red_pin, OUTPUT);


}

void loop() {
  digitalWrite(yellow_pin, HIGH);
  strip.setPixelColor(3,255,0,0);
  strip.show();
  digitalWrite(red_pin, HIGH);
}