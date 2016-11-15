// File: TrackFPV.ino 
// Date: 15.11.2016
// Author: Hendrik Schutter
// Version: a0.1

#include <Joystick.h>
#include <CPPM.h>

int yawRaw;
int pitchRaw;
int min = -500; 
int max = 500;

void cppm_cycle(void){
  if (CPPM.synchronized()){
    yawRaw = CPPM.read_us(CPPM_GEAR) - 1500; 
    pitchRaw = CPPM.read_us(CPPM_AUX1) - 1500; 
  }
  else
  {
    Serial.println("Nix");
  }
}

int getYAW() {
  yawRaw = yawRaw - 22;
  yawRaw = max_min(yawRaw);
  float f = yawRaw/5;
  return f;
}

int getPITCH() {
  pitchRaw = pitchRaw - 22;
  pitchRaw = max_min(pitchRaw);
  float f = pitchRaw/5;
  return f;                           
}

int max_min(int zahl) {
  if (zahl > max) {
    zahl = max;
  }
  if (zahl < min) {
    zahl = min;
  }
  return zahl;
}


void setup(){
  Serial.begin(9600);
  CPPM.begin();
  Joystick.begin(true);
}

void loop(){
  cppm_cycle();
  Serial.print("Pitchraw: ");
  Serial.println(pitchRaw-22);
  Serial.print("YAWraw: ");
  Serial.println(yawRaw-22);
  
  Serial.print("Pitch: ");
  Serial.println(getPITCH());
  Serial.print("YAW: ");
  Serial.println(getYAW());
  
  Joystick.setYAxis(getPITCH());
  Joystick.setXAxis(getYAW());
  
  delay(100);
}
