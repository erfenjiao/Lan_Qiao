#include<stdio.h>
int f(int x)
{
	for(int i=2;i<x;i++)
	if(x%i==0) return 0;
	return 1;
}
int main()
{
	int sum=1;
	int i,j,k,a,z;
	for(i=2;i<50000;i++)//枚举素数首项 
	if(f(i))//如果是素数 
	{
		for(k=1;k<10000;k++)//枚举公差 
		for(int h=1;h<1000;h++)
		{
			a=i+h*k;
			if(f(a)) sum++; 
			else {sum=1;break;} //如果不是素数就跳出循环，找下一个公差 
			if(sum==10)//当有10个素数的时候，输出公差 
			{
				printf("%d\n",k);
				return 0;
			}	
		}
	}
	return 0;
}
