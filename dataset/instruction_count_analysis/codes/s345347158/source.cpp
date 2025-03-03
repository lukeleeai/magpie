#include<stdio.h>

#include<algorithm>

using namespace std;

int a[200010];

int main()

{

	int n,i,flag=0;

	scanf("%d",&n);

	for(i=0;i<n;i++)

	{

		scanf("%d",&a[i]);

	}

	sort(a,a+n);

	for(i=0;i<n-1;i++)

	{

		if(a[i]==a[i+1])

		{

			flag=1;

			break;

		}

	}

	if(flag==1)

	{

		printf("NO\n");

	}

	else

	{

		printf("YES\n");

	}

	return 0;

}