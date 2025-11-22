#include <VALMUX16.h>

VALMUX16 mux(2,3,4,5);

int fakeADC() {
    return 1234;
}

void setup() {
    Serial.begin(115200);

    mux.setMuxCount(1);
    mux.setEnable(0, 6);
    mux.setAdcFunction(fakeADC);

    mux.begin();
}

void loop() {
    Serial.println(mux.readLinear(0));
    delay(200);
}
