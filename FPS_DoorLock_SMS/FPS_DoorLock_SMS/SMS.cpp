// 
// 
// 

#include "SMS.h"

SMS::SMS(String contact_no)
{
	GSM.begin(4800);

	this->contact_no = contact_no;
}

SMS::~SMS()
{

}

void SMS::send(String text)
{
	GSM.sendSms((char *)contact_no.c_str(), (char *)text.c_str());
}