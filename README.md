# README Landfill Model Guide

Create by George Spearing for Arcana Workshop
March 2020

## Purpose

The lanfill model is run by an Arduino Nano with a breakout board to control audio track files. The audio track files live on the microSD card in the breakout board. Formmating for files are shown below.

## Audio Track Naming

The audio tracks are labeled using the scheme "TRACK000.wav" where "000" is the track identifier. These track numbers correspond to the buttons which light up specific sections.

## Track Numbering

- "000" Electric Power Plant
- "001" Empty - Not Used
- "002" Ground Water
- "003" Ground Liner
- "004" Leache Runoff
- "005" Gas Collection
- "006" Garbage Layer
- "007" Ground (Surface Layer)

## Track Formatting

The Arduino uses the TMRpcm library to play audio track from a microSD card. The full documentation for this library can be found at [https://github.com/TMRh20/TMRpcm/wiki](https://github.com/TMRh20/TMRpcm/wiki).

In summary, the tracks should be formatted as follows:

- Mono track
- 32000Hz (22050, 1600, 11025 also work)
- WAV, Unsigned 8 bit PCM

## Programming

I hope this doesn't need to be reprogrammed. There are two nano boards. 1 is the master and mainly controls all the leds. This is also the master to control the slave arduino file playing. The salve nano is a dedicated audio interpreter and player. This uses the micro SD card breakout. To program the slave nano, the SD car must NOT be connected. the MISO/MISI connections with the usbtiny during programming fail the upload. There is a switch on the circuit board that disables the SD card interface. Turn this off when progrmaming. DON'T FORGET TO TURN BACK ON ONCE DONE.

