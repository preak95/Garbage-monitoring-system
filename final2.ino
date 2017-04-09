#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define echoPin1 D7 // Echo Pin
#define trigPin1 D6 // Trigger Pin



long duration, distance1; // Duration used to calculate distance

const int RELAY_PIN = 2; //RELAY
 
const char* ssid = "sagar";
const char* password = "bhininjosq@vjti";
String s1;


WiFiClient client;
  char servername[]="192.168.43.147";  // remote server we will connect to
  String result;
/*
MDNSResponder mdns;
ESP8266WebServer server(80);



void handleNotFound(){
  server.send(200, "text/plain", "Percentage Filled in dustbin1: " + s1);
}
 */
void setup(void){
  Serial.begin (9600);
  
  pinMode(RELAY_PIN, OUTPUT);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(RELAY_PIN, 1);
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(RELAY_PIN, 0);
  
  //server.begin();
  //Serial.println("HTTP server started");
}
 
void loop(void){
  //server.handleClient();
  distance1 = read_dustbin1();
  s1 = (String)distance1;
  sendDataToServer(s1);
  delay(150);
   
  
  Serial.print(distance1);
  Serial.println();
  
   //server.onNotFound(handleNotFound);
   delay(50);
}
//level?level=4
void sendDataToServer(String level)
{
  if (client.connect(servername, 8000)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /level?level="+level+" HTTP/1.1"); //Send data
    client.println("Host: 192.168.43.147");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("connection failed"); //error message if no client connect
    Serial.println();
  }

 while(client.connected() && !client.available()) delay(1); //waits for data
  while (client.connected() || client.available()) { //connected or data available
    char c = client.read(); //gets byte from ethernet buffer
      result = result+c;
    }

  client.stop(); //stop client
  Serial.println(result);
  
}


long read_dustbin1()
{
   pinMode(trigPin1, OUTPUT);
   pinMode(echoPin1, INPUT);
   digitalWrite(trigPin1, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin1, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin1, LOW);
   duration = pulseIn(echoPin1, HIGH);
   //Calculate the distance (in cm) based on the speed of sound.
   distance1 = duration/58.2;
   return(distance1);
   delay(100);
}
  
  
