#include<reg52.h>
sbit beep=P1^5;
void fun(int x);
void main()
{	int i;
	i=10;
	while(1)
	{
	while(i<=10000000){
	beep=0;
	fun(1);
	beep=1;
	fun(1);
	i++;

	
	}
	fun(1000);
	while(i<=20000000)
	{
	beep=0;
	fun(2);
	beep=1;
	fun(2);
	i++;
	
	
	}
	fun(1000);
	}}
void fun(int x)
{
	int i,j;
	for(i=x;i>0;i--)
		for(j=110;j>0;j--);//不知道为什么我总是无法输出两个不同的音符，这让我感到十分的困惑啊！
}