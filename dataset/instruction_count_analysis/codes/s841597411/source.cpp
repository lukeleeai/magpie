#include<stdio.h>

#include<algorithm>

using namespace std; 

int a[100010];

int main()

{

	int n,i;

	scanf("%d",&n);

	for(i=1;i<=n;i++)

	scanf("%d",&a[i]);

	sort(a+1,a+n+1);

	if(n%2!=0) printf("0\n");

	else

	{

		int m=n/2;

		m=a[m+1]-a[m];

		printf("%d\n",m);

	}



}