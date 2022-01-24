#include<stdio.h>
int max(int a,int b)
{
	if(a<b)
	return b;
	else return a;
}
int knapsack(int n,int wt[20],int val[20],int w)
{
	if(n==0 || w<=0)
	return 0;
	else
		if(wt[n-1]<=w)
		return(max(val[n-1]+(knapsack(n-1,wt,val,w-wt[n-1])),knapsack(n-1,wt,val,w)));
		else
		return(knapsack(n-1,wt,val,w));
}
void main()
{
	int i,n,val[20],wt[20],w;
	printf("Enter no of items:\n");
	scanf("%d",&n);
	printf("Enter item weights:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter %dth item weight:",i);
		scanf("%d",&wt[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter %dth item value:",i);
		scanf("%d",&val[i]);
	}
	printf("Enter capacity of knapsack:\n");
	scanf("%d",&w);
	printf("%d",knapsack(n,wt,val,w));
}
