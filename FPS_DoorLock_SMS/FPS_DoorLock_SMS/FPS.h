// FPS.h

#ifndef _FPS_h
#define _FPS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_Fingerprint.h>

class FPS
{
public:
	FPS(HardwareSerial *hs, uint32_t baudrate);
	~FPS();

	bool isFPSConnected();

	bool readValidImge();
	bool checkImage2Tz();
	bool findMatch();
	int Success();

private:
	Adafruit_Fingerprint *finger;

};

#endif

