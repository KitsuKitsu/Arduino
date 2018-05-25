#include <WiFi.h>
#include <HTTPClient.h>

const char ssid[]="ssid";
const char password[]="password";
const char lock_url[]="http://api_ip:5000/";
const int trigger_pin = 25;
const int echo_pin = 26;
int echo_res;
int kyori;

void setup() {
  Serial.begin(115200);
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("connecting");
    delay(100);
    }
  Serial.println("connected");
  delay(1000);
}
void loop(){

  digitalWrite(trigger_pin, LOW);        
  delayMicroseconds(2);            
  digitalWrite(trigger_pin, HIGH);    
  delayMicroseconds(10);            
  digitalWrite(trigger_pin, LOW);       
  echo_res = pulseIn(echo_pin, HIGH);
  kyori =  echo_res*340*100/1000000;
  
  Serial.print(kyori);
  Serial.println("cm");
  
  if(kyori < 50){
    HTTPClient http;
    http.begin(lock_url);
    int res_code = http.GET();
    Serial.println(res_code);
    delay(10000);
  }else{
    delay(80);
  }
}
