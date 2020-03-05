#include <WiFi.h> 

const char* ssid = "ebiz";
const char* password = "Mccormick67";

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.begin(ssid,password);

while(WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(500);
}
Serial.print("\nconnected to wifi");
Serial.print("IP address: ");
Serial.println(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:

}
