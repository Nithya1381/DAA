#include<stdio.h>
struct chull
{
	int x;
	int y;
};
void main()
{
	int i,j,f1=1,f2=1,n,k,a,b,d,x;
	printf("Enter no of points:\n");
	scanf("%d",&n);
	struct chull c[n];
	for (i=0;i<n;i++)
	{
		printf("Enter x:");
		scanf("%d",&c[i].x);
		printf("Enter y:");
		scanf("%d",&c[i].y);
	}
	for(i=0;i<n-1;i++)
	{	
		for(j=i+1;j<n;j++)
		{
			a=c[j].y-c[i].y;
			b=c[i].x-c[j].x;
			d=(c[i].x*c[j].y)-(c[i].y*c[j].x);
			f1=1;f2=1;count=0;
			for(k=0;k<n;k++)
			{
				if(k!=i && k!=j)
				{
					x=(a*c[k].x)+(b*c[k].y);
					//if(x==d)
					//count++;
					if(x<d)
					f1++;
					else
					f2++;
				}
			}
			if(f1==1 || f2==1)
			{
				printf("%d %d\t",c[i].x,c[i].y);
				printf("%d %d\n",c[j].x,c[j].y);
			}
		/*	if(f1+count==n-2 || f2+count==n-2)
			{
				printf("%d %d\t",c[i].x,c[i].y);
				printf("%d %d\n",c[j].x,c[j].y);
			}*/
		}
		
	}
}
