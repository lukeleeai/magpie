#include"stdc++.h"



using namespace std;

using ll = long long;

int n, m, v, p;

const int maxn = 1e5+7;

vector<ll>a;

ll pre[maxn];

int main()

{

	ios::sync_with_stdio(false);cin.tie(0);

	cin >> n >> m >> v >> p;

	a.resize(n);

	for(auto &u:a){

		cin >> u;

	}

	sort(a.begin(), a.end(), [&](int a, int b){

		return a > b;

	});

	for(int i=0; i<n; ++i){

		pre[i+1] = pre[i]+a[i];

	}

	ll ans = p;

	for(int i=p; i<n; ++i){

		if(a[i]+m<a[p-1])break;

		ll cur = v-(n-(i-p+1));//需要超过的人里的投票数 

		if(cur<=0){//全给不会产生影响的人投票 

			ans++;

			continue;

		}

		if(cur*m<=(i-p+1)*(a[i]+m)-(pre[i]-pre[p-1]))ans++;//需要超过的人里投票 

	}

	cout << ans; 

} 