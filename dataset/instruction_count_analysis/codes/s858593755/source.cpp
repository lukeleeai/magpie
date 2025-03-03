#include "stdc++.h"

#define lowbit(x) ((x) & -(x))



typedef long long ll;

const int N = 100054, Z = N * 2;



ll L;

int n, cnt = 1, d[Z][2];

char s[N];



void append(char *s) {

	char *p = s; int t = 1, id;

	for (; *p; ++p)

		id = *p & 1, t = (d[t][id] ? d[t][id] : (d[t][id] = ++cnt));

}



ll dfs(int t, ll dep) {return t ? dfs(d[t][0], dep - 1) ^ dfs(d[t][1], dep - 1) : lowbit(dep + 1);}



int main() {

	scanf("%d%lld", &n, &L);

	for (int i = 0; i < n; ++i) scanf("%s", s), append(s);

	puts(dfs(1, L) ? "Alice" : "Bob");

	return 0;

}