#include<reg51.h>
#include<intrins.h>
#define DATA  P2
sbit RS = P1^0;
sbit E = P1^1;

sbit SCL=P0^0;	
sbit SDA=P0^1;

#include<delay.h>
#include<lcd.h>
#include<rtc.h>

void main()
{
 unsigned char rec; 	
 init_lcd();
 string_lcd("RTC clock");
 delay(30000);
 set_rtc(10,17,12,6,20,12,14); // sec,min,hrs,day,date,month,year


while(1)
{
	cmd_lcd(0x80);
	rec=read_rtc(3);
	if(rec==0)                string_lcd("SUN  ");
	if(rec==1)                string_lcd("MON  ");
	if(rec==2)                string_lcd("TUES ");
	if(rec==3)                string_lcd("WED  ");
	if(rec==4)                string_lcd("THUR ");
	if(rec==5)                string_lcd("FRI  ");
	if(rec==6)                string_lcd("SAT  ");

   rec=read_rtc(4);  number_lcd(rec & 0x3f,2);  data_lcd('/');
   rec=read_rtc(5);  number_lcd(rec & 0x1f,2);  data_lcd('/');
   rec=read_rtc(6);  number_lcd(rec & 0x7f,2);
   cmd_lcd(0xc5);
   rec=read_rtc(2);  number_lcd(rec & 0x3f,2);  data_lcd(':');
   rec=read_rtc(1);  number_lcd(rec & 0x7f,2);  data_lcd(':');
   rec=read_rtc(0);  number_lcd(rec & 0x7f,2);
}
}
