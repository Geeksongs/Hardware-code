#include <REG52.H>    
#include <INTRINS.H>    
//本例采用89C52, 晶振为12MHZ    
//关于如何编制音乐代码, 其实十分简单,各位可以看以下代码.    
//频率常数即音乐术语中的音调,而节拍常数即音乐术语中的多少拍;    
//所以拿出谱子, 试探编吧!    

sbit Beep =  P1^5; 
   
unsigned char n=0;  //n为节拍常数变量    
unsigned char code music_tab[] ={      0xff,
                    0x48,0x10,0x55,0x10,0x60,0x10,0x55,0x20,0x60,0x20,0xff,0x20,0x60,0x20,
                    0x4c,0x20,0x40,0x20,0x39,0x30,0x40,0x30,0x39,0x30,0x30,0x30,0x30,0x30,
                    0x2b,0x30,0x2b,0x30,0x30,0x30,0x40,0x20,0x48,0x20,0x40,0x20,0x39,0x20,
                    0x40,0x20,0x48,0x20,0x40,0x20,0x39,0x20,0x30,0x20,0x48,0x30,0x00,
};   
   
void int0()  interrupt 1   //采用中断0 控制节拍    
{  TH0=0xd8;   
   TL0=0xef;   
   n--;   
}   
   
void delay (unsigned char m)   //控制频率延时    
{   
 unsigned i=3*m;   
 while(--i);   
}   
   
void delayms(unsigned char a)  //豪秒延时子程序    
{   
  while(--a);                  //采用while(--a) 不要采用while(a--); 各位可编译一下看看汇编结果就知道了!    
}   
   
void main()   
{ unsigned char p,m;   //m为频率常数变量    
  unsigned char i=0;   
  TMOD&=0x0f;   
  TMOD|=0x01;   
  TH0=0xd8;TL0=0xef;   
  IE=0x82;   
play:   
   while(1)   
    {   
    a: p=music_tab[i];   
       if(p==0x00)       { i=0, delayms(1000); goto play;}     //如果碰到结束符,延时1秒,回到开始再来一遍    
       else if(p==0xff)  { i=i+1;delayms(100),TR0=0; goto a;}  //若碰到休止符,延时100ms,继续取下一音符    
            else         {m=music_tab[i++], n=music_tab[i++];}  //取频率常数 和 节拍常数    
             TR0=1;                                             //开定时器1    
           while(n!=0) Beep=~Beep,delay(m);                         //等待节拍完成, 通过P1口输出音频(可多声道哦!)    
       TR0=0;                                             //关定时器1    
    }   
}  