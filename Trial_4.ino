//#include <SerialESP8266wifi.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#define FIREBASE_HOST "https://control-led-from-everywhere-default-rtdb.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "EwCPUVuD3pq0jZdR7j0r26y2wzZZuCPfMfbI04TE"       //Your Firebase Database Secret goes here
#define WIFI_SSID "Control Your Home"                                               //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "babehngopii"                                      //Password of your wifi network 

#define Relay1 12 //D6
int val1;

#define Relay2 14 //D5
int val2;

#define Relay3 4  //D2
int val3;

#define Relay4 5 //D1
int val4;

FirebaseData firebaseData;

void setup() 
{
  Serial.begin(115200);                                                   // Select the same baud rate if you want to see the datas on Serial Monitor
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);

  digitalWrite(Relay1,HIGH);
  digitalWrite(Relay2,HIGH);
  digitalWrite(Relay3,HIGH);
  digitalWrite(Relay4,HIGH);



  
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(" . ");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

   Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
   Firebase.setInt(firebaseData,"S1",0);       //Here the varialbe"S1","S2","S3" and "S4" needs to be the one which is used in our Firebase and MIT App Inventor
   Firebase.setInt(firebaseData,"S2",0); 
   Firebase.setInt(firebaseData,"S3",0); 
   Firebase.setInt(firebaseData,"S4",0); 
  
}
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }

void loop() 
{
//  if (Firebase.failed())
     // {
  //    Serial.print("setting number failed:");
    //  Serial.println(Firebase.error());
      //firebasereconnect();
      //return;
      //}  
val1= Firebase.getString(firebaseData,"/HOME_AUTOMATION/S1") ? 1 : 0;
  
if(val1==1) {
    if(firebaseData.stringData() == "1")
    {
        digitalWrite(Relay1,LOW);
        
        Serial.println("light 1 ON");
    }
    else
    {                                      
        digitalWrite(Relay1,HIGH);
        Serial.println("light 1 OFF");
    }
} 
else
{
    Serial.println("error getting data from firebase");
}

val2= Firebase.getString(firebaseData,"/HOME_AUTOMATION/S2") ? 1 : 0;
  
if(val2==1) 
{
    if(firebaseData.stringData() == "1")
    {
        digitalWrite(Relay2,LOW);
        
        Serial.println("light 2 ON");
    } else 
    {                                      
        digitalWrite(Relay2,HIGH);
        Serial.println("light 2 OFF");
    }
} 
else
{
    Serial.println("error getting data from firebase");
}

 val3= Firebase.getString(firebaseData,"/HOME_AUTOMATION/S3") ? 1 : 0;
  
if(val3==1) 
{
    if(firebaseData.stringData() == "1")
    {
        digitalWrite(Relay3,LOW);
        
        Serial.println("light 3 ON");
    } 
    else
    {                                      
        digitalWrite(Relay3,HIGH);
        Serial.println("light 3 OFF");
    }
} 
else
{
    Serial.println("error getting data from firebase");
}

 val4= Firebase.getString(firebaseData,"/HOME_AUTOMATION/S4") ? 1 : 0;
  
if(val4==1)
{
    if(firebaseData.stringData() == "1")
    {
        digitalWrite(Relay4,LOW);
        
        Serial.println("light 4 ON");
    } 
    else 
    {                                      
        digitalWrite(Relay4,HIGH);
        Serial.println("light 4 OFF");
    }
}
else
{
    Serial.println("error getting data from firebase");
}
}
