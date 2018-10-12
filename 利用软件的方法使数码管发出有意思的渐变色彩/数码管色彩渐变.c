#include<reg52.h>
sbit a=P2^2;
sbit b=P2^3;
sbit c=P2^4;
sbit d=P2^0;
sbit e=P2^1;
sbit f=P2^2;
void delay(int x);
void main(void)
{
	while(1){
	int j,i,k;
		for(j=1;j>=0;j--){
			for(i=1;i>=0;i--){
				for(k=1;k<=500;k++){
	a=j;
	b=i;
	c=1;
	P0=0xfe;
	delay(k);		//最终的结果反正是我失败了。。。并没有编制出一个像样的渐变程序。。。功力不够啊！
			}}}}
	
}
void delay(int x)
{
	int e,f;
	for(e=x;e>0;e--){
		for(f=100;e>0;e--);}
}