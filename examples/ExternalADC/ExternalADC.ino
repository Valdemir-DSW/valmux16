#include <VALMUX16.h>

VALMUX16 mux(2,3,4,5);

int fakeADC() {
    //Você pode utilizar, para utilizar uma fonte de ADC externa, por exemplo, o módulo ADS1115. Com essa função será totalmente possível utilizar. 
    //Neste caso, a porta analógica comum dos multiplexadores será ligada em apenas uma porta, no módulo ADS, por exemplo. Daí aqui, nesta função, você faria a leitura desta porta em específico.
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
