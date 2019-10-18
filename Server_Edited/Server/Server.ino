

#include <SPI.h> //Libraries
#include <WiFi.h>//Libraries


char ssid[] = "vivo 1806"; //Name of my wifi hotspot     
char pass[] = "rajah1234"; //Password of my wifi hotspot
int keyIndex = 0;                
int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
 
  Serial.begin(9600);
  while (!Serial) {
    
  }

 if (WiFi.status() == WL_NO_SHIELD) { 
    Serial.println("WiFi shield not present");
  
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }

  //Trying to connect to my hotspot
  while (status != WL_CONNECTED) { 
  Serial.println("Attempting to connect to SSID . If red bulb blinks then check your hotspot whether its On or Off");
//  Serial.println(ssid) //just for printing SSID name
  status = WiFi.begin(ssid, pass);//Connecting to wifi
  printWifiStatus();//This function will print wifi name,password and IP address of this arduino
//  Serial.println(server.available()); //This will return whether there is a client is waiting or not

 //This will ensure that we found the slave robot
  if(server.available(){
  Serial.println("Connected");
  }
   }
  server.begin();
  

}
//Printing function
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




//This will check for client robot and send a data forever.You can delay it with a delay time
void loop() {
 
WiFiClient client = server.available(); //If client available client=1 else its client=0

if (client) {
    Serial.println("Slave Robot Found");
    Serial.println("Connected");

/*We can only send a one character char value to client.So I assigned switch case with 40 different alphabets. 
So ifyou want to send a data then assign it to a number then send it throuh wifi shield.Then set a condition in client robot to identify actions 
from char values 
*/       
int n=40; //Here I need to send a data.I assiged that kind of data as n=40. Then it will return 'z' to client.Then client will understand what is 'z' and 
//it will make decisions
char f;
switch(n)
{
case 1:
  f='A'; break;
case 2:
  f='B'; break;
case 3:
  f='C'; break;
case 4:
  f='D'; break;
case 5:
  f='E'; break;
case 6:
  f='F'; break;
case 7:
  f='G'; break;
case 8:
  f='H'; break;
case 9:
  f='I'; break;
case 10:
  f='J'; break;
case 11:
  f='K'; break;
case 12:
  f='L'; break;
case 13:
  f='M'; break;
case 14:
  f='N'; break;
case 15:
  f='O'; break;
case 16:
  f='P'; break;
case 17:
  f='Q'; break;
case 18:
  f='R'; break;
case 19:
  f='S'; break;
case 20:
  f='T'; break;
case 21:
  f='U'; break;
case 22:
  f='V'; break;
case 23:
  f='W'; break;
case 24:
  f='X'; break;
case 25:
  f='Y'; break;
case 26:
  f='Z'; break;
case 27:
  f='a'; break;
case 28:
  f='b'; break;
case 29:
  f='c'; break;
case 30:
  f='d'; break;
case 31:
  f='e'; break;
case 32:
  f='f'; break;
case 33:
  f='g'; break;
case 34:
  f='h'; break;
case 35:
  f='i'; break;
case 36:
  f='j'; break;
case 37:
  f='k'; break;
case 38:
  f='l'; break;
case 39:
  f='m'; break;
case 40:
  f='z'; break;
}
client.print(f); //Sending my data.My data is f
Serial.println(f);//Just printing for me
Serial.println();
//delay(9999999); //uncomment if you want delay
 }
 }
 

