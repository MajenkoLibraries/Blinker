#include <Blinker.h>

Blinker::Blinker(int pin) {
    _blinkPin = pin;
    _highDelay = 500;
    _lowDelay = 500;
    _lastBlink = 0;
    _blinkState = false;
    _running = false;
}

void Blinker::setDelay(uint32_t d) {
    _highDelay = d;
    _lowDelay = d;
}

void Blinker::setDelay(uint32_t h, uint32_t l) {
    _highDelay = h;
    _lowDelay = l;
}

void Blinker::blink() {
    uint32_t diff = millis() - _lastBlink;
    uint32_t blinkDelay = _blinkState ? _highDelay : _lowDelay;
    if (diff >= blinkDelay) {
        _lastBlink = millis() - (diff - blinkDelay); // Account for any delay in calling blink
        _blinkState = !_blinkState;
        if (_running) {
            digitalWrite(_blinkPin, _blinkState ? HIGH : LOW);
        }
    }
}

void Blinker::start() {
    pinMode(_blinkPin, OUTPUT);
    _running = true;
    _blinkState = false;
    _lastBlink = millis();
}

void Blinker::stop() {
    _running = false;
    digitalWrite(_blinkPin, LOW);
}
