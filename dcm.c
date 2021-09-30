#include<reg51.h>
#include"delay.h"
sbit m11 = P0^0;
sbit m12 = P0^1;

void main()
{	
	while(1)
	{
		m11=1; m12=0;
		delay(30000);delay(30000);delay(30000);
		m12=1; m11=0;
		delay(30000);delay(30000);delay(30000);}
}
Delay.h
void delay(int x)
{int i;
for(i=0;i<x;i++);
}
