#include<stdio.h>

#include<algorithm>

using namespace std;

int main()

{

	int n,i,b,a[100005];

	while(~scanf("%d",&n))

	{for(i=0;i<n;i++)

	 scanf("%d",&a[i]);

	 sort(a,a+n);

	 printf("%d\n",a[n/2]-a[n/2-1]);

	}

}