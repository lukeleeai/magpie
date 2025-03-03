#include<stdio.h>

#define maxn 100005

#define inf 0x3f3f3f3f

using namespace std;

typedef long int ll;

ll a[maxn];

int main()

{

    int n, A, B;

    scanf("%d %d %d", &n, &A, &B);

    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

    int C = A - B, l = 0, r = 1e9, ans;

    while (l <= r){

        int m = (l + r) / 2, cnt = 0;

        for (int i = 0; i < n; ++i){

            if ((a[i] - (ll)m * B) <= 0) continue;

            if ((a[i] - (ll)m * B) % C == 0) cnt += (a[i] - (ll)m * B) / C;

            else cnt += (a[i] - (ll)m * B) / C + 1;

            if (cnt > m) break;

        }

        if (cnt > m) l = m + 1;

        else r = m - 1, ans = m;

    }

    printf("%d\n", ans);

    return 0;

}
