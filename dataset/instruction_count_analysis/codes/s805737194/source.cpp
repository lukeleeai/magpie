#include<cstdio>

#include<iostream>

using namespace std;

int n;

int B,W;

int a[300050];

int s[300050];

bool judge(int x)

{

	int mn=0;

	if(s[n]>=x) return 1;

	for(int i=2;i<=n;++i)

	{

		if(s[i-1]-mn>=x)

		{

			if(s[n]-s[i]>=x) return 1;

			mn=min(mn,s[i]);

		}

	}

	return 0;

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;++i)

	{

		scanf("%d",&a[i]);

		if(i&1)

		{

			B+=a[i];

			s[i]=s[i-1]+a[i];

		}

		else

		{

			W+=a[i];

			s[i]=s[i-1]-a[i];

		}

	}

	if(~n&1)

	{

		printf("%d %d\n",max(B,W),min(B,W));

		return 0;

	}

	int l=0,r=B,re=-1;

	while(l<=r)

	{

		int mid=(l+r)>>1;

		if(judge(mid)) l=mid+1,re=mid;

		else r=mid-1;

	}

	int an=max(B,W+re);

	printf("%d %d\n",an,B+W-an);

	return 0;

}