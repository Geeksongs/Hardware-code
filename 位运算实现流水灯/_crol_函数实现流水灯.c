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
		m=m<<1;  //ֵ�����ƶ�һλ��c�����������й涨�����ܹ�ֱ�Ӷ�P2������λ������ԭ������ģ�
		m=m|0x01;//���һλ�ӻ���ϡ�1��
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


