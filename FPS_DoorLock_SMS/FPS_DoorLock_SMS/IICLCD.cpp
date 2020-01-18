// 
// 
// 

#include "IICLCD.h"

IICLCD::IICLCD(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
{
	lcd = new LiquidCrystal_I2C(lcd_addr, lcd_cols, lcd_rows);
	rows = lcd_rows;

	lcd->begin();
}


IICLCD::~IICLCD()
{
	if (lcd)
		delete lcd;
}

void IICLCD::showisFPSConnected()
{
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print("  FingerPrint ");
	lcd->setCursor(0, 1);
	lcd->print("Sensor Connected");
}

void IICLCD::showFPSnotFound()
{
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print("Unable to found");
	lcd->setCursor(0, 1);
	lcd->print("Sensor");
}

void IICLCD::showFPSCheckConnection()
{
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print("Check Connections");
}

void IICLCD::showreadNotValidImge()
{
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print("  Waiting For");
	lcd->setCursor(0, 1);
	lcd->print("  Valid Finger");
}

void IICLCD::showcheckFailedImage2Tz()
{
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print("  Messy Image");
	lcd->setCursor(0, 1);
	lcd->print("  Try Again");
}

void IICLCD::showfindNotMatch()
{
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print("Not Valid Finger");
}

void IICLCD::showSuccess()
{
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print("  Door Unlocked");
	lcd->setCursor(0, 1);
	lcd->print("    Welcome");
}




