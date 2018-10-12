#include<reg52.h>
sbit led1=P2^0;
sbit led2=P2^1;
sbit led3=P2^2;
sbit led4=P2^3;
sbit led5=P2^4;
sbit led6=P2^5;
sbit led7=P2^6;
sbit led8=P2^7;
			 

void delay(int i)
{
	while(i--);
}


void main()
{
	while(1)
	{
		led1=0;
		led2=0;
		led3=0;
		led4=0;
		delay(0,110); //延时的时间我自己说了算！
		led1=1;
		led2=1;
		led3=1;
		led4=1;
		led5=0;
		led6=0;
		led7=0;
		led8=0;
		delay(0,110);
		led5=1;
		led6=1;
		led7=1;
		led8=1; 
	
	}		
}
