#include<reg52.h>
sbit k=P3^2;
sbit led=P2^2;
void delay(int x);
void zhongduan0()
{
  IT0=0;
  EX0=0;
  EA=0;
}

void main()
{
	zhongduan0();
	while(1);
}

void int0() interrupt 0
{
	if(k==0)
	{
	 	delay(1000);
		if(k==0)
		{
			led=1;
			delay(10000);
			led=0;

		}
	
	}
}
void delay(int x)
{
   int i,j;
   for(i=x;i>0;i--)
   	for(j=100;j>=0;j--);
}

