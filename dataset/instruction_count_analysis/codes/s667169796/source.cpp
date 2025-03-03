#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 100100;

ll q[N],f[N],tag[N],x;

int n,Q,tail;

void solve(ll d,ll v) {

    if(d==0) return ;

    int j=upper_bound(q+1,q+tail+1,d)-q-1;

    if(j==0) tag[1]+=v,tag[d+1ll]-=v;

    else f[j]+=d/q[j]*v,solve(d%q[j],v);

}

int main() {

    scanf("%d%d",&n,&Q);

    q[++tail]=(ll)n;

    for(int i=1;i<=Q;i++) {

        scanf("%lld",&x);

        while(tail&&q[tail]>=x) tail--;

        q[++tail]=x;

    }

    f[tail]=1;

    for(int i=tail;i>1;i--) {

        f[i-1]+=q[i]/q[i-1]*f[i];

        solve(q[i]%q[i-1],f[i]);

    }

    tag[1]+=f[1],tag[q[1]+1ll]-=f[1];

    for(int i=1;i<=n;i++) tag[i]+=tag[i-1],printf("%lld\n",tag[i]);

}