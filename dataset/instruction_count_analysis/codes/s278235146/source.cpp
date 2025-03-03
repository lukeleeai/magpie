#include<cstdio>

#include<algorithm>

using namespace std;



int l, n, m, d[100002], k[10000];



int main() {

  while (scanf("%d", &l), l) {

    int ans = 0;

    scanf("%d%d", &n, &m);

    for (int i = 1; i < n; i++) scanf("%d", &d[i]);

    d[n] = l;

    sort(d, d+n+1);

    for (int i = 0; i < m; i++) scanf("%d", &k[i]);

    for (int i = 0; i < m; i++) {

      if (k[i] == 0) continue;

      int x = lower_bound(d, d+n+1, k[i]) - d;

      int len = min(d[x] - k[i], k[i] - d[x-1]);

      ans += len;

    }

    printf("%d\n", ans);

  }

}


