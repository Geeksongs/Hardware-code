#include<reg52.h>
sbit led=P2^0;
void delay(int x);
void main()
{
	while(1)
	{
	led=0;
	delay(30000);
	led=1;
	
}	 
}
void delay(int x)
{
	int i,j;
	for(i=x;i>0;i--)
		for(j=110;j>0;j--);	//���ڣ��Լ���һ����ʱ�����������д���ˣ�������
}