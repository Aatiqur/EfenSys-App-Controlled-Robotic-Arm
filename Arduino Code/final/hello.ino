#include <WiFi.h>         // Automatically get it from ESP32 Board Package
#include <HTTPClient.h>   // get it from Arduino Official Library Package
#include <ArduinoJson.h>  // get it from Arduino Official Library Package
#include <ESP32Servo.h>
#define spd 500

const char* ssid = "Hack";  // wifi name
const char* password = "asdfghjkl";   // wifi password

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
  Serial.begin(115200);
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  servog.setPeriodHertz(50);
  servowp.setPeriodHertz(50);
  servoe.setPeriodHertz(50);
  servos.setPeriodHertz(50);
  servow.setPeriodHertz(50);

  servog.attach(servogg, 1000, 2000);
  servowp.attach(servowpp, 1000, 2000);
  servoe.attach(servoee, 1000, 2000);
  servos.attach(servoss, 1000, 2000);
  servow.attach(servoww, 1000, 2000);
  /* servog.write(180);
    delay(spd);
    servowp.write(60);
    delay(spd);
    servoe.write(80);
    delay(spd);
    servos.write(180);
    delay(spd);
    servow.write(0);*/
  WiFi.begin(ssid, password);  // start the wifi

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  val = getData();
  currVal = val;
}

void loop() {
  val = getData();
  currVal = val;
  if (currVal != prevVal) {
    servoMovement();
    prevVal = val;
  }
  else if (currVal == prevVal) {
    prevVal = val;
  }
}

String getData() {
  http.begin(url);  // start the http client

  //Getting the Data from Firebase.........................................................................................................................

  int httpGETCode = http.GET();  // getting the httpGET code

  if (httpGETCode > 0) {
    String payload = http.getString();  // getting the main JSON data
    deserializeJson(doc, payload);      // preapring to make JSON data readable
    String data = doc[String("data")];  // making JSON data readable
    return data;
  }
  else {
    Serial.println(http.errorToString(httpGETCode).c_str());
  }

  http.end();
}

void servoMovement() {
  dataIn = getData();  // Read the data as string
  //Move Servo 1
  if (dataIn.startsWith("s1")) {
    String dataInS = dataIn.substring(2, dataIn.length());  // Extract only the number. E.g. from "s1120" to "120"
    servogP = dataInS.toInt();                              // Convert the string into integer
    // We use for loops so we can control the speed of the servo

    if (servogPPos > servogP)  // If previous position is bigger then current position
    {
      for (int j = servogPPos; j >= servogP; j--)  // Run servo down
      {
        servog.write(j);
        delay(10);  // defines the speed at which the servo rotates
      }
    }

    if (servogPPos < servogP)  // If previous position is smaller then current position
    {
      for (int j = servogPPos; j <= servogP; j++)  // Run servo up
      {
        servog.write(j);
        delay(10);
      }
    }
    servogPPos = servogP;  // set current position as previous position
  }

  // Move Servo 2
  if (dataIn.startsWith("s2")) {
    String dataInS = dataIn.substring(2, dataIn.length());
    servowpP = dataInS.toInt();

    if (servowpPPos > servowpP) {
      for (int j = servowpPPos; j >= servowpP; j--) {
        servowp.write(j);
        delay(10);
      }
    }
    if (servowpPPos < servowpP) {
      for (int j = servowpPPos; j <= servowpP; j++) {
        servowp.write(j);
        delay(10);
      }
    }
    servowpPPos = servowpP;
  }
  // Move Servo 3
  if (dataIn.startsWith("s3")) {
    String dataInS = dataIn.substring(2, dataIn.length());
    servoeP = dataInS.toInt();
    if (servoePPos > servoeP) {
      for (int j = servoePPos; j >= servoeP; j--)
      {
        servoe.write(j);
        delay(20);
      }
    }
    if (servoePPos < servoeP) {
      for (int j = servoePPos; j <= servoeP; j++) {
        servoe.write(j);
        delay(20);
      }
    }
    servoePPos = servoeP;
  }
  // Move Servo 4
  if (dataIn.startsWith("s4")) {
    String dataInS = dataIn.substring(2, dataIn.length());
    servosP = dataInS.toInt();
    if (servosPPos > servosP) {
      for (int j = servosPPos; j >= servosP; j--) {
        servos.write(j);
        delay(20);
      }
    }
    if (servosPPos < servosP) {
      for (int j = servosPPos; j <= servosP; j++) {
        servos.write(j);
        delay(20);
      }
    }
    servosPPos = servosP;
  }
  // Move Servo 5
  if (dataIn.startsWith("s5")) {
    String dataInS = dataIn.substring(2, dataIn.length());
    servowP = dataInS.toInt();
    if (servowPPos > servowP) {
      for (int j = servowPPos; j >= servowP; j--) {
        servow.write(j);
        delay(20);
      }
    }
    if (servowPPos < servowP) {
      for (int j = servowPPos; j <= servowP; j++) {

        servow.write(j);
        delay(20);
      }
    }
  }
  servowPPos = servowP;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // If button "SAVE" is pressed
  if (dataIn.startsWith("SAVE"))
  {
    Serial.println("Hello");
    servogSP[ind] = servogPPos;  // save position into the array
    servowpSP[ind] = servowpPPos;
    servoeSP[ind] = servoePPos;
    servosSP[ind] = servosPPos;
    servowSP[ind] = servowPPos;
    Serial.println(servogSP[ind]);
    ind++;  // Increase the array index

  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // If button "RUN" is pressed
  dataIn = getData();
  Serial.println("Current Val: " + currVal);
  Serial.println("Previous Val: " + prevVal);
  while (dataIn.startsWith("RUN"))
  {

    Serial.println("Run:  DJBASJBKDA");
    Serial.println(dataIn);
    if (dataIn != "RESET")  // Run the steps over and over again until "RESET" button is pressed
    {

      Serial.println("Run:  in while");

      for (int i = 0; i <= ind - 1; i++)  {
        servog.write(servogSP[i]);
        Serial.println(servogSP[i]);
        delay(spd);
        servowp.write(servowpSP[i]);
        Serial.println(servowpSP[i]);
        delay(spd);
        servoe.write(servoeSP[i]);
        Serial.println(servoeSP[i]);
        delay(spd);
        servos.write(servosSP[i]);
        Serial.println(servosSP[i]);
        delay(spd);
        servow.write(servowSP[i]);
        Serial.println(servowSP[i]);
        dataIn = getData();

        if (currVal != prevVal)  // Check for incomding data
        {
          prevVal = dataIn;

          if (dataIn == "PAUSE")  // If button "PAUSE" is pressed
          {
            while (dataIn != "RUN")  // Wait until "RUN" is pressed again
            {
              if (currVal != prevVal)
              {
                dataIn = getData();
                if (dataIn == "RESET")
                {
                  prevVal = dataIn;
                  break;
                }
              }
            }
          }
        }
      }
    }
  }
  // If button "RESET" is pressed
  if (dataIn == "RESET") {
    ESP.restart();
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
