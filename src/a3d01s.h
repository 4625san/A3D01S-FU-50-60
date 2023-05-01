// A3D01S-FU-50-60 Library
// Version: 1.0 (2023.05.01)
// License: MIT
// Copyright(c) 2023 4625san(@4625nyanko)
//

#ifndef A3D01S_H
#define A3D01S_H
#include "Arduino.h"

class a3d01s {
  public:
    a3d01s(byte adr);
    a3d01s();
    
    bool IsPresent();
    float Target();
    float Internal();

  private:
    byte adrs;

    uint16_t regRead16(byte reg);

    // I2Cアドレスとレジスタアドレス
    const byte defaultAdrs = 0x3d;
    const byte regSelfTemp = 0x70;
    const byte regTargetTemp = 0x71;    

};
#endif
