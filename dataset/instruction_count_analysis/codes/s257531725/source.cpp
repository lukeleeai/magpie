#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN=1e5+10;

const ll MOD=1e9+7;

ll pri[MAXN],jud[MAXN],phi[MAXN]={0,1},cnt;

ll qpow(ll a,ll b){

    ll res=1,rem=a;

    while(b){

        if(b&1) res=(res*rem)%MOD;

        rem=(rem*rem)%MOD;

        b>>=1;

    }

    return res;

}

void euler(){

    for(ll i=2;i<MAXN;i++){

        if(!jud[i]){

            pri[cnt++]=i;

            phi[i]=(i-1)%MOD;

        }

        for(ll j=0;j<cnt&&i*pri[j]<MAXN;j++){

            jud[i*pri[j]]=1;

            if(i%pri[j]==0){

                phi[i*pri[j]]=phi[i]*pri[j];

                break;

            }

            phi[i*pri[j]]=phi[i]*phi[pri[j]];

        }

    }

}

int main(){

    euler();

    ll n,k;scanf("%lld %lld",&n,&k);

    ll res=0;

    for(ll i=1;i<=k;i++) res=(res+qpow(k/i,n)*phi[i])%MOD;

    printf("%lld\n",res);

    return 0;

}
