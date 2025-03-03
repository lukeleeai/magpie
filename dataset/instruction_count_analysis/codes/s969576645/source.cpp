#include       <set>

#include       <map>

#include     <queue>

#include     <cmath>

#include    <cstdio>

#include    <cctype>

#include    <vector>

#include   <cstring>

#include <algorithm>

using namespace std;



typedef long long ll;

const ll mod = 1e9+7;

const double eps = 1e-7;

const int maxn = 1e5+5;



ll fast_pow(ll a,ll b,ll mod){

    ll ans = 1;

    while(b){

        if(b&1)

            ans = ans*a%mod;

        a = a*a%mod;

        b>>=1;

    }

    return ans;

}



int main(){

    ll n, m;

    ll a, x=0, y=0;

    scanf("%lld%lld",&n,&m);



    for(int i=1;i<=n;i++){

        scanf("%lld",&a);

        x = (x+(2*i-n-1)*a)%mod;

    }

    for(int i=1;i<=m;i++){

        scanf("%lld",&a);

        y = (y+(2*i-m-1)*a)%mod;

    }

    printf("%lld\n",x*y%mod);

    return 0;

}



/*



1592794101

989097785





232162543



*/
