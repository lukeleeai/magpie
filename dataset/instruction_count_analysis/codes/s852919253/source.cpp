#include "stdc++.h"

using namespace std;

inline void rd(int &x) {

	char ch; for(;!isdigit(ch=getchar()););

	for(x=ch-'0';isdigit(ch=getchar());)x=x*10+ch-'0';

}

typedef long long LL;

const int MAXN = 300005;

int n, cnt[MAXN];

LL sum[MAXN];

int ans[MAXN];



inline bool chk(int k, int x) { return sum[x] >= 1ll*k*x; }



int main() {

	rd(n);

	for(int i = 1, x; i <= n; ++i) rd(x), ++cnt[x], ++sum[cnt[x]];

	for(int i = 1; i <= n; ++i) sum[i] += sum[i-1];

	int now = 0;

	for(int k = n; k >= 1; --k) {

		while(now < n && chk(k, now+1)) ++now;

		ans[k] = now;

	}

	for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);

}