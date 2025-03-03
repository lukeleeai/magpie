#include <cstdio>

#define maxn 100005

using namespace std;



int fa[maxn], dis[maxn];



int find(int x)

{

	if(fa[x] == x) return x;

	int t = fa[x];

	fa[x] = find(fa[x]);

	dis[x] += dis[t];

	return fa[x];

}



int main(int argc, char** argv)

{

	int n, m;

	scanf("%d%d", &n, &m);

	for(int i=0; i<n; i++) fa[i] = i;

	for(int i=0; i<m; i++)

	{

		int l, r, d;

		scanf("%d%d%d", &l, &r, &d);

		int x = find(--l), y = find(--r);

		if(x == y && dis[l] - dis[r] != d)

		{

			puts("No");

			return 0;

		}

		if(x != y)

			fa[x] = fa[y], dis[x] = d + dis[r] - dis[l] + dis[y];

	}

	puts("Yes");

	return 0;

}