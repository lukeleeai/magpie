#include <cstdio>

int main(){

    static long long f[81]={2,1};

    int n; scanf("%d",&n);

    for(int i=2;i<=n;i++) f[i]=f[i-1]+f[i-2];

    printf("%lld\n",f[n]);

}