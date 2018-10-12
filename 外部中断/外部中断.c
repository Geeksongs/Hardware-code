#include<reg52.h>
sbit k=P3^2;
sbit k2=P2^2;
sbit k3=P2^3;
sbit k4=P2^4;
sbit k5=P2^5;
sbit k6=P2^6;
sbit k7=P2^7;
sbit k222=P3^3;
typedef unsigned int u16;	  
typedef unsigned char u8;

void zhongduan()
{
	EA=1;
	EX0=1;
	IT0=1;

}

void delay(u16 i)
{
	while(i--);	
}

void main()
{
	
	zhongduan();
	while(1);
}
void Int1() interrupt 0
{
	 		
	  delay(2000);
	  if(k==0)
	  	{
		while(1)
		{

		k7=1;
		k2=0;
		delay(400000);
		k2=1;
		k3=0;
		delay(400000);
		k3=1;
		k4=0;
		delay(400000);
		k4=1;
		k5=0;
		delay(400000);
		k5=1;
		k6=0;
		delay(400000);
		k6=1;
		k7=0;
		delay(400000);
	  	}}
}
void Int2() interrupt 2
{

	  delay(2000);
	  if(k222==0)
	  {
	   k2=1;


	  }
}
