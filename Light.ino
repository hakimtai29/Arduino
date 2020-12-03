#include <SPI.h>
#include <WiFi.h>

char ssid[] = "yourNetwork"; 
char pass[] = "secretPassword";    
int keyIndex = 0;            

int status = WL_IDLE_STATUS;
char server[] = "www.google.com";    
WiFiClient client;

int signal1[] = {0,1};
int signal2[] = {0,1};
int signal3[] = {0,1};
int signal4[] = {0,1};
int redDelay = 5000;
void setup()
 {
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);

    delay(10000);
  }
  for (int i = 0; i < 3; i++)
  {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
    pinMode(signal3[i], OUTPUT);
    pinMode(signal4[i], OUTPUT);
  }
}
void loop() 
{
  int arr[4], i = 0;
  client.connect(server, 80);
  while (client.available()) 
  {
    char c = client.read();
    arr[i] = c;
  }
    digitalWrite(signal1[0], LOW);
    digitalWrite(signal2[0], LOW);
    digitalWrite(signal3[0], LOW);
    digitalWrite(signal4[0], LOW);
    digitalWrite(signal1[1], LOW);
    digitalWrite(signal2[1], LOW);
    digitalWrite(signal3[1], LOW);
    digitalWrite(signal4[1], LOW);
  if(arr[0] == 1)
  {
    digitalWrite(signal1[1], HIGH);
  }
  else
  {
    digitalWrite(signal1[0], HIGH);
  }
  

  if(arr[1] == 1)
  {
    digitalWrite(signal2[1], HIGH);
  }
  else
  {
    digitalWrite(signal2[0], HIGH);
  }
  

  if(arr[2] == 1)
  {
    digitalWrite(signal3[1], HIGH);
  }
  else
  {
    digitalWrite(signal3[0], HIGH);
  }
  
  
  if(arr[3] == 1)
  {
    digitalWrite(signal4[1], HIGH);
  }
  else
  {
    digitalWrite(signal4[0], HIGH);
  }
  

  
}