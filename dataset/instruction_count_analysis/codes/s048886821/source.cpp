#include <cstdio>

#include <algorithm>

using namespace std;

#define N 100000 + 5



int n, k, seg;

char s[N];



int main()

{

	scanf("%d%d", &n, &k);

	scanf("%s", s);

	for (int i = 0; i < n; i ++)

		seg += (!i || s[i] != s[i - 1]);

	if (seg / 2 <= k)

		printf("%d\n", n - 1);

	else printf("%d\n", n - seg + 2 * k);

	return 0;

}