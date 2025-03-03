#include<stdio.h>

#include<stdlib.h>

int a[200005],temp[200005];

int inc(const void *a, const void *b)

{

    return *(int*)a-*(int*)b;

}

int main()

{

	int n;

	scanf("%d",&n);

	for(int i=0;i<n;i++)scanf("%d",&a[i]);

	for(int i=0;i<n;i++)temp[i]=a[i];

	qsort(a,n,sizeof(int),inc);

	for(int i=0;i<=n/2-1;i++)

	{

		if(temp[i]>=a[n/2])printf("%d\n",a[n/2-1]);

		else printf("%d\n",a[n/2]);

	}

	for(int i=n/2;i<n;i++)

	{

		if(temp[i]>a[n/2-1])printf("%d\n",a[n/2-1]);

		else printf("%d\n",a[n/2]);

	}

}