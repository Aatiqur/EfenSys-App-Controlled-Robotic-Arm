void button()
{
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
  // If button "RUN" is pressed
  dataIn = getData();
  Serial.println("Current Val: " + currVal);
  Serial.println("Previous Val: " + prevVal);
  while (dataIn.startsWith("RUN")) {
    for (int i = 0; i < ind - 1; i++) { // Run through all steps(index)
//      Serial.print(servogSP[i]);
//      Serial.print("    ");
//      Serial.print(servogSP[i+1]);
//      Serial.println("    ");
//      delay(2000);
      //////////////////////////////////////////////////////////////1
      if (servogSP[i] > servogSP[i + 1])
        for (int j = servogSP[i]; j >= servogSP[i + 1]; j--) {
          servog.write(j); delay(20);
        }
      else if (servogSP[i] < servogSP[i + 1])
        for (int j = servogSP[i]; j <= servogSP[i + 1]; j++) {
          servog.write(j); delay(20);
        }
      //////////////////////////////////////////////////////////////2
      if (servowpSP[i] > servowpSP[i + 1])
        for ( int j = servowpSP[i]; j >= servowpSP[i + 1]; j--) {
          servowp.write(j); delay(20);
        }

      else if (servowpSP[i] < servowpSP[i + 1])
        for ( int j = servowpSP[i]; j <= servowpSP[i + 1]; j++) {
          servowp.write(j); delay(20);
        }
      //////////////////////////////////////////////////////////////////////3
      if (servoeSP[i] > servoeSP[i + 1])
        for ( int j = servoeSP[i]; j >= servoeSP[i + 1]; j--) {
          servoe.write(j);  delay(20);
        }
      else if (servoeSP[i] < servoeSP[i + 1])
        for ( int j = servoeSP[i]; j <= servoeSP[i + 1]; j++) {
          servoe.write(j);
          delay(20);
        }
      //////////////////////////////////////////////////////////////////////4
      if (servosSP[i] > servosSP[i + 1])
        for ( int j = servosSP[i]; j >= servosSP[i + 1]; j--) {
          servos.write(j);
          delay(20);
        }
      else if (servosSP[i] < servosSP[i + 1])
        for ( int j = servosSP[i]; j <= servosSP[i + 1]; j++) {
          servos.write(j);
          delay(20);
        }
      //////////////////////////////////////////////////////////////////////5
      if (servowSP[i] > servowSP[i + 1])
        for ( int j = servowSP[i]; j >= servowSP[i + 1]; j--) {
          servow.write(j);
          delay(20);
        }
      if (servowSP[i] < servowSP[i + 1])
        for ( int j = servowSP[i]; j <= servowSP[i + 1]; j++) {
          servos.write(j);
          delay(20);
        }

      dataIn = getData();
      if (currVal != prevVal) {
        prevVal = dataIn;
        if (dataIn == "PAUSE") {
          while (dataIn != "RUN") {
            dataIn = getData();
            if (currVal != prevVal) {
              if (dataIn == "RESET") {
                prevVal = dataIn;
                ESP.restart();
              }
            }
          }
        }
      }
    }
  }
}
