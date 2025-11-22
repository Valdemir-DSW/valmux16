#include "VALMUX16.h"
//By Valdemir 
VALMUX16::VALMUX16(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3)
{
    _pinS[0] = s0;
    _pinS[1] = s1;
    _pinS[2] = s2;
    _pinS[3] = s3;

    _adcExternal = nullptr;
    _adcPin = A0;
    _muxCount = 0;

    for (int i = 0; i < MAX_MUX; i++)
        _enablePins[i] = 255;
}

void VALMUX16::setMuxCount(uint8_t count)
{
    if (count > MAX_MUX) count = MAX_MUX;
    _muxCount = count;
}

void VALMUX16::setEnable(uint8_t muxIndex, uint8_t enPin)
{
    if (muxIndex < MAX_MUX)
        _enablePins[muxIndex] = enPin;
}

void VALMUX16::setAdcFunction(int (*funcaoADC)())
{
    _adcExternal = funcaoADC;
}

void VALMUX16::setInternalAdcPin(uint8_t pin)
{
    _adcPin = pin;
}

void VALMUX16::begin()
{
    for (int i = 0; i < 4; i++)
        pinMode(_pinS[i], OUTPUT);

    for (int i = 0; i < _muxCount; i++) {
        if (_enablePins[i] != 255) {
            pinMode(_enablePins[i], OUTPUT);
            digitalWrite(_enablePins[i], HIGH);
        }
    }
}

void VALMUX16::disableAll()
{
    for (int i = 0; i < _muxCount; i++) {
        if (_enablePins[i] != 255)
            digitalWrite(_enablePins[i], HIGH);
    }
}

void VALMUX16::selectChannel(uint8_t ch)
{
    digitalWrite(_pinS[0], ch & 1);
    digitalWrite(_pinS[1], (ch >> 1) & 1);
    digitalWrite(_pinS[2], (ch >> 2) & 1);
    digitalWrite(_pinS[3], (ch >> 3) & 1);
}

int VALMUX16::read(uint8_t muxIndex, uint8_t channel)
{
    if (muxIndex >= _muxCount || channel > 15)
        return 0;

    disableAll();

    if (_enablePins[muxIndex] != 255)
        digitalWrite(_enablePins[muxIndex], LOW);

    selectChannel(channel);
    delayMicroseconds(5);

    if (_adcExternal != nullptr)
        return _adcExternal();

    return analogRead(_adcPin);
}

int VALMUX16::readLinear(uint8_t pin)
{
    if (pin >= (16 * _muxCount))
        return 0;

    uint8_t mux = pin / 16;
    uint8_t ch  = pin % 16;

    return read(mux, ch);
}
