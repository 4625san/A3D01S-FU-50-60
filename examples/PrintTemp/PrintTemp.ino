// A3D01S-FU-50-60 Library Example
// Version: 1.0 (2023.05.01)
// License: MIT
// Copyright(c) 2023 4625san(@4625nyanko)
//

#include "a3d01s.h"

a3d01s TPSens;

void setup() {
  Serial.begin(115200);

  if (!TPSens.IsPresent()){
    Serial.println("No A3D01S found.");
    while(1);
  }
}

void loop() {
  Serial.print("Internal:");
  Serial.print(TPSens.Internal());
  Serial.print("\t");
  Serial.print("Target:");
  Serial.print(TPSens.Target());
  Serial.println("");
  delay(50);
}
