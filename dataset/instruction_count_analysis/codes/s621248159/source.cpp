#include<stdio.h>

int main()

{

	int a,b,n,sum,c,d,i,min=200;

	scanf("%d",&n);

	for(a=1;a<=n/2;a++)

	{   sum=0;

		b=n-a;

		c=a;

		d=b;

		for(i=5;i>0;i--)

		{

		    sum+=c%10;

		    sum+=d%10;

		    c=c/10;

		    d=d/10;

		}

	    if(min>sum)

	    min=sum;

	}

	printf("%d",min);

	return 0;

 } 