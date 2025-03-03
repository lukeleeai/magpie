#include"stdc++.h"

#define int long long 

using namespace std;

const int maxn=2e5+10;

set<int>s[maxn];

int n,k,a[maxn],b[maxn],cnt,tot;

main()

{

	scanf("%lld%lld",&n,&k);

	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s[a[i]].insert(i);

	int now=1;

	while(b[now]==0)

	{

		b[now]=++cnt;

		set<int>::iterator it=s[a[now]].upper_bound(now);

		if(it!=s[a[now]].end())

		{

			now=*it+1;

			if(now==n+1)now=1,tot++;

		}

		else

		{

			it=s[a[now]].upper_bound(0);

			now=*it+1;

			tot++;

		}

	}

//	printf("%lld\n",tot);

	k%=tot;

	now=1;

	if(k==0)return 0;

	while(k!=1)

	{

		set<int>::iterator it=s[a[now]].upper_bound(now);

		if(it!=s[a[now]].end())

		{

			now=*it+1;

			if(now==n+1)now=1,k--;

		}

		else

		{

			it=s[a[now]].upper_bound(0);

			now=*it+1;

			k--;

		}

//		printf("%lld\n",now);

	}

//	puts("!");

	for(;now<=n;now++)

	{

		set<int>::iterator it=s[a[now]].upper_bound(now);

		while(it!=s[a[now]].end())

		{

			now=*it+1;

			if(now==n+1)

			{

				now=1,k--;

				return 0;

			}

			it=s[a[now]].upper_bound(now);

		}

		printf("%lld ",a[now]);

	}

}

/*

5 10

1 2 3 2 3

*/