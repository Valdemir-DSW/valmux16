# valmux16
It facilitates the use of analog multiplexers (MUX).

```
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
```
Também é possível anexar o modulo ADC externo, por exemplo, o modo ADS-1115. Veja isso nos exemplos de como utilizar fonte ADC externa.

<img width="260" height="248" alt="image" src="https://github.com/user-attachments/assets/465a2d15-b211-48a1-81b0-8a3d0dcd9b1a" />

