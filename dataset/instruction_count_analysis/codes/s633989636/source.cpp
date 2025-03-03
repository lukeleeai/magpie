#include<cstdio>

main(){long long n,ans=0,k=10;scanf("%lld",&n);if(!(n&1)){while(k<=n){ans+=n/k;k*=5;}}printf("%lld\n",ans);}