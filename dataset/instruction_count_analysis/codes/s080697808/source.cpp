#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll x,ll y){

    if(!y)

        return x;

    return gcd(y,x%y);

}

ll n,m;

int main()

{

   // freopen("light.in","r",stdin);

   // freopen("light.out","w",stdout);

    scanf("%lld%lld",&n,&m);

    ll k=n-gcd(n,m);

    printf("%lld\n",k*3);

}