#include<cstdio>

#include<algorithm>

#include<iostream>

#include<cstring>

using namespace std;

int n,m;

struct qq

{

	int p,c;

}s[15];

bool ok[15];

int ans;

void check ()

{

	int lalal=0,now=0;

	for (int u=1;u<=n;u++)

	{

		if (ok[u])

		{

			lalal=lalal+s[u].p;

			now=now+u*s[u].p+s[u].c;

		}

	}

	if (now>=m)

	{

		ans=min(ans,lalal);

		return ;

	}

	for (int u=n;u>=1;u--)

	{

		if (ok[u]) continue;

		int t=(m-now);

		int need=t/u;

		if (t%u!=0) need++;

		if (s[u].p>=need)

		{

			lalal=lalal+need;

			ans=min(ans,lalal);

			return ;

		}

		else

		{

			lalal=lalal+s[u].p;

			now=now+u*s[u].p+s[u].c;

		}

		if (now>=m)

		{

			ans=min(ans,lalal);

			return ;

		}

	}

}

void dfs (int x)

{

	if (x>n)	

	{

		check();

		return ;

	}

	ok[x]=true;dfs(x+1);

	ok[x]=false;dfs(x+1);

}

int main()

{

	scanf("%d%d",&n,&m);m/=100;

	ans=(1<<28);

	for (int u=1;u<=n;u++)		

	{

		scanf("%d%d",&s[u].p,&s[u].c);

		s[u].c/=100;

	}

	dfs(1);

	printf("%d\n",ans);

	return 0;

}