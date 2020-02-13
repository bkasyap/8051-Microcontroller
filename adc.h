void clock(void)
{
 int a,b;
 for(b=0;b<=1000;b++)
 {
  for(a=0;a<30;a++);
  CLOCK=~CLOCK;
 }
}

unsigned char adc(char s)
{
	unsigned char dat;
	if(s & (1<<0))	SET0=1;	
	if(s & (1<<1))	SET1=1;	
	if(s & (1<<2))	SET2=1;	
	
	ALE=1;    SOC=1;    clock();
  ALE=0;    SOC=0;    clock();
  while(EOC==0);
  OE = 1;
	dat = ADC;
	return(dat);
}