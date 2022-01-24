#include<stdio.h>
#include<string.h>
void swap(char a[10],int i,int j)
{
	char temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void permute(char a[10],int l,int r)
{
	if(l==r)
	printf("%s\n",a);
	else
	{
		int i;
		for(i=l;i<=r;i++)
		{
			swap(a,l,i);
			permute(a,l+1,r);
			swap(a,l,i);
		}
	}
}
void main()
{
	char a[100];
	printf("Enter string:\n");
	scanf("%s",a);
	printf("Permutations of \"%s\"\n",a);
	permute(a,0,strlen(a)-1);
}
