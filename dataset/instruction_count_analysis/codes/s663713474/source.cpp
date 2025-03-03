#include <iostream>

#include <cstring>

using namespace std;

long long a[401000],stack[401000],l[401000],r[401000],s[401000];

int main()

{

	long long n;

	cin>>n;

	for(long long i=1; i<=n; i++)

	{

		cin>>a[i];

		s[i]=s[i-1]+a[i];

	}

	

	long long top=0;

	for(long long i=1; i<=n; i++)

	{

		while(top&&a[i]<=a[stack[top]])

		{

			top--;

		}

		l[i]=stack[top]+1;

		top++;

		stack[top]=i;

	}

	memset(stack,0,sizeof(stack));

	top=0;

	for(long long i=n; i>=1; i--)

	{

		while(top&&a[i]<=a[stack[top]])

		{

			top--;

		}

		r[i]=stack[top]-1;

		top++;

		stack[top]=i;

	}

	long long ans=0;

	for(long long i=1; i<=n; i++)

	{

		long long left=l[i],right=r[i];

		if(right==-1) right=n;

		ans+=(i-left+1)*a[i]*(right-i+1);

	}

	cout<<ans;

	return 0;

}