#include "heltec.h"
#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

const int w = 2;
const int a = 4;
const int s =  5;
const int d = 18;

int counter = 0;

//Buttons W A S D as a remote controller to send commands to control turtlesim on slave 

void setup() {
  
  //WIFI Kit series V1 not support Vext control
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/); 
  pinMode(w, INPUT);
  pinMode(a, INPUT);
  pinMode(s, INPUT);
  pinMode(d, INPUT);
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
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

  if(digitalRead(w)){
    LoRa.print("1");
    }
    else if(digitalRead(a)){
      LoRa.print("2");
    }
    else if(digitalRead(s)){
      LoRa.print("3");
    }
    else if(digitalRead(d)){
      LoRa.print("4");
    }else{
      LoRa.print("0");
    }
  LoRa.print(counter);
  LoRa.endPacket();
  
  counter++;
}
