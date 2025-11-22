#include <VALMUX16.h>

VALMUX16 mux(2,3,4,5);

void setup() {
    Serial.begin(115200);

    mux.setMuxCount(2);

    mux.setEnable(0, 6);
    mux.setEnable(1, 7);

    mux.setInternalAdcPin(A0);
    mux.begin();
}

void loop() {
    int v = mux.readLinear(10);
    Serial.println(v);
    delay(200);
}
