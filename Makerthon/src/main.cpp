#include <Arduino.h>

#define LED_PIN 2

#define DOT_MS   200
#define DASH_MS  600
#define SYMBOL_GAP_MS  200
#define LETTER_GAP_MS  600
#define WORD_GAP_MS   1400

void dot() {
  digitalWrite(LED_PIN, HIGH);
  delay(DOT_MS);
  digitalWrite(LED_PIN, LOW);
  delay(SYMBOL_GAP_MS);
}

void dash() {
  digitalWrite(LED_PIN, HIGH);
  delay(DASH_MS);
  digitalWrite(LED_PIN, LOW);
  delay(SYMBOL_GAP_MS);
}

void letterGap() {
  delay(LETTER_GAP_MS - SYMBOL_GAP_MS); // subtract the trailing symbol gap already applied
}

void wordGap() {
  delay(WORD_GAP_MS - SYMBOL_GAP_MS);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
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
