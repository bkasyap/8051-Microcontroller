#include<reg51.h>
////// PIN DEFINED ////
#define DATA P0
sbit RS=P1^0;
sbit E=P1^1;
//////////////
#include"delay.h"
#include"lcd.h"


void main()
{
char i;
init_lcd();
	while(1)
	{
		cmd_lcd(0x80);
		string_lcd("LCD DISPLAY");
		cmd_lcd(0xc0);
		string_lcd("** 8051 ** ");
		
		for(i=0;i<5;i++)
		{
			cmd_lcd(0x1C);
			delay(30000);	
		}
		for(i=0;i<5;i++)
		{
			cmd_lcd(0x18);
			delay(30000);	
		}		
	}
}