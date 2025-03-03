#include<iostream>

#include<cstdio>

#include<algorithm>

#define ll long long

using namespace std;

const int maxn=100+50;

ll n,a,b,f[maxn],ans=0,cnt=0,bif=0,minn=1e15+5;

ll xyz,s[105][105],acl=0;

int main()

{

	for(int i=0;i<100;i++)

	{

		s[i][0]=1;

		for(int j=1;j<=i;j++)

		{

			s[i][j]=s[i-1][j]+s[i-1][j-1];

		}

	}

	cin>>n>>a>>b;

	for(int i=0;i<n;i++)

	{

		cin>>f[i];

	}

	sort(f,f+n);

	for(int i=n-1;i>=n-a;i--)

	{

		ans+=f[i];

		minn=min(minn,f[i]);

	}

	printf("%.6lf\n",(double)ans/a);

	for(int i=n-1;i>=n-a;i--)

	{

		if(minn==f[i])

		{

			acl++;

		}

	}

	if(minn==f[n-1])

	{

		for(int i=0;i<n;i++)

		{

			if(f[i]==f[n-1])

				bif++;

		}

		for(int i=a;i<=b&&i<=bif;i++)

		{

			cnt+=s[bif][i];

		}

		cout<<cnt;

	}

	if(minn!=f[n-1])

	{

		for(int i=0;i<n;i++)

		{

			if(f[i]==minn)

				bif++;

		}

		cnt=s[bif][acl];

		cout<<cnt;

	}

	return 0;

}