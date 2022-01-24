#include<stdio.h>
#include<string.h>
int min=9999;
char dummy[20];
void swap(char a[10],int i,int j)
{
	char temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void tsm(char a[10],int c[4][4])
{
	int k,cost=0;
	for(k=0;k<3;k++)
	{
		int x=(int)(a[k])-48,y=(int)(a[k+1])-48;
		cost=c[x][y]+cost;
	}
	cost=c[(int)a[k]-48][0]+cost;
	if(min>=cost)
	{
		min=cost;
		strcpy(dummy,a);
	}
}
//char hamil[10];
void permute(char a[10],int l,int r,int c[4][4])
{
	if(l==r)
	{
		printf("%s\t",a);
		tsm(a,c);
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
	char a[100];
	printf("Enter string:\n");
	scanf("%s",a);
	int n=strlen(a);
	int i,j;
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
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	printf("Permutations of \"%s\"\n",a);
	permute(a,1,strlen(a)-1,c);
	printf("%d %s",min,dummy);
}
