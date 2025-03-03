#include<iostream>

#include<cstdio>

using namespace std;

int a[201000];long long ans=0;

int main()

{

	int n;scanf("%d",&n);

	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	if(a[1]!=0)return 0*puts("-1");

	int now=0;

	for(int i=n;i>=2;i--)

	{

		if(a[i]<now)return 0*puts("-1");

		else if(a[i]==now){if(a[i]!=0)now--;}

		else now=a[i]-1,ans+=a[i];

	}

	if(now!=0)return 0*puts("-1");

	printf("%lld",ans);return 0;

}