#include<stdio.h>
int k[20][20];
int max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}
int knapsack(int n,int wt[20],int val[20],int w)
{
	if(n==0 || w<=0)
	k[n][w]=0;
	else if(k[n][w]!=-1)
	return k[n][w];
	else
	{
		if(wt[n-1]<=w)
		k[n][w]=max(val[n-1]+(knapsack(n-1,wt,val,w-wt[n-1])),knapsack(n-1,wt,val,w));
		else
		k[n][w]=knapsack(n-1,wt,val,w);
	}
	return k[n][w];
}
void main()
{
	int i,j,w,n,wt[20],val[20];
	printf("Enter no of items:\n");
	scanf("%d",&n);
	printf("Enter weights of items:\n");
	for(i=0;i<n;i++)
	{
		printf("%d item weight:",i);
		scanf("%d",&wt[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d item value:",i);
		scanf("%d",&val[i]);
	}
	printf("Enter capacity of knapsack:\n");
	scanf("%d",&w);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0)
			k[i][j]=0;
			else if(j==0)
			k[i][j]=0;
			else
			k[i][j]=-1;
		}
 	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			printf("%d ",k[i][j]);
		}
		printf("\n");
	}
	knapsack(n,wt,val,w);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			printf("%d ",k[i][j]);
		}
		printf("\n");
	}
	printf("%d",k[n][w]);
	
}
