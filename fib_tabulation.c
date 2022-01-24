#include<stdio.h>
int a[20];
void fib(n)
{
	int i;
	a[0]=0;a[1]=1;
	for(i=2;i<=n;i++)
	a[i]=a[i-2]+a[i-1];
}
void main()
{
	int i,n;
	printf("Enter n to find nth fibonnaci number:\n");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	a[i]=-1;
	fib(n);
	printf("%dth fibonnaci number: %d",n,a[n]);
}
