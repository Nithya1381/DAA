#include<stdio.h>
#include<math.h>
long int size(long int n)
{
	long int c=0;
	while(n!=0)
	{
		n=n/10;
		c++;
	}
	return c;
}
long int max(long int a,long int b)
{
	if(a<=b)
	return b;
	else return a;
}
long int multiply(long int n1,long int n2)
{
	if(n1<10 || n2<10)
	return n1*n2;
	else
	{
		long int n=max(size(n1),size(n2)),nd,a1,a0,b1,b0,c2,c1,c0;
		nd=n/2;
		a1=n1/( long int)(pow(10,nd));
		a0=n1%((long int)pow(10,nd));
		b1=n2/(long int)(pow(10,nd));
		b0=n2%(long int)pow(10,nd);
		c2=multiply(a1,b1);
		c0=multiply(a0,b0);
		c1=multiply((a0+a1),(b0+b1))-(c2+c0);
		//printf("%d*%d=%d\n",n1,n2,(c2*(int)pow(10,2*nd)+c1*(int)pow(10,nd)+c0));
		return (c2*(long int)pow(10,2*nd)+c1*(long int)pow(10,nd)+c0);
	}
}
void main()
{
	long int n1,n2;
	printf("Enter number1:\n");
	scanf("%ld",&n1);
	printf("Enter number2:\n");
	scanf("%ld",&n2);
	long int val=multiply(n1,n2);
	printf("%ld",val);
}
