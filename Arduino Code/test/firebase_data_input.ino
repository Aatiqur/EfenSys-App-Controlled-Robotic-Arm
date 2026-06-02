void firebase_servo_control()
{
  if (dataIn.startsWith("s1")) {
    String dataInS = dataIn.substring(2, dataIn.length());  // Extract only the number. E.g. from "s1120" to "120"
    servogP = dataInS.toInt(); // Convert the string into integer
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
  ////////////////////////////////////////////////////////////////////////Servo 2
  if (dataIn.startsWith("s2")) {
    String dataInS = dataIn.substring(2, dataIn.length());
    servowpP = dataInS.toInt();
    if (servowpPPos > servowpP)
      for (int j = servowpPPos; j >= servowpP; j--) {
        servowp.write(j); delay(10);
      }
    else if (servowpPPos < servowpP) {
      for (int j = servowpPPos; j <= servowpP; j++) {
        servowp.write(j);
        delay(10);
      }
    }
    servowpPPos = servowpP;
  }
  ////////////////////////////////////////////////////////////////////////Servo 3
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
  ////////////////////////////////////////////////////////////////////////Servo 4
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

  ////////////////////////////////////////////////////////////////////////Servo 5

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
    servowPPos = servowP;
  }


}
