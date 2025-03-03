#include"stdc++.h"



using namespace std;

typedef long long ll;



const ll MOD = 1e9 + 7;



int cnt[65][2];



int main(){

	memset(cnt,0,sizeof cnt);

	int n; cin >> n;

	for(int i=0; i<n; i++){

		ll x; cin >> x;

		for(int j=0; j<60; j++){

			if(x & ((ll)1 << j)) cnt[j][1]++;

			else cnt[j][0]++;

		}

	}

	ll ans = 0, pw = 1;

	for(int i=0; i<60; i++){

		pw %= MOD;

		ans += pw * (((ll)cnt[i][0] * cnt[i][1]) % MOD);

		ans %= MOD;

		pw *= (ll)2;

	}

	cout << ans << endl;

	return 0;

}