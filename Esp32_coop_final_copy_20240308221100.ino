#include <WiFi.h>
#include <HTTPClient.h>


/********************************************************************************/
//Things to update
const char * ssid = "YOURSSID";
const char * password = "PASSWORD";
String GOOGLE_SCRIPT_ID = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

const int delayTime = 10000; 
String payload;
/********************************************************************************/
/********************************************************************************/
WiFiClientSecure client;
//motor relay 1298n stuff

int enA = 21;
int in1 = 19;
int in2 = 18;
//Reed switch stuff
int lowerReed = 22;
int upperReed = 23;
int stateOfLowerReed = 0;
int stateOfUpperReed = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(upperReed, INPUT_PULLUP);
  pinMode(lowerReed, INPUT_PULLUP);

  Serial.begin(9600);
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

}

void loop() {
Serial.println("starting LOOP");
spreadsheetCall();
delay(delayTime);

stateOfLowerReed = digitalRead(lowerReed);
stateOfUpperReed = digitalRead(upperReed);

if (payload=="Open"){
  motorUp();
  }

if (payload=="Close") {
  motorDown();
}
}
//////////////////////////////////////////////////////////////////////////////////////////////
void motorUp() {
  Serial.println("motor  up");
      while (stateOfUpperReed != LOW) {
        Serial.println("motor going up");
        analogWrite(enA, 170);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        stateOfUpperReed = digitalRead(upperReed);
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void motorDown() {
  Serial.println("motor  down");
      while (stateOfLowerReed != LOW) {
        Serial.println("motor going down");
        analogWrite(enA, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        stateOfLowerReed = digitalRead(lowerReed);
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void spreadsheetCall(void) {
   HTTPClient http;
   String url="https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?read=a2";
//   Serial.print(url);
	Serial.print("Making a request");
	http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
	int httpCode = http.GET();
    if (httpCode > 0) { //Check for the returning code
        payload = http.getString();
        
        Serial.println(httpCode);
        Serial.println(payload);
      }
    else {
      Serial.println("Error on HTTP request");
    }
	http.end();
}