// IICLCD.h

#ifndef _IICLCD_h
#define _IICLCD_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class IICLCD
{
public:
	IICLCD(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);
	~IICLCD();

	void showisFPSConnected();
	void showFPSnotFound();
	void showFPSCheckConnection();

	void showreadNotValidImge();
	void showcheckFailedImage2Tz();
	void showfindNotMatch();
	void showSuccess();

private:
	LiquidCrystal_I2C *lcd;
	uint8_t rows;

};
#endif

