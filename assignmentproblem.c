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
	for(k=0;k<n;k++)
	{
		cost=c[k][a[k]]+cost;
	}
//	cost=c[a[k]][0]+cost;
	printf("\t%d\n",cost);
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
		int k;
		for(k=0;k<=r;k++)
		{
		printf("%d",a[k]);
		}
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
	printf("Enter no of jobes:\n");
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
	int c[4][4]={{5,2,4,8},{6,4,3,5},{5,8,1,8},{3,3,9,7}};
	printf("COST_MATRIX for job assignment:\n");
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
	printf("Job Assignment:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",dummy[i]);
	}
	printf("\n");
	printf("Least Cost:%d",min);
}
