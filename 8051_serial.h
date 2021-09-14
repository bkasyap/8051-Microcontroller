void init_serial(unsigned int br)
{
	TMOD=0x20;
	SCON=0x50;
	TH1=(256-(28800/br));
	TR1=1;
}

unsigned char rec_serial()
{
	RI=0;
	while(RI==0);
	RI=0;
	return(SBUF);
}
/*
void trans_serial(unsigned char trans)
{
	 TI=0;
	 SBUF=trans;
	 while(TI==0);
	 TI=0;
}

void string_serial(unsigned char *str)	   // function to display string to lcd
{
	 while(*str!='\0')		  		// '\0' is null char as last char of pointer is null
	 {
		 trans_serial(*str);
		 str++;
	 }
}
*/