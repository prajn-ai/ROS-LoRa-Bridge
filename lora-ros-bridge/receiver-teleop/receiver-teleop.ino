#include "heltec.h"
#include <ros.h>
#include <string.h>
#include <std_msgs/Int8.h>

ros::NodeHandle nh;

std_msgs::Int8 int_msg;
ros::Publisher command("rcommand", &int_msg);

int received_command;

#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6
void setup() {
    //WIFI Kit series V1 not support Vext control
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
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
      Serial.print((char)LoRa.read());
      received_command = (char)LoRa.read() - '0';
    }
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }

  int_msg.data = received_command;
  command.publish( &int_msg );
  nh.spinOnce();
  delay(1000);
}
