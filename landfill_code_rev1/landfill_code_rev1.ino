#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 7;
////Pin connected to DS of 74HC595
int dataPin = 6;

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
int button1State = 0;
int button2State = 0;
int button3State = 0;

void setup()
{
  //buttons
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
     
  tmrpcm.speakerPin=9;
  Serial.begin(9600);
  if(!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  tmrpcm.setVolume(6);


}

void loop() {
  
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);

  if(button1State == HIGH){
    tmrpcm.play("audio1.wav");
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 1);  
    digitalWrite(latchPin, HIGH);
  }
  if(button2State == HIGH){
    tmrpcm.play("audio2.wav");
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 2);  
    digitalWrite(latchPin, HIGH);
  }
  if(button3State == HIGH){
    tmrpcm.play("audio3.wav");
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 4); 
    digitalWrite(latchPin, HIGH); 
  }

  if(!tmrpcm.isPlaying()){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0); 
    digitalWrite(latchPin, HIGH); 
  }
}
