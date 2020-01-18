// SMS.h

#ifndef _SMS_h
#define _SMS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Sim800L.h>
#include <SoftwareSerial.h>

//#define DEFAULT_RX_PIN 		10
//#define DEFAULT_TX_PIN 		11
//#define DEFAULT_RESET_PIN 	2		

class SMS
{
public:
	SMS(String contact_no);
	~SMS();

	void send(String text);

private:
	String contact_no;
	uint8_t reset_pin;
	Sim800L GSM;
};

#endif

