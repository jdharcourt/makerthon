#include <Arduino.h>

#define LED_PIN 13

#define DOT_MS 200
#define DASH_MS 600
#define SYMBOL_GAP_MS 200
#define LETTER_GAP_MS 600
#define WORD_GAP_MS 1400

String input;

const char *morseFor(char value) {
  switch (tolower(value)) {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    default: return nullptr;
  }
}

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

void blinkMorse(const char *code) {
  for (int i = 0; code[i] != '\0'; i++) {
    if (code[i] == '.') {
      dot();
    } else {
      dash();
    }
  }
}

void translate(String text) {
  text.trim();

  if (text.length() == 0) {
    return;
  }

  Serial.print("Morse: ");

  for (int i = 0; i < text.length(); i++) {
    if (isspace(text[i])) {
      Serial.print("/ ");
      wordGap();
      continue;
    }

    const char *code = morseFor(text[i]);

    if (code == nullptr) {
      continue;
    }

    Serial.print(code);
    Serial.print(" ");
    blinkMorse(code);
    letterGap();
  }

  Serial.println();
  Serial.println("Enter a word:");
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Enter a word:");
}

void loop() {
  while (Serial.available() > 0) {
    char value = Serial.read();

    if (value == '\n' || value == '\r') {
      translate(input);
      input = "";
      return;
    }

    if (input.length() < 64) {
      input += value;
    }
  }
}
