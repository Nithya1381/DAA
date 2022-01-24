#include<stdio.h>
#include<string.h>
void main()
{
	char s1[20];
	char s2[20];
	printf("Enter main string:\n");
	scanf("%s",s1);
	printf("Enter search string:\n");
	scanf("%s",s2);
	int m=strlen(s1),n=strlen(s2);
	int i,j,f=0;
	for(i=0;i<m+n-1;i++)
	{
		for(j=i;j<i+n;j++)
		{
			if(s1[j]!=s2[j-i])
			{
				break;
			}
		}
		if(j==i+n)
		{
			f=1;
			printf("Pattern found\n");
		}
	}
	if(f==0)
	printf("Pattern not found\n");
	//printf("%d\t%d",m,n);
}
