void start()
{
   SDA = 1 ;	   _nop_() , _nop_() , _nop_() ;
   SCL = 1;	       _nop_() , _nop_() , _nop_() ;
   SDA = 0 ;	   _nop_() , _nop_() , _nop_() ;
   SCL = 0 ;	   _nop_() , _nop_() , _nop_() ;
}

void stop()
{
   SDA = 0 ;	   _nop_() , _nop_() , _nop_() ;
   SCL = 1;		   _nop_() , _nop_() , _nop_() ;
   SDA = 1 ;	   _nop_() , _nop_() , _nop_() ;
   SCL = 0 ;	   _nop_() , _nop_() , _nop_() ;
}

void clock()
{
   SCL = 1;		   _nop_() ; _nop_() ; _nop_() ;
   SCL = 0 ;	   _nop_() ; _nop_() ; _nop_() ;
}

void nack()
{
   SDA = 1 ;
   clock() ;
}

void waitack()
{
   SDA = 1 ;
   clock();
}

unsigned char getdat(void)
{
   unsigned char i , dat;
   SDA = 1;		   _nop_() , _nop_() , _nop_();
   for ( i = 0 ; i < 8 ; i++ ) 
   {
       dat = ( ( ( dat << 1 ) & 0xfe ) | SDA );
 	   clock();
   }
   return dat;
}

void opdat(char dat)
{
   unsigned char i ;

   for ( i = 0 ; i < 8 ; i++ )
   {
	  if ( ( dat >> ( 7 - i ) ) & 0x01 )	SDA = 1 ; 
      else	 							  	SDA = 0 ;
      clock() ;     
   }
}

void write_rtc(unsigned char dat1, unsigned char add1)
{
 unsigned char dat;

 dat=( ( ( dat1 / 10 ) << 4 ) | ( dat1 % 10 ) );

 start();
 opdat(0xd0);
 waitack();
 opdat(add1);
 waitack();
 opdat(dat);
 waitack();
 stop();
}

unsigned char read_rtc(unsigned char add)
{
 unsigned char rdata,send;

 start();
 opdat(0xd0);
 waitack();
 opdat(add);
 waitack();
 start();
 opdat(0xd1);
 waitack();
 rdata=getdat();
 nack();
 stop(); 
 send=( ( ( rdata >> 4) * 10 ) + ( rdata & 0x0f ) );
 return(send);
}
void set_rtc(unsigned char sec,unsigned char min,unsigned char hrs,unsigned char day,unsigned char date,unsigned char month,unsigned char year)
{
  sec = sec & 0x7f;
	min = min & 0x7f;
	hrs = hrs & 0x3f;
	day = day & 0x07;
	date = date & 0x3f;
	month = month & 0x1f;
	year = year & 0x7f;
	
   write_rtc(sec,0);
   write_rtc(min,1);
   write_rtc(hrs,2);
   write_rtc(day,3);
   write_rtc(date,4);
   write_rtc(month,5);
   write_rtc(year,6);
}