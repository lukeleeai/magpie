#include"stdc++.h"

using namespace std;

long long d[100005];

int n,m;

bool vis[100005],use[100005];

vector<int>v[100005];

vector<int>e[100005];

void read(int& x)

{

	char c=getchar();

	x=0;

	while(c<'0'||c>'9')c=getchar();

	while(c>='0'&&c<='9')

	{

		x=x*10+c-'0';

		c=getchar();

	}

}

bool dfs(int fa)

{

	vis[fa]=1;

	use[fa]=1;

	for(int i=0;i<v[fa].size();i++)

	{

		int y=v[fa][i];

		int z=e[fa][i];

		if(d[y]>d[fa]+z)

		{

			if(vis[y])return 1;

			d[y]=d[fa]+z;

			if(dfs(y))return 1;

		}

	}

	vis[fa]=0;

	return 0;

}

int main()

{

	read(n);

	read(m);

	for(int i=1;i<=n;i++)

	{

		d[i]=200000000000ll;

	}

	for(int i=1;i<=m;i++)

	{

		int x,y,z;

		read(x);

		read(y);

		read(z);

		v[x].push_back(y);

		e[x].push_back(z);

		v[y].push_back(x);

		e[y].push_back(-z);

	}

	bool ok=0;

	for(int i=1;i<=n;i++)

	{

		if(!use[i])

		{

			d[i]=0;

			if(dfs(i))

			{

				ok=1;

			}

		}

	}

	if(ok)printf("No\n");

	else printf("Yes\n");

	return 0;

}