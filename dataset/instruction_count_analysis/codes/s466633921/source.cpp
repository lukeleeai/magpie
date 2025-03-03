#include <cstdio>

#include <algorithm>

using namespace std;



const int MAXN = 200005;

int p[MAXN], ord[MAXN];



int main()

{

	int n;

	scanf("%d", &n);

	for (register int i = 1; i <= n; i++)

	{

		scanf("%d", &p[i]);

		ord[p[i]] = i;

	}

	int ans = 0, len = 1;

	for (register int i = 2; i <= n; i++)

		if (ord[i] >= ord[i-1]) len++;

		else ans = max(ans, len), len = 1;

	ans = max(ans, len);

	printf("%d", n - ans);

	return 0;

}