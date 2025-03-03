#include<cstdio>

#include<cstdlib>

int n;

long long int sum,min,x;

int a[200000];

int main()

{

	scanf("%d",&n);

	for(int i=0;i<n;i++)

	  scanf("%d",&a[i]);

	for(int i=0;i<n;i++)

	  sum+=a[i];

	min=labs(sum-2*a[0]);

	for(int i=0;i<n-1;i++)

	{

		x+=a[i];

		if(labs(sum-2*x)<min)

		  min=abs(sum-2*x);

	}

	printf("%d\n",min);

	return 0;

}