#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN=110000;

int t[MAXN];

int main()

{

//	freopen("A.in", "r", stdin);

//	freopen("A.out", "w", stdout);

	int n, c, k;

	scanf("%d%d%d", &n, &c, &k);

	for (int i=1; i<=n; i++) scanf("%d", &t[i]);

	sort(t+1, t+n+1);

	int ans=0;

	for (int i=1, j; i<=n; i++, i=j)

	{

		ans++; j=i;

		for (int p=0; j<=n&&p<c&&t[i]+k>=t[j]; j++) p++;

	}

	printf("%d\n", ans);

	return 0;

}