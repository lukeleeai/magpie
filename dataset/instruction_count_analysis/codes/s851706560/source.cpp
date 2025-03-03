#include"stdc++.h"

#define ll long long

using namespace std;



int main() {

	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n, k;

	cin>>n>>k;

	vector<ll> a(n+1), pref(n+1);

	for(int i=1; i<=n; ++i) {

		cin>>a[i];

		pref[i]=(pref[i-1]+a[i])%k;

	}

	map<ll, ll> cnt;

	ll ans=0;

	cnt[0]=1;

	if(k==1) {

		cout<<0;

		return 0;

	}

	for(int i=1; i<=n; ++i) {

		if(i>=k) {

			cnt[(pref[i-k]-i%k+k)%k]--;

		}

		ans += cnt[(pref[i]-i%k+k)%k];

		cnt[(pref[i]-i%k+k)%k]++;

	}

	cout<<ans;

}
