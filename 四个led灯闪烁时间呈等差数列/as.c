#include<reg52.h>
sbit led1=P2^0;
sbit led2=P2^1;
sbit led3=P2^2;
sbit led4=P2^3;			 
typedef unsigned int u16;	
typedef unsigned char u8;

		 


void delay(u16 i)
{
	while(i--);	
}


void main()
{
	while(1)
	{
		led1=0;
		delay(8000); //¥Û‘º—” ±450ms
		led1=1;
		delay(8000); 
		led2=0;
		delay(8000);
		led2=1;
		delay(8000);
		led3=0;
		delay(8000);
		led3=1;
		delay(8000);
		led4=0;
		delay(8000);
		led4=1;
		delay(8000);
		led3=0;
		delay(8000);
		led3=1;
		delay(8000);
	}		
}

