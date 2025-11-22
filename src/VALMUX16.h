#ifndef VALMUX16_H
#define VALMUX16_H

#include <Arduino.h>
//By Valdemir 
class VALMUX16 {
public:
    VALMUX16(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3);

    void setMuxCount(uint8_t count);
    void setEnable(uint8_t muxIndex, uint8_t enPin);
    void setAdcFunction(int (*funcaoADC)());
    void setInternalAdcPin(uint8_t pin);
    void begin();

    int read(uint8_t muxIndex, uint8_t channel);
    int readLinear(uint8_t pin);

private:
    static const uint8_t MAX_MUX = 6;

    uint8_t _pinS[4];
    uint8_t _enablePins[MAX_MUX];
    uint8_t _muxCount;
    uint8_t _adcPin;

    int (*_adcExternal)();

    void disableAll();
    void selectChannel(uint8_t ch);
};

#endif
