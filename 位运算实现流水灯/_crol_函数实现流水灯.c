#include<reg52.h>
#include<intrins.h>
void delay()
{
	int j,k;
	for(j=0;j<=50;j++)
		for(k=0;k<=100;k++);
}
void main()
{
		int i,m;
		while(1)
		{
		m=0x1;
		
		for(i=0;i<=10;i++)
		{
		P2=m;
		m=m<<1;  //值向右移动一位（c语言在这里有规定，不能够直接对P2进行移位，具体原因不清楚的）
		m=m|0x01;//最后一位加或加上“1”
		delay(); }
		m=0x1;
		for(i=0;i<=10;i++)
		{
		P2=m;
		m=m>>1;
		m=m|0x01;
		delay();

		}
		}
		}


