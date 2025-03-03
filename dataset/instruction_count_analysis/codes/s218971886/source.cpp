#include <cstdio>

main(){int n;while(scanf("%d", &n), n){int t, m = 0, p, a, b;for(;n;n--){scanf("%d%d%d",&p,&a,&b);if(a+b>m)t=p,m=a+b;}printf("%d %d\n",t,m);}}