#include<stdio.h>

#include<algorithm>

using namespace std;

int main()

{

	int i,n,a[100005],temp=1;

	long long sum;

	scanf("%d",&n);

	for(i=0;i<n;i++)

	 scanf("%d",&a[i]);

	sort(a,a+n);

	sum=(long long)a[0];

	for(i=1;i<n;i++)

	{

		if(sum*2<(long long)a[i])

		{

		   temp=1;

		   sum+=(long long)a[i];

		}

		else

		{

			temp++;

			sum+=(long long)a[i];

		}	

	}

   printf("%d\n",temp);

}