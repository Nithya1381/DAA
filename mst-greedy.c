#include<stdio.h>


/*int min(int n,int visit[],int c[])
{
	int m=n-1,j,k;
	for(k=0;k<n;k++)
	{
		if(c[m]>c[k] && visit[k]==-1)
		{
			m=k;
		
		}
	}
	return m;
}*/
int min(int n,int visit[],int c[])
{
	int m=999,j=0,k;
	for(k=0;k<n;k++)
	{
		if(m>c[k] && visit[k]==-1)
		{
			m=c[k];
			j=k;
		}
	}
	return j;
}
void mst(int visit[],int p[],int c[],int n,int cost[7][7])
{
	int j;
	for(j=0;j<n;j++)
	{
	//	printf("nithya\n");
		int i=min(n,visit,c);
		printf("minimum:%d\n",i);
		visit[i]=1;
		printf("%d\n",i);
		int k=0;
		for(k=0;k<n;k++)
		{
			if(visit[k]==-1 && cost[i][k]!=0)
			{
				if( c[k]>cost[i][k])
				{
					c[k]=cost[i][k];
				//	printf("%d\n",c[k]);
					p[k]=i;
				}
			}
		}
		printf("c matrix\n");
		for(k=0;k<n;k++)
		{
			printf("%d ",c[k]);
		}
		printf("\n");
	}
}
void main()
{
	int n,i,j;
	printf("Enter no of nodes:\n");
	scanf("%d",&n);
//	int visit[20],c[20],p[20],i;
	int visit[7]={-1,-1,-1,-1,-1,-1,-1};
	int c[7]={0,99,99,99,99,99,99};
	int p[7]={-1,-1,-1,-1,-1,-1};
	int cost[7][7]={{0,2,0,4,0,5,0},{2,0,7,1,3,8,4},{0,7,0,0,10,0,6},{4,1,0,0,2,0,0},{0,3,10,2,0,0,0},{5,8,0,0,0,0,1},{0,4,6,0,0,1,0}};
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",cost[i][j]);
		}
		printf("\n");
	}
	int sum=0;
	mst(visit,p,c,n,cost);
	for(i=0;i<n;i++)
	{
		sum=sum+c[i];
	}
	printf("%d\n",sum);
}
