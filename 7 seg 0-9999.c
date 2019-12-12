#include<reg51.h>
#include"delay.h"

#define SEG_DATA P0
#define SEG_CTRL P2

unsigned char sev_seg[10]={0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef};

void main(void)
{
unsigned char a,b,c,d,e;
while(1)
{
for(d=0;d<10;d++)
{
  for(c=0;c< 10;c++)
  {
	for(b=0;b< 10;b++)
	{
		for(a=0;a< 10;a++)
		{
			for(e=0;e<50;e++)// for delay or hold the hole value for few sec
			{
				SEG_CTRL = 0x01;
				SEG_DATA = sev_seg[a];
				delay(200);
				
				SEG_CTRL = 0x02;
				SEG_DATA = sev_seg[b];
				delay(200);
				
				SEG_CTRL = 0x04;
				SEG_DATA = sev_seg[c];
				delay(200);
				
				SEG_CTRL = 0x08;
				SEG_DATA = sev_seg[d];
				delay(200);
			}
		}
	}
  }
}
}
}