// A3D01S-FU-50-60 Library
// Version: 1.0 (2023.05.01)
// License: MIT
// Copyright(c) 2023 4625san(@4625nyanko)
//

#include "a3d01s.h"
#include "Arduino.h"
#include "Wire.h"

a3d01s::a3d01s(byte adr){
  adrs = adr;
  Wire.begin();
}

a3d01s::a3d01s(){
  adrs = defaultAdrs;
  Wire.begin();
}


float a3d01s::Target() {
  uint16_t raw;
  float tmp;

  raw = regRead16(regTargetTemp);
  tmp = ((float)raw / 8 - 30);

  return(tmp);
}

float a3d01s::Internal() {
  uint16_t raw;
  float tmp;

  raw = regRead16(regSelfTemp);
  tmp = ((float)raw / 8 - 20);

  return(tmp);
}

uint16_t a3d01s::regRead16(byte reg) {
  uint16_t buf;
  Wire.beginTransmission(adrs);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom((int)adrs, 2, false);
  Wire.readBytes((uint8_t*)&buf, 2);
  Wire.endTransmission(true);
  return (buf);
}


bool a3d01s::IsPresent() {
  Wire.beginTransmission(adrs);
  return(Wire.endTransmission()==0);
}
