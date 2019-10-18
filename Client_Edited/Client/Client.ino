

#include <SPI.h>
#include <WiFi.h>


char ssid[] = "vivo 1806";
char pass[] = "rajah1234";
int keyIndex = 0;
int status = WL_IDLE_STATUS;
WiFiClient client1; //Assigning a name for 


IPAddress server1(192, 168, 43,167); //IP address of our server.You can find it by running the server file.


void setup() {
  Serial.begin(9600);
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }
  while (status != WL_CONNECTED) {
    //    Serial.print("Attempting to connect to SSID: ");
    //   Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  printWifiStatus();
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  //  Serial.print("signal strength (RSSI):");
  //  Serial.print(rssi);
  // Serial.println(" dBm");
}

void loop() {

  while (client1.available()) { //If server available it will return true
    char recievedData = client1.read(); //It will recieve the data and save it to  recievedData char file
    Serial.println(recievedData);
  }
}




















