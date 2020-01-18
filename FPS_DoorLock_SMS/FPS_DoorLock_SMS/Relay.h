// Relay.h

#ifndef _RELAY_h
#define _RELAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Relay
{
public:
	Relay(uint8_t pin, bool is_high);
	~Relay();

	void On();
	void Off();

private:
	uint8_t pin;
};


#endif

