/*
 Name:		FPS_DoorLock_SMS.ino
 Created:	1/18/2020 8:12:17 AM
 Author:	CrisantoIII
*/

// the setup function runs once when you press reset or power the board
#include "SMS.h"
#include "Relay.h"
#include "IICLCD.h"
#include "FPS.h"

//SMS_RX 					10
//SMS_TX 					11
//SMS_RESET 				2
//SDA						A4
//SCL						A5
//FPS_RX					0
//FPS_TX					1

#define FPS_BAUDRATE		57600
#define RELAY_PIN			3
#define CONTACTNO			"+63000000000"

#define LCD_ADDRESS			0x27
#define LCD_ROWS			2	
#define LCD_COLS			16

SMS *sms;
Relay *relay;
IICLCD *lcd;
FPS *fps;

void setup() {
	sms = new SMS(CONTACTNO);
	relay = new Relay(RELAY_PIN, false);
	lcd = new IICLCD(LCD_ADDRESS, LCD_ROWS, LCD_COLS);
	fps = new FPS(&Serial, FPS_BAUDRATE);

	if (fps->isFPSConnected())
	{
		lcd->showisFPSConnected();
		delay(3000);
	}
	else
	{
		lcd->showFPSnotFound();
		delay(3000);
		lcd->showFPSCheckConnection();
		while (1) {}
	}
		
}

// the loop function runs over and over again until power down or reset
void loop() {
  
	processFPS();
	delay(50);
}

int processFPS()
{
	if (fps->readValidImge() == false)
	{
		lcd->showreadNotValidImge();
		return -1;
	}

	if (fps->checkImage2Tz() == false)
	{
		lcd->showcheckFailedImage2Tz();
		delay(3000);
		return -1;
	}

	if (fps->findMatch() == false)
	{
		lcd->showfindNotMatch();
		sms->send("FPS Failed");
		delay(3000);
		return -1;
	}

	//If everything was ok, then we successfully match
	lcd->showSuccess();
	relay->On();
	sms->send("FPS Accepted");
	delay(3000);
	relay->Off();
	return fps->Success();
}
