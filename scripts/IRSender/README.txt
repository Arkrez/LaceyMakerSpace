1. In the Arduino IDE, go to Tools → Board and select "Generic ESP8266 Module."
2. Connect the D2 (GPIO4) pin on the ESP8266 to the data pin of the IR transmitter.
3. Open the Arduino IDE setting and add `http://arduino.esp8266.com/stable/package_esp8266com_index.json` to the "Additional Board Manager URL List"
4. Use the Arduino IDE to download the IRremoteESP8266.h & the rc-switch by sui77 library 
5. Upload the code to the ESP8266.