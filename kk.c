#include<stdio.h>
#include<math.h>
struct point
{
	int x;
	int y;
};
void sortx(struct point p[20],int start,int end)
{
	int i,j;
	struct point temp;
	for(i=start;i<=end;i++)
	{
		for(j=start;j<end;j++)
		{
			if(p[j].x>p[j+1].x)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	//return p;
}
void sorty(struct point strip[20],int start,int end)
{
	int i,j;
	struct point temp;
	for(i=start;i<=end;i++)
	{
		for(j=start;j<end;j++)
		{
			if(strip[j].y>strip[j+1].y)
			{
				temp=strip[j];
				strip[j]=strip[j+1];
				strip[j+1]=temp;
			}
		}
	}
//	return p;
}
double dist(struct point a,struct point b)
{
	double bb=sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
	return bb;
}
double stripmin(struct point strip[20],int start,int end,double d)
{
	sorty(strip,start,end);
	int s;
	for(s=0;s<=end;s++)
	{
		printf("x:%d y:%d\n",strip[s].x,strip[s].y);
	}
	int i,j;double dmin=9999;
	for(i=start;i<end;i++)
	{
		for(j=i+1;j<=end;j++)
		{
			if((strip[j].y-strip[i].y)<d)
			{
				d=dist(strip[j],strip[i]);
				if(d<=dmin)
				dmin=d;
			}
		}
	}
	return dmin;
}
double bruteforce(struct point c[20],int start,int end)
{
	int i,j;double min=99999;
	double d;
	for(i=start;i<end;i++)
	{
		for(j=i+1;j<=end;j++)
		{
			d=sqrt(pow((c[i].x-c[j].x),2)+pow((c[i].y-c[j].y),2));
			if(min<d)
			min=d;
		}
	}
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
	double d;
	if(end-start<=3)
	{
		d=bruteforce(p,start,end);
	}
	else
	{
		int mid=(start+end)/2;
		double dl,dr;int j,i;
		double d;
		dl=closestpair(p,start,mid,n);
		dr=closestpair(p,mid+1,end,n);
		if(dl<dr)
		d=dl;
		else
		d=dr;
		struct point strip[20];
		j=0;
		for(i=0;i<=end;i++)
		{
			if(abs(p[i].x-p[mid].x)<=d)
			{
				strip[j]=p[i];j++;
			}
		}
		double df=min(d,stripmin(strip,0,j,d));
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
