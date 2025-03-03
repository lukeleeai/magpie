#include <stdio.h>

#include <string.h>

#include <algorithm>

#define Maxn 500005

char s[Maxn];

int n, ans, fail1[Maxn], fail2[Maxn];

void buildFail(char *s, int *fail) {

	int j = fail[0] = -1;

	for (int i = 1; i <= n; ++ i) {

		while (j >= 0 && s[j] != s[i - 1]) j = fail[j];

		fail[i] = ++ j;

	}

}

int main() {

	scanf("%s", s); n = strlen(s);

	buildFail(s, fail1);

	int len = n % (n - fail1[n]) == 0 && (n - fail1[n] <= n / 2) ? n - fail1[n] : -1;

	if (len == -1) return puts("1\n1") & 0;

	if (len == 1) return printf("%d\n1\n", n) & 0;

	puts("2"); std :: reverse(s, s + n);

	buildFail(s, fail2); for (int i = 1; i < n; ++ i)

		if ((!fail1[i] || i % (i - fail1[i])) && (!fail2[n - i] || (n - i) % ((n - i) - fail2[n - i]))) ++ ans;

	printf("%d\n", ans);

	return 0;

}