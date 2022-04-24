#define ROSSERIAL_ARDUINO_TCP
#include "heltec.h"
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>

#define BAND 433E6  //you can set band here directly,e.g. 868E6,915E6
ros::NodeHandle nh;

std_msgs::String msg;
ros::Publisher command("rcommand", &msg);


void setup() {
    //WIFI Kit series V1 not support Vext control
  Serial.begin(115200);
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  WiFi.begin("IceCream", "butterscotch");
  
  while (WiFi.status() != WL_CONNECTED) 
  { delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected - IP address:  ");
  Serial.println(WiFi.localIP());
  nh.initNode();
  nh.advertise(command);
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");
    // read packet
    while (LoRa.available()) {
      msg.data = "w";
      command.publish(&msg);
      Serial.print((char)LoRa.read());
    }
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());

  nh.spinOnce();

  
  }
}
