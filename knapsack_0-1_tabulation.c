#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
	return a;
	else return b;
}
void main()
{
	int i,j,wt[20],val[20],n,w;
	printf("Enter no of items:\n");
	scanf("%d",&n);
	printf("Enter weights of each item:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter item weight: ");
		scanf("%d",&wt[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter item value: ");
		scanf("%d",&val[i]);
	}
	printf("Enter knapsack capacity:\n");
	scanf("%d",&w);
	int k[n+1][w+1];
	for(i=0;i<=n;i++)
	{
		k[i][0]=0;
	}
	for(i=0;i<=w;i++)
	{
		k[0][i]=0;	
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=w;j++)
		{
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
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(wt[i-1]<=j)
			k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
			else 
			k[i][j]=k[i-1][j];
		}
	}
	printf("Tabulation Method\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			printf("%d ",k[i][j]);
		}
		printf("\n");
	}
	
	printf("Maximum value of knapsack %d",k[n][w]);
}
