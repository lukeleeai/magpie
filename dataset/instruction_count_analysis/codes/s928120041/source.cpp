#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define INF (1<<30)

#define INFLL (1ll<<60)

typedef pair<int, int> P;

typedef pair<int, P> E;

#define gt first

#define gc second.first

#define gr second.second

#define MOD (1000000007ll)

#define l_ength size

#define PI 3.14159265358979



void mul_mod(ll& a, ll b){

	a *= b;

	a %= MOD;

}



void add_mod(ll& a, ll b){

	b += MOD;

	a += b;

	a %= MOD;

}



int n;

ll a[2222],memo[2222][2222];

bool done[2222][2222];



ll sgmn(int l, int r){

	if(done[l][r]){

		return memo[l][r];

	}

	done[l][r] = true;

	if(l > r){

		memo[l][r] = min(sgmn(l,n-1),sgmn(0,r));

	}else if(l == r){

		memo[l][r] = a[l];

	}else{

		memo[l][r] = min(sgmn(l,r-1),a[r]);

	}

	return memo[l][r];

}



int main(void){

	int i,j;

	ll x,tmp,ans=INFLL;

	fill(done[0],done[2222],false);

	cin >> n >> x;

	for(i=0; i<n; ++i){

		cin >> a[i];

	}

	for(i=0; i<n; ++i){

		tmp = i * x;

		for(j=0; j<n; ++j){

			tmp += sgmn((j-i+n)%n,j);

		}

		ans = min(tmp,ans);

	}

	cout << ans << endl;

	return 0;

}
