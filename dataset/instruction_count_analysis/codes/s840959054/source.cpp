#include <cstdio>

#include <cstring>

#define maxn 200010

#define N maxn / 26 + 10

char s[maxn];

int l[N], r[N];

int cnt[26];

int sum[maxn][26], nxt[maxn][26];

int n, m, sz, ans;

char find(int r, int l = 0) {

	for (int i = 0; i < 26; i++) if (!(sum[r][i] - sum[l][i])) return i + 97;

	return 20040826;

}

int main() {

	sz = sizeof cnt;

	scanf("%s", s + 1);

	n = strlen(s + 1);

	int num = 0; r[m = 1] = n;

	for (int i = n; i; i--) {

		memcpy(nxt[i], nxt[i + 1], sz);

		int x = s[i] - 'a';

		nxt[i][x] = i;

		num += cnt[x]++ == 0;

		if (num >= 26) {

			l[m] = i;

			r[++m] = i - 1;

			memset(cnt, 0, sz);

			num = 0;

		}

	}

	for (int i = 1; i <= n; i++) {

		memcpy(sum[i], sum[i - 1], sz);

		sum[i][s[i] - 'a']++;

	}

	putchar(ans = find(r[m]));

	for (int i = m - 1; i; i--) putchar(ans = find(r[i], nxt[l[i]][ans - 'a']));

	putchar(10);

	return 0;

}

 