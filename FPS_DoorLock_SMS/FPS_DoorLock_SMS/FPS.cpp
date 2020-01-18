// 
// 
// 

#include "FPS.h"


FPS::FPS(HardwareSerial *hs, uint32_t baudrate)
{
	finger = new Adafruit_Fingerprint(hs);
	finger->begin(baudrate);
}

FPS::~FPS()
{
	if (finger)
		delete finger;
}

bool FPS::isFPSConnected()
{
	return finger->verifyPassword();
}

bool FPS::readValidImge()
{
	return finger->getImage() == FINGERPRINT_OK;
}

bool FPS::checkImage2Tz()
{
	return finger->image2Tz() == FINGERPRINT_OK;
}

bool FPS::findMatch()
{
	return finger->fingerFastSearch() == FINGERPRINT_OK;
}

int FPS::Success()
{
	return finger->fingerID;
}