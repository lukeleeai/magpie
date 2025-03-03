#include"stdc++.h"

using namespace std;

#define ll long long



const ll MOD = 1e9+7;

ll n, m, ans = 1, cnt=0, tot=0, sum[100050];



void getprime(){

	for(ll i = 2; i <= m; i++){

		if(m % i == 0){

			m /= i;

			sum[++cnt]++;

			while(m % i == 0)  

				m /= i, sum[cnt]++;

			tot += sum[cnt];

		}

	}

	if(m != 1) sum[++cnt] = 1, tot++;

}



ll inv(ll x){

    return x==1 ? 1 : (MOD-MOD/x)*inv(MOD%x)%MOD;

}

ll C(ll n,ll m){

    if(m<0 || n<m) return 0;

    if(m > n-m)  m = n-m;

    ll zi = 1, mu = 1;

    for(ll i = 0; i < m; i++){

        zi = zi *(n-i) %MOD;

        mu = mu *(i+1) %MOD;

    }

    return zi*inv(mu)%MOD;

}



int main(){

	scanf("%lld%lld",&n, &m);

	getprime();

	for(ll i = 1; i <= cnt; i++){

		ans *= C(sum[i]+n-1, n-1);

		ans %= MOD;

	}

	printf("%lld", ans);

	return 0;

} 