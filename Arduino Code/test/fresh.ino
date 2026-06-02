#include <WiFi.h>         // Automatically get it from ESP32 Board Package
#include <HTTPClient.h>   // get it from Arduino Official Library Package
#include <ArduinoJson.h>  // get it from Arduino Official Library Package
#include <ESP32Servo.h>
#define spd 500

const char* ssid = "NAF Tech_WiFi";  // wifi name
const char* password = "N@f Tech";   // wifi password

String val, prevVal = "a", currVal;

HTTPClient http;                // declare the http client
DynamicJsonDocument doc(1024);  // for create JSON object

String url = "https://robotic-arm-56dc5-default-rtdb.firebaseio.com/ARM.json";  // main api url
int servogg = 15;   //griper servo
int servowpp = 16;  // wrist pitch servo
int servoee = 17;   //elbow servo
int servoss = 4;   //shoulder servo
int servoww = 2;   //waist servo

Servo servog;   //griper servo
Servo servowp;  // wrist pitch servo
Servo servoe;   //elbow servo
Servo servos;   //shoulder servo
Servo servow;   //waist servo

int servogP, servowpP, servoeP, servosP, servowP;                           // current position
int servogPPos, servowpPPos, servoePPos, servosPPos, servowPPos;            // previous position
int servogSP[50], servowpSP[50], servoeSP[50], servosSP[50], servowSP[50];  // for storing positions/steps

int ind = 0;
String dataIn = "";

void setup() {
  Serial.begin(115200);        // start the serial monitor
  WiFi.begin(ssid, password);  // start the wifi

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  val = getData();
  currVal = val;

  servog.attach(servogg, 1000, 2000);
  servowp.attach(servowpp, 1000, 2000);
  servoe.attach(servoee, 1000, 2000);
  servos.attach(servoss, 1000, 2000);
  servow.attach(servoww, 1000, 2000);
}

void loop() {
  val = getData();
  currVal = val;
  if (currVal != prevVal)
  {
    servoMovement();
    Serial.println("Value: " + val);
    prevVal = val;

    for(int i =0; i < ind; i++){
      Serial.print(servogSP[i]);
      Serial.print("  ");
    }
    
  }
}



void servoMovement() {
  dataIn = getData();  // Read the data as string
  firebase_servo_control();
  button();
}
