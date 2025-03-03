#include<stdio.h>

int main()

{

	int a[200];

	int x,n;

	scanf("%d %d",&n,&x);

	int i;

	for(i=0;i<n;i++)

	scanf("%d",&a[i]);

	int sum=0;

	int d=0;

	for(i=0;i<n;i++)

	{

	d+=a[i];

	if(d<=x)

	{

		sum++;

	}

	}

	printf("%d",sum+1);

	

}