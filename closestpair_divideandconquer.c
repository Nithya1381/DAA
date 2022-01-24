#include<stdio.h>
#include<math.h>
struct point
{
	int x;
	int y;
};
void sortx(struct point p[20],int start,int end)
{
	int i,j,temp;
	for(i=start;i<end;i++)
	{
		for(j=start;j<end;j++)
		{
			if(p[j].x>p[j+1].x)
			{
			 
				struct point temp;
				temp=p[j];
				
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}
void sorty(struct point p[20],int start,int end)
{
	int i,j,temp;
	for(i=start;i<end;i++)
	{
		for(j=start;j<end;j++)
		{
			if(p[j].y>p[j+1].y)
			{
				struct point temp;
				temp=p[j];
				
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}
int stripmin(struct point strip[20],int start,int end,double d)
{
	sorty(strip,start,end);
	int i,j;
	double x,dmin=9999;
	for(i=start;i<end;i++)
	{
		for(j=i+1;j<=end;j++)
		{
			if((strip[j].y-strip[i].y)<d)
			{
				//d=dist(strip[j],strip[i]);
				x=sqrt(pow((strip[i].x-strip[j].x),2)+pow((strip[i].y-strip[j].y),2));
				if(x<dmin)
				dmin=x;
			}
		}
	}
	return dmin;
}
double bruteforce(struct point c[20],int start,int end)
{
	int i,j;
	double min=99999;
	double d;
	for(i=start;i<end;i++)
	{
		for(j=i+1;j<=end;j++)
		{
			d=sqrt(pow((c[i].x-c[j].x),2)+pow((c[i].y-c[j].y),2));
			if(min>d)
			min=d;
		}
	}
	printf("min%lf",min);
	return min;
}
double min(double a,double b)
{
	if(a<b)
	return a;
	else return b;
}
double closestpair(struct point p[20],int start,int end,int n)
{
	sortx(p,start,end);
	int i;
	for(i=start;i<=end;i++)
	 printf("(%d,%d) ",p[i].x,p[i].y);
	double d;
	if(end-start<=3)
	{
		d=bruteforce(p,start,end);
		return d;
	}
	else
	{
		int mid=(start+end)/2;
		int dl,dr,d,j,i;
		dl=closestpair(p,start,mid,n);
		dr=closestpair(p,mid+1,end,n);
		if(dl<dr)
		d=dl;
		else
		d=dr;
		struct point strip[20];
		j=0;
		for(i=0;i<n;i++)
		{
			if(abs(p[i].x-p[mid].x)<d)
			{
				strip[j]=p[i];j++;
			}
		}
		int df=min(d,stripmin(strip,0,j,d));
		return df;
	}
}
void main()
{
	struct point p[20];
	int n,i;
	printf("Enter no of point:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter x:");
		scanf("%d",&p[i].x);
		printf("Enter y:");
		scanf("%d",&p[i].y);
	}
	double mind=closestpair(p,0,n-1,n);
	printf("%lf",mind);
}
