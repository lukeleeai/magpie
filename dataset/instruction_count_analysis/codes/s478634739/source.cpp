#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

typedef long long ll;

const int maxd = 1e5+10;

ll p[maxd],a[maxd],sum,ans;

int t[maxd],tot,n;

void insert(ll x)

{

    for(int i=1;i<=tot;i++)

        if((x>>t[i])&1)

        {

            if(p[i]) x^= p[i];

            else

            {

                p[i]=x;

                break;

            }

        }

}

int main()

{

    // freopen("a.in","r",stdin);

    // freopen("k.out","w",stdout);

    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    for(int i=1;i<=n;i++) sum ^= a[i];

    for(int i=60;i>=0;i--) if(( (sum>>i)&1) == 0) t[++tot]=i;

    for(int i=1;i<=n;i++) insert(a[i]);

    for(int i=1;i<=tot;i++) 

        if(((ans >>t[i])&1) == 0) ans ^=p[i];

    printf("%lld\n",ans+(sum^ans));





    return 0;

}