#include<cstdio>

#define MIN(a,b) (a)<(b)?(a):(b)

long long n,m,k,c,t,ans;

signed main(){scanf("%lld%lld%lld%lld",&n,&m,&k,&c),n--;while(n--){scanf("%lld",&t),ans+=MIN((t-c)*m,k),c=t;}return printf("%lld\n",ans),0;}