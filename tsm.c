#include<stdio.h>
#include<string.h>
int min=9999;
int dummy[20];
void swap(int a[10],int i,int j)
{
	char temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void tsm(int a[10],int c[4][4],int n)
{
	int k,cost=0;
	for(k=0;k<n-1;k++)
	{
		cost=c[a[k]][a[k+1]]+cost;
	}
	cost=c[a[k]][0]+cost;
	printf("%d\n",cost);
	if(min>=cost)
	{
		min=cost;
		for(k=0;k<n;k++)
		dummy[k]=a[k];
	}
}
void permute(int a[10],int l,int r,int c[4][4])
{
	if(l==r)
	{
		//printf("%s\t",a);
		tsm(a,c,r+1);
	}
	else
	{
		int i;
		for(i=l;i<=r;i++)
		{
			swap(a,l,i);
			permute(a,l+1,r,c);
			swap(a,l,i);
		}
	}
}
void main()
{
	int a[100];
	int n;
	int i,j;
	printf("Enter no of cities:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//printf("Cost Matrix:\n");
/*	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]:",i,j);
			scanf("%d",a[i][j])
		}
	}*/
	int c[4][4]={{0,2,3,6},{2,0,1,3},{3,1,0,2},{6,3,2,0}};
	printf("COST_MATRIX\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	
//	printf("Permutations of \"%s\"\n",a);
	permute(a,0,n-1,c);
	printf("Hamilton path:");
	for(i=0;i<n;i++)
	{
		printf("%d",dummy[i]);
	}
	printf("\n");
	printf("Least Cost:%d",min);
}
