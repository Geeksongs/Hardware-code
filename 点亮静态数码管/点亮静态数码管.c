#include<reg52.h>
sbit ymq1=P2^2;
sbit ymq2=P2^3;
sbit ymq3=P2^4;
void delay(int x);	  
unsigned char code table[16]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void main()
{	int k,l;
	for(k=0;k<=15;k++){
		for(l=10000;l<=0;l--)
{
	ymq1=0;
	ymq2=0;
	ymq3=0;
	P0=table[k];
	delay(10);
	ymq1=0;
	ymq2=0;
	ymq3=1;
	P0=table[k];
	delay(10);
	ymq1=0;
	ymq2=1;
	ymq3=0;
	P0=table[k];
	delay(10);
	ymq1=0;
	ymq2=1;
	ymq3=1;
	P0=table[k];
	delay(10);
	ymq1=1;
	ymq2=0;
	ymq3=0;
	P0=table[k];
	delay(10);
	ymq1=1;
	ymq2=0;
	ymq3=1;
	P0=table[k];
	delay(10);
	ymq1=1;
	ymq2=1;
	ymq3=0;
	P0=table[k];
	delay(10);
	ymq1=1;
	ymq2=1;
	ymq3=1;
	P0=table[k];
	delay(10); }
	delay(30000);	 }

	}
					  //不知道为何，我的这段程序下载到单片机上老是无法表达出我想要的效果！！！
void delay(int x)
{
	int i,j;
	for(i=x;i>0;i--)
		for(j=50;j>0;j--);
}