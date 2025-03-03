#include <cstdio>

#define mod 998244353

#define max(a,b) ((a)>(b)?(a):(b))

struct interval{

    int l,r;

}a[200003];

long long f[200003]={0,1},s[200003]={0,1};

int n,k;

int main(){

    scanf("%d%d",&n,&k);

    for(int i=1;i<=k;i++) scanf("%d%d",&a[i].l,&a[i].r);

    for(int i=2;i<=n;i++){

        for(int j=1;j<=k;j++){

            if(i>a[j].l) f[i]=(f[i]+(s[i-a[j].l]-s[max(i-a[j].r-1,0)])%mod)%mod;

        }

        s[i]=(s[i-1]+f[i])%mod;

    }

    printf("%lld\n",(f[n]+mod)%mod);

    return 0;

}