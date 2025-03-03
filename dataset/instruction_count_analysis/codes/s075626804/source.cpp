#include <cstdio>

#define ll long long

#define min(a,b) (a<b?a:b)

#define max(a,b) (a>b?a:b)



ll n,m;



int main(){

    scanf("%lld%lld",&n,&m);

    printf("%lld\n",min(n,m/2)+max(m-n*2,0)/4);

    return 0;

}