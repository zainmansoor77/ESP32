

#include <WiFi.h>                                                // esp32 library
#include <FirebaseESP32.h>
//#include <IOXhop_FirebaseESP32.h>                                             // firebase library

#define FIREBASE_HOST "led-control-b1d21.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "zHR47tIAi6Hr6oSJ47zgTBBbt1r7PrMaDo21sgEb"
#define WIFI_SSID "ebiz"
#define WIFI_PASSWORD "Mccormick67"  //password of wifi ssid

FirebaseData firebaseData;
String path = "/Test/Stream";
String fireStatus = "";                                                     // led status received from firebase

int led = 2;                                                               

void setup() {

  Serial.begin(9600);

  delay(1000);

  pinMode(2, OUTPUT);                

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      //try to connect with wifi

  Serial.print("Connecting to ");

  Serial.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");

    delay(500);

  }

  Serial.println();

  Serial.print("Connected to ");

  Serial.println(WIFI_SSID);

  Serial.print("IP Address is : ");

  Serial.println(WiFi.localIP());                                                      //print local IP address

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                                       // connect to firebase

  //Firebase.setString("LED_STATUS", "OFF");                                          //send initial string of led status
  //Firebase.setString("message", "hello world");
  Firebase.setString(firebaseData, path + "/String", "OFF" );
    

}

void loop() {

  fireStatus = Firebase.getString(firebaseData, path + "/String");                     // get led status input from firebase

  if (fireStatus == "ON") {                         // compare the input of led status received from firebase

    Serial.println("Led Turned ON");                 

    digitalWrite(2, HIGH);                                                         // make output led ON

  }

  else if (fireStatus == "OFF") {              // compare the input of led status received from firebase

    Serial.println("Led Turned OFF");

    digitalWrite(2, LOW);                                                         // make output led OFF

  }

  else {

    Serial.println("Wrong Credential! Please send ON/OFF");

  }

}
