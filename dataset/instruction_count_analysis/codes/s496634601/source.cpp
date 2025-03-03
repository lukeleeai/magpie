#include <iostream>

#include <cstring>

#include <cstdio>

#include <algorithm>

#include <cmath>

using namespace std;

#define ll long long

#define maxn 210000

#define mod 1000000007

const int m=1e9+7;

ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}

ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p%mod;p=p*p%mod;q>>=1;}return f;}

int n,k,t,h,w,a,b;

ll fac[maxn],inv[maxn];

void init()

{

    fac[0]=1;

    for(int i=1;i<=maxn-10;i++)fac[i]=fac[i-1]*i%mod;

    inv[maxn-10]=qpow(fac[maxn-10],mod-2);

    for(int i=maxn-11;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;

}

ll C(int x,int y)

{

    return fac[x]*inv[y]%mod*inv[x-y]%mod;

}

int main()

{

    //freopen("de.txt","r",stdin);

    init();

    while (~scanf("%d%d%d%d",&h,&w,&a,&b)){

        ll ans=C(h+w-2,h-1);

        for (int i=0;i<b;++i){

            ll temp1=C(i+h-1-a,i);

            ll temp2=C(w-i+a-2,a-1);

            ll temp3=(temp1*temp2)%mod;

            ans=(ans-temp3+mod)%mod;

        }

        printf("%I64d\n",ans);

    }

    return 0;

}
