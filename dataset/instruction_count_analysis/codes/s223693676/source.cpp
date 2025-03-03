#include<stdio.h>

#include<stdlib.h>

int a[100005];

int inc(const void *a, const void *b)

{

    return *(int *)a-*(int *)b;

}

int main()

{

	int n,m,min=-1;

	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++)scanf("%d",&a[i]);

	qsort(a,n,sizeof(int),inc);

	for(int i=0;i<=(n-m);i++)

	{

		if(min==-1)min=a[i+m-1]-a[i];

		if(min>a[i+m-1]-a[i])min=a[i+m-1]-a[i];

	}

	printf("%d\n",min);

}