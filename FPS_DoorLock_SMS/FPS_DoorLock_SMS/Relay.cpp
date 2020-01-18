// 
// 
// 

#include "Relay.h"


Relay::Relay(uint8_t pin, bool is_high)
{
	this->pin = pin;

	pinMode(pin, OUTPUT);

	if (is_high)
		digitalWrite(pin, HIGH);
	else
		digitalWrite(pin, LOW);
}

Relay::~Relay()
{

}

void Relay::On()
{
	digitalWrite(pin, HIGH);
}

void Relay::Off()
{
	digitalWrite(pin, LOW);
}