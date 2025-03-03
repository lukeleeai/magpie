#include<stdio.h>

#define ll long long

ll min(ll a,ll b){return a<b?a:b;}

int main(){

    ll n, k;

    scanf("%lld%lld",&n,&k);

    printf("%lld\n",min((n%k),k-(n%k)));

    return 0;

}