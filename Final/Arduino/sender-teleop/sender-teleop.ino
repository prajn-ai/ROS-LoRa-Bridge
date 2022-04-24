#include "heltec.h"
#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

int counter = 0;
#define w 4
#define a 2
#define s 17
#define d 16

void setup() {
  
  //WIFI Kit series V1 not support Vext control
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  pinMode(w, INPUT);
  pinMode(a, INPUT);
  pinMode(s, INPUT);
  pinMode(d, INPUT);
}

void loop() {
  // send packet
  LoRa.beginPacket();
/*
* LoRa.setTxPower(txPower,RFOUT_pin);
* txPower -- 0 ~ 20
* RFOUT_pin could be RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
*   - RF_PACONFIG_PASELECT_PABOOST -- LoRa single output via PABOOST, maximum output 20dBm
*   - RF_PACONFIG_PASELECT_RFO     -- LoRa single output via RFO_HF / RFO_LF, maximum output 14dBm
*/

  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  
  if(buttonPressed1(w)) {
  LoRa.print("w");
  LoRa.endPacket();
  }

  if(buttonPressed2(a)) {
  LoRa.print("a");
  LoRa.endPacket();
  }

  if(buttonPressed3(s)) {
  LoRa.print("s");
  LoRa.endPacket();
  }
  
  if(buttonPressed4(d)) {
  LoRa.print("d");
  LoRa.endPacket();
  }

}

int buttonPressed1(uint8_t button) {
  static uint16_t lastStates = 0;
  uint8_t state = digitalRead(button);
  if (state != ((lastStates >> button) & 1)) {
    lastStates ^= 1 << button;
    return state == HIGH;
  }
  return false;
}

int buttonPressed2(uint8_t button) {
  static uint16_t lastStates = 0;
  uint8_t state = digitalRead(button);
  if (state != ((lastStates >> button) & 1)) {
    lastStates ^= 1 << button;
    return state == HIGH;
  }
  return false;
}
int buttonPressed3(uint8_t button) {
  static uint16_t lastStates = 0;
  uint8_t state = digitalRead(button);
  if (state != ((lastStates >> button) & 1)) {
    lastStates ^= 1 << button;
    return state == HIGH;
  }
  return false;
}
int buttonPressed4(uint8_t button) {
  static uint16_t lastStates = 0;
  uint8_t state = digitalRead(button);
  if (state != ((lastStates >> button) & 1)) {
    lastStates ^= 1 << button;
    return state == HIGH;
  }
  return false;
}
