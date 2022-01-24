#include<stdio.h>
int a[10];
int fib(n)
{
	if(n==0 || n==1)
	a[n]=n;
	else if(a[n]!=-1)
	return a[n];
	else
	a[n]=fib(n-2)+fib(n-1);
	return a[n];
}
void main()
{
	int n,i;
	printf("Enter value of n to know nth fibonacci:\n");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	a[i]=-1;
	printf("%dth fibonacci number: %d",n,fib(n));
}
