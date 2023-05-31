#include <IRremote.h>
#include "SR04.h"
#define trig1 5
#define echo1 6

SR04 s1 = SR04(echo1 , trig1);
long a;

IRrecv IR(13);
unsigned long previousMillis1 = 0;
const long interval1 = 500;
const long interval2 = 1500;

// Motor A connections
int enA = 10;
int in1 = 12;
int in2 = 7;
// Motor B connections
int enB = 11;
int in3 = 2;
int in4 = 4;

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  IR.enableIRIn();
  digitalWrite(3, HIGH);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
 
  

}


void loop() {
  a = s1.Distance();
if (a<5)
  sstopp();

  unsigned long currentMillis = millis();
  if (IR.decode()) { 
    if (currentMillis - previousMillis1 >= interval1) {
      previousMillis1 = currentMillis;
      IR.resume();
    }
    
    if (IR.decodedIRData.decodedRawData == 0xF30CFF00)
      forward();
    else if (IR.decodedIRData.decodedRawData == 0xE718FF00)
      back();
    else if (IR.decodedIRData.decodedRawData == 0xA15EFF00)
      spin();
    else if (IR.decodedIRData.decodedRawData == 0xF708FF00)
      right();
    else if (IR.decodedIRData.decodedRawData == 0xE31CFF00)
      left();
    else
      sstopp();

  }
}


  void sstopp() {
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    digitalWrite(in1, HIGH);
        Serial.println("s");

  }
   void spin() {
    unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in1, HIGH);
    if (currentMillis - previousMillis >= interval2) {
      previousMillis = currentMillis;
      digitalWrite(in4, LOW);
      digitalWrite(in1, LOW);
    }
        Serial.println("ss");

  }
  void back() {
    unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in1, HIGH);
    if (currentMillis - previousMillis >= interval2) {
      previousMillis = currentMillis;
      digitalWrite(in4, LOW);
      digitalWrite(in1, LOW);
    }
     Serial.println("b");
  }
  void forward() {
    unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in1, LOW);
  if (currentMillis - previousMillis >= interval2) {
    previousMillis = currentMillis;
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    Serial.println("f");
  }
  }
  void right() {
    unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in1, HIGH);
    if (currentMillis - previousMillis >= interval2) {
      previousMillis = currentMillis;
      digitalWrite(in3, LOW);
      digitalWrite(in1, LOW);
     
    }
      Serial.println("r");
  }

  
  void left() {
    unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in1, LOW);
    if (currentMillis - previousMillis >= interval2) {
      previousMillis = currentMillis;
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
    }
      Serial.println("l");
  }
