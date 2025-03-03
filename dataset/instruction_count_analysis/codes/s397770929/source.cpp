#include "stdc++.h"

using namespace std;

inline void rd(int &x) {

	char ch; for(;!isdigit(ch=getchar()););

	for(x=ch-'0';isdigit(ch=getchar());)x=x*10+ch-'0';

}

typedef long long LL;

const int MAXN = 300005;

int N, n, a[MAXN], cnt[MAXN];

LL sum[MAXN];

int ans[MAXN];



inline bool chk(int k, int x) {

	int pos = upper_bound(a + 1, a + n + 1, x) - a;

	return sum[pos-1] + 1ll*(n-pos+1)*x >= 1ll*k*x;

}



int main() {

	rd(N);

	for(int i = 1, x; i <= N; ++i) rd(x), ++cnt[x];

	for(int i = 1; i <= 300000; ++i) if(cnt[i]) a[++n] = cnt[i];

	sort(a + 1, a + n + 1);

	for(int i = 1; i <= n; ++i) sum[i] = sum[i-1] + a[i];

	int now = 0;

	for(int k = n; k >= 1; --k) {

		while(now < N && chk(k, now+1)) ++now;

		ans[k] = now;

	}

	for(int i = 1; i <= N; ++i) printf("%d\n", ans[i]);

}