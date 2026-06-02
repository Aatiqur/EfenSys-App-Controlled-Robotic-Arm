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
