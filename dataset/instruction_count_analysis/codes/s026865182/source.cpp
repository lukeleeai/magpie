#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

#define int long long

#define maxn (100010)

int n, m, top, s[maxn], cnt[maxn], sum[maxn];



inline int read() {

	int x = 0, f = 1;

	char ch = getchar();

	while (ch < '0' || ch > '9')

		ch == '-' ? f = -1, ch = getchar() : ch = getchar();

	while (ch >= '0' && ch <= '9')

		x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();

	return x * f;

}



void sol(int x, int del) {

//	printf("X %lld %lld\n", x, del);

	if (!x) return;

	int pos = upper_bound(s + 1, s + top + 1, x) - s - 1; // 找到比他大的，然后-1 

//	printf("POS %lld\n", pos);

	if (!pos) sum[1] += del, sum[x + 1] -= del;

	else cnt[pos] += (x / s[pos]) * del, sol(x % s[pos], del);

}



signed main() {

	n = read(), m = read();

	s[++top] = n;

	int x;

	for (int i = 1; i <= m; ++i) {

		x = read();

		while (top && s[top] >= x) --top;

		s[++top] = x;

	}

	cnt[top] = 1;

	for (int i = top; i >= 2; --i) {

		cnt[i - 1] += (s[i] / s[i - 1]) * cnt[i];

//		printf("	%lld %lld %lld\n", s[i] % s[i - 1], cnt[i], i);

		sol(s[i] % s[i - 1], cnt[i]);

	}

//	for (int i = 1; i <= top; ++i) printf("%lld\n", cnt[i]);

	sum[1] += cnt[1], sum[s[1] + 1] -= cnt[1]; // s[1]为最长长度

	for (int i = 1; i <= n; ++i) sum[i] += sum[i - 1];

	for (int i = 1; i <= n; ++i) printf("%lld\n", sum[i]); 

	return 0;

}
