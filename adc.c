#include<reg51.h>

//////////// PIN DEFINED ///////////////
#define DATA P0
#define ADC P3
sbit RS=P2^0;
sbit E=P2^1;
sbit ALE=P1^2;
sbit SOC=P1^1;
sbit OE=P1^0;
sbit EOC=P1^3;
sbit SET0=P1^5;
sbit SET1=P1^6;
sbit SET2=P1^7;
sbit CLOCK=P1^4;
//////////////////////////////////////////
#include"delay.h"
#include"lcd.h"
#include"adc.h"

unsigned char adc_val;

void main(void)
{ 
  init_lcd();
	string_lcd("ADC Test");
	delay(30000);
  while(1)
  {   
    adc_val = adc(7);	
		cmd_lcd(0xc0);
		number_lcd(adc_val,3);
		delay(1000);
   }
 }




