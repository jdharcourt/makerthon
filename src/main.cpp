#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 8
#define NUM_LEDS 1

Adafruit_NeoPixel led(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

#define DOT_MS        200
#define DASH_MS       600
#define SYMBOL_GAP_MS 200
#define LETTER_GAP_MS 600
#define WORD_GAP_MS  1400

void ledOn() {
  led.setPixelColor(0, led.Color(255, 255, 255));
  led.show();
}

void ledOff() {
  led.setPixelColor(0, 0);
  led.show();
}

void dot() {
  ledOn();
  delay(DOT_MS);
  ledOff();
  delay(SYMBOL_GAP_MS);
}

void dash() {
  ledOn();
  delay(DASH_MS);
  ledOff();
  delay(SYMBOL_GAP_MS);
}

void letterGap() {
  delay(LETTER_GAP_MS - SYMBOL_GAP_MS);
}

void wordGap() {
  delay(WORD_GAP_MS - SYMBOL_GAP_MS);
}

void setup() {
  led.begin();
  led.setBrightness(100);
  led.show();
}

void loop() {
  // P: .--.
  dot(); dash(); dash(); dot();
  letterGap();

  // A: .-
  dot(); dash();
  letterGap();

  // T: -
  dash();
  letterGap();

  // C: -.-.
  dash(); dot(); dash(); dot();
  letterGap();

  // H: ....
  dot(); dot(); dot(); dot();

  wordGap();
}
