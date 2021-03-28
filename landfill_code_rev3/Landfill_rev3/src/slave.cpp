/**
 * George Spearing
 * Revision 3 of Landfill Model Code
 * 8 Buttons for user input. Play one audio file and light
 * up one section of the model. One LED always lit
 * February 26, 2020
 */

// #define DEBUG

#include <Arduino.h>
#include <Wire.h>

#include <SD.h>                      // need to include the SD library
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>
#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328, can use other pins

TMRpcm tmrpcm;   // create an object for use in this sketch

void receiveEvent(int howMany);

void setup(){

    Wire.begin(1);
    Wire.onReceive(receiveEvent);
    #ifdef DEBUG
        Serial.begin(9600);
    #endif

    // start tmrpcm
    tmrpcm.speakerPin = 9; // define speaker pin
    tmrpcm.setVolume(3); // volume setting for audio file
    tmrpcm.quality(0); // SET TO QUALITY 0 FOR BEST AUDIO
    tmrpcm.disable();

    #ifndef DEBUG
    SD.begin(SD_ChipSelectPin);
    #endif

    // test and start SD Card
    #ifdef DEBUG
        if(SD.begin(SD_ChipSelectPin)){
            Serial.println("SD OK");
            tmrpcm.play("TRACK000.wav");
        }
        else{
            Serial.println("SD FAIL");
        }
    #endif
}

void loop(){

}

void receiveEvent(int howMany){
    while(Wire.available()){
        char inByte = Wire.read();
        switch(inByte){
            case 'a':
                tmrpcm.play("TRACK000.wav");
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
            case 'b':
                tmrpcm.play("TRACK001.wav");
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
            case 'c':
                tmrpcm.play("TRACK002.wav");
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
            case 'd':
                tmrpcm.play("TRACK003.wav");
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
            case 'e':
                tmrpcm.play("TRACK004.wav");
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
            case 'f':
                tmrpcm.play("TRACK005.wav");
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
            case 'g':
                tmrpcm.play("TRACK006.wav");
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
            case 'h':
                tmrpcm.play("TRACK007.wav");
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
            case 'z':
                tmrpcm.stopPlayback();
                #ifdef DEBUG
                    if(tmrpcm.isPlaying()){
                        Serial.println("playing audio");
                    }
                #endif
                break;
        }
    }
}