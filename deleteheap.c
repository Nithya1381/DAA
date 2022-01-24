#include<stdio.h>
void delheap(int a[10],int n,int i)
{
	int l=2*i+1;
	int r=2*i+2,min=-1,temp;
	if(r<n)
	{
		if(a[l]>a[r])
		min=r;
		else
		min=l;
	}
	else if(l<n)
	{
		min=l;
	}
	if(min!=-1)
	{
		printf("%d\t",a[i]);
		a[i]=a[min];
		delheap(a,n,min);	
	}
	else
	{
		a[i]=99;
	}
}
void main()
{
	int a[10]={10,15,16,22,25,23,18};
	int n=7,i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",i);
		delheap(a,n,i);
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}*/
}
