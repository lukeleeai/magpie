#include<cstdio>

long long x[100005];

long long y[100005];

const long long mod = 1e9+7;

int main(){

    int n,m;

    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++){

        scanf("%lld",&x[i]);

    }

    for(int i=0;i<m;i++){

        scanf("%lld",&y[i]);

    }

    long long sumx = 0;

    for(int i=0, j=n-1;j>i;i++,j--){

        sumx = (sumx + (x[j]-x[i])*(j-i))%mod;

    }

    long long sumy = 0;

    for(int i=0, j=m-1;j>i;i++,j--){

        sumy = (sumy + (y[j]-y[i])*(j-i))%mod;

    }

    printf("%lld\n",(sumx*sumy)%mod);

    return 0;

}
