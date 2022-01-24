#include<stdio.h>
#include<math.h>
struct cor
{
	int x;
	int y;
};
void main()
{
	int n;
	printf("Enter no of co-ordinates:\n");
	scanf("%d",&n);
	struct cor c[n];
	printf("Enter x and y co-ordinates:\n");
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Enter x:");
		scanf("%d",&c[i].x);
		printf("Enter y:");
		scanf("%d",&c[i].y);          
	}
	int ind1,ind2,min=9999;
	double d;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			d=sqrt(pow((c[i].x-c[j].x),2)+pow((c[i].y-c[j].y),2));
			if(min>d)
			{
				min=d;
				ind1=i;
				ind2=j;
			}
		}
	}
	printf("Min dist:%d\n",min);
	printf("first co-ordinate:%d\t%d\n",c[ind1].x,c[ind1].y);
	printf("first co-ordinate:%d\t%d\n",c[ind2].x,c[ind2].y);
}
