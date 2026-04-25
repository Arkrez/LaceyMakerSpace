#include <Arduino.h>
#include <RCSwitch.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

// Pins
const uint16_t RF_PIN = 5;     // D1 (GPIO5)
const uint16_t IR_LED_PIN = 4; // D2 (GPIO4)

RCSwitch mySwitch = RCSwitch();
IRsend irsend(IR_LED_PIN);

void setup() {
  Serial.begin(115200);

  // 1. Initialize IR
  irsend.begin();

  // 2. Initialize RF
  // On ESP8266, you can pass the pin number directly to enableReceive
  mySwitch.enableReceive(RF_PIN); 
  
  Serial.println("System Online. Waiting for 433.92MHz signal...");
}

void loop() {
  if (mySwitch.available()) {
    long receivedValue = mySwitch.getReceivedValue();

    if (receivedValue != 0) {
      Serial.print("Received RF Code: ");
      Serial.println(receivedValue);

      // --- TRIGGER LOGIC ---
      // Press your remote button and watch the Serial Monitor.
      // Replace '123456' with the number you see for your remote.
      if (receivedValue == 16407524) { 
          Serial.println("Match found! Sending IR to turn on/off...");
          uint32_t code = irsend.encodeNEC(0x0001, 0x03);
          irsend.sendNEC(code, 32);
      } else if (receivedValue == 1841) {
        Serial.println("Match found! Sending IR to turn speed up...");
          uint32_t code = irsend.encodeNEC(0x0001, 0x07);
          irsend.sendNEC(code, 32);
      }
    }

    mySwitch.resetAvailable(); // Clear flag for next signal
  }
}