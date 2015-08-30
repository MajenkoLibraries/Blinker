#include <Blinker.h>

Blinker::Blinker(int pin) {
    _blinkPin = pin;
    _blinkDelay = 500;
    _lastBlink = 0;
    _blinkState = false;
    _running = false;
}

void Blinker::setDelay(uint32_t d) {
    _blinkDelay = d;
}

void Blinker::blink() {
    uint32_t diff = millis() - _lastBlink;
    if (diff >= _blinkDelay) {
        _lastBlink = millis() - (diff - _blinkDelay); // Account for any delay in calling blink
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
