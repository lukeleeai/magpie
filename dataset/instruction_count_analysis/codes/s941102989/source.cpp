#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int maxd = 1e5+10;

int a[maxd],n;

long long b[maxd];

int main()

{

    // freopen("a.in","r",stdin);

    // freopen("k.out","w",stdout);

    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    b[1] = 0ll;

    for(int i=1;i<=n;i++)

    {

        if(i%2) b[1] += a[i];

        else b[1] -= a[i];

    }

    b[1] /=2; a[n] -= b[1];

    for(int i=1;i<n;i++)

        b[i+1] = a[i] - b[i];

    for(int i=1;i<=n;i++)

        printf("%lld ",b[i]*2);

    //printf("%lld",ans);

    return 0;

}