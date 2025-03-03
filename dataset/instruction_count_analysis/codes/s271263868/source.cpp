#include <cstdio>

#include <algorithm>

using namespace std;

const int N=1e5+5;

int n;

long long d[N],cur[N];

int id[N],sz[N],par[N];

bool cmp(int a,int b){return d[a]>d[b];}

int main()

{

	scanf("%d",&n);

	for (int i=1;i<=n;i++)

	{

		scanf("%lld",&d[i]);

		id[i]=i;

		sz[i]=1;

	}

	sort(id+1,id+n+1,cmp);

	for (int i=1;i<n;i++)

	{

		long long dpar=d[id[i]]+sz[id[i]]-(n-sz[id[i]]);

		for (int j=i+1;j<=n;j++)

			if (dpar==d[id[j]])

			{

				par[id[i]]=id[j];

				cur[id[j]]+=cur[id[i]]+sz[id[i]];

				sz[id[j]]+=sz[id[i]];

			}

			else

				if (dpar>d[id[j]])

					break;

		if (!par[id[i]])

			break;

	}

	if (cur[id[n]]!=d[id[n]])

		printf("-1\n");

	else

		for (int i=1;i<n;i++)

			printf("%d %d\n",id[i],par[id[i]]);

	return 0;

}