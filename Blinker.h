#ifndef _BLINKER_H
#define _BLINKER_H

#if (ARDUINO >= 100)
# include <Arduino.h>
#else
# include <WProgram.h>
#endif

class Blinker {
	private:
        int _blinkPin;
        uint32_t _blinkDelay;
        uint32_t _lastBlink;
        boolean _blinkState;
        boolean _running;

	public:
		Blinker(int pin);
		void setDelay(uint32_t d);
        void blink();
        void start();
        void stop();
};

#endif
