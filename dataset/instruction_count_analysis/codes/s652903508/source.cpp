#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int INF = (1<<30);

const ll INFLL = (1ll<<60);

const ll MOD = (ll)(1e9+7);

const int zero = 12826;



#define l_ength size



void mul_mod(ll& a, ll b){

	a *= b;

	a %= MOD;

}



void add_mod(ll& a, ll b){

	a = (a<MOD)?a:(a-MOD);

	b = (b<MOD)?b:(b-MOD);

	a += b;

	a = (a<MOD)?a:(a-MOD);

}



ll a[2222],s[2222];



int main(void){

	int n,i,j;

	ll x,tmp,ans=INFLL;

	cin >> n >> x;

	fill(s,s+n,INFLL);

	for(i=0; i<n; ++i){

		cin >> a[i];

	}

	for(j=0; j<n; ++j){

		tmp = x*j;

		for(i=0; i<n; ++i){

			s[i] = min(a[(i-j+n)%n],s[i]);

			tmp += s[i];

		}

		ans = min(ans,tmp);

	}

	cout << ans << endl;

	return 0;

}
