#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t IR_LED_PIN = 4; // D2
IRsend irsend(IR_LED_PIN);

void setup() {
  Serial.begin(115200);
  irsend.begin();
}

void loop() {
  Serial.println("IR sender: a:oxo1");
  uint32_t code = irsend.encodeNEC(0x0001, 0x03);
  irsend.sendNEC(code, 32);
  delay(2000);
} `