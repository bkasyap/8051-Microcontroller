#include<reg51.h>
#include"delay.h"
#define SEG_DATA P1
#define SEG_CTRL P0
																			   
unsigned char sev_seg[10]={0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef}; 

void main()
{
unsigned char j;
while(1)
{
	for(j=0;j<10;j++)
		{
		    SEG_CTRL = 0x0f;
			SEG_DATA = sev_seg[j];
			delay(30000);
		}
	}
}