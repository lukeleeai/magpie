#include<stdio.h>

#include<algorithm>

#define maxn 200005

#define inf 0x3f3f3f3f

using namespace std;

typedef long int ll;

int main()

{

    int n, t, x;

    long long ans = 0;

    scanf("%d %d", &n, &t);

    if (t) return 0 & puts("-1");

    while(--n){

        scanf("%d", &x);

        if (x <= t) ans += x;

        else if (x == t + 1) ++ans;

        else return 0 & puts("-1");

        t = x;

    }

    printf("%lld\n", ans);

    return 0;

}
