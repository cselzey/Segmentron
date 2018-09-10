//Segmentron library
// By Christian Elzey
// Last modified 9-8-2018
// 
// Description: Intended to be run on an ESP8266 microcontroller powering a Segmentron 16-segment display. 
// See Github for more info. 
//
// This library contains code adapted from the  Adafruit_LEDBackpack library.
// Library abailable at https://github.com/adafruit/Adafruit_LED_Backpack. 
// The Adafruit_LED_Backpack library is freely made available under the MIT license. See license.txt.  




#ifndef Segmentron_h
#define Segmentron_h

#include "Arduino.h"
#include <Wire.h>




// These define statements are borrowed from the Adafruit Adafruit_LEDBackpack library, which uses 
// the same HT16K33 IC. Library abailable at https://github.com/adafruit/Adafruit_LED_Backpack
#define HT16K33_BLINK_CMD 0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BLINK_OFF 0
#define HT16K33_BLINK_2HZ  1
#define HT16K33_BLINK_1HZ  2
#define HT16K33_BLINK_HALFHZ  3



#define HT16K33_CMD_BRIGHTNESS 0xE0


class Segmentron {
 public:
  Segmentron(void);
  void begin(uint8_t _numberOfModules);
  void setBrightness(uint8_t b);
  void blinkRate(uint8_t b);
  void writeDisplay(void);
  void clear(void);
  void writeDigitRaw(uint8_t n, uint16_t bitmask);
  void writeDigitAscii(uint8_t n, uint8_t ascii);
  
  uint16_t displaybuffer[64]; 
  
 void init(uint8_t a); // I have no phreaking idea what this even does. 
 protected:
  uint8_t i2c_addr;
};









































#endif