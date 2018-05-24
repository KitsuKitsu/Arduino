#include <WiFi.h>
#include <HTTPClient.h>

const char ssid[]="ssid";
const char password[]="password";
const char lock_url[]="api_url:5000/";
const int trigger_pin = 26;
const int echo_pin = 25;
int echo_res;
int kyori;

void setup() {
  Serial.begin(115200);
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

  //Wifiに接続
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("connecting");
    delay(100);
    }
  Serial.println("connected");
}
void loop(){

  //距離を測定
  digitalWrite(trigger_pin, LOW);        
  delayMicroseconds(2);            
  digitalWrite(trigger_pin, HIGH);    
  delayMicroseconds(10);            
  digitalWrite(trigger_pin, LOW);       
  echo_res = pulseIn(echo_pin, HIGH);
  kyori =  echo_res*340*100/1000000;
  
  //モニタに出力
  Serial.print(kyori);
  Serial.println("cm");
  
  //30cm以下ならGETを送る
  if(kyori < 30){
    HTTPClient http;
    http.begin(lock_url);
    int res_code = http.GET();
    Serial.println(res_code);
    delay(5000);
  }else{
    delay(100);
  }
}
