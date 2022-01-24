 #include<stdio.h>
int max(double a[20],int n)
{
	int m=0,i;
	for(i=0;i<n;i++)
	{
		if(a[m]<a[i])
		m=i;
	}
	return m;
}
void main()
{
	int n,i,m,wt[20],val[20],w;
	double p=0;
	double unit[20];
	printf("Enter no of items:\n");
	scanf("%d",&n);
	printf("Enter each item weight:\n");
	for(i=0;i<n;i++)
	{
		printf("Entem %d item weight:",i);
		scanf("%d",&wt[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("Entem %d item value:",i);
		scanf("%d",&val[i]);
	}
	printf("Enter knapsack capacity:\n");
	scanf("%d",&w);
	for(i=0;i<n;i++)
	unit[i]=(double)val[i]/(double)wt[i];
	
	for(i=0;i<n;i++)
	{
		if(w>0)
		{
			m=max(unit,n);
			if(w>=wt[m])
			{
				p=p+val[m];
				w=w-wt[m];
			}
			else
			{
				p=p+(w*unit[m]);
				w=0;
			}	unit[m]=-1;
		
		}
		//printf("%lf\n",p);
	}
	printf("Maximum value of knapsack: %lf\n",p);
	//printf("%d",w);
	
}
