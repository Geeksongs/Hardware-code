  //该板子上的点阵为8*8，只能显示简单的一些汉子，如果要显示真正的汉字
//通过取模软件取的可以选择16*16点阵的板子

#include<reg51.h>
#include<intrins.h>

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

//--定义要使用的IO口--//
#define COMMONPORTS		P0

//--列选通控制--//
unsigned char code TAB[8]  = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

//--点阵字码--//
unsigned char code CHARCODE[6][8]=
{

0x00,0x12,0x14,0x78,0x14,0x12,0x00,0x00,  //大
0x24,0x3e,0x40,0x32,0x04,0x78,0x14,0x22,   //伙 
0x00,0xe9,0xaa,0xac,0xaa,0xe9,0x00,0x00,	//ok
0x00,0x1c,0x08,0x08,0x08,0x08,0x1c,0x00,//I	
0x00,0x00,0x77,0x49,0x41,0x22,0x14,0x08,//心形									
{0x08,0x44,0xdf,0x56,0x4e,0x55,0x4c,0x44}  //你

};
void delay(unsigned int time)
{
  unsigned int i,j;
  for(i=0;i<time;i++)
    for(j=0;j<121;j++);
}
void Hc595SendByte(unsigned char dat)
{
	unsigned char a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;}

void main()
{	
 	unsigned char tab, j;
	unsigned int  i;

	while(1)
	{	
		for(i= 0; i<50; i++ )   //两个字之间的扫描间隔时间
		{
			for(tab=0;tab<8;tab++)
			{	

				Hc595SendByte(0x00);			     //消隐																
				COMMONPORTS	= TAB[tab];				 //输出字码	
				Hc595SendByte(CHARCODE[j][tab]);	
				delay(2);		
			}
			 
		}
		j++;
		if(j == 6)
		{
			j = 0;
		}
	}	
}