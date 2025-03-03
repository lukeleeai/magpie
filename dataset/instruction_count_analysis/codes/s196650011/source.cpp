#include<iostream>

#include<string>

#include<cstdio>

#include<vector>

#include<cmath>

#include<algorithm>

#include<functional>

#include<iomanip>

#include<queue>

#include<ciso646>

#include<random>

#include<map>

#include<set>

#include<complex>

#include<bitset>

#include<stack>

#include<unordered_map>

#include<utility>

using namespace std;

typedef long long ll;

typedef unsigned int ui;

const ll mod = (ll)1 << 32;

const ll INF = (ll)1000000007 * 1000000007;

typedef pair<int, int> P;

#define stop char nyaa;cin>>nyaa;

#define rep(i,n) for(int i=0;i<n;i++)

#define per(i,n) for(int i=n-1;i>=0;i--)

#define Rep(i,sta,n) for(int i=sta;i<n;i++)

#define rep1(i,n) for(int i=1;i<=n;i++)

#define per1(i,n) for(int i=n;i>=1;i--)

#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)

typedef long double ld;

typedef complex<ld> Point;

const ld eps = 1e-11;

const ld pi = acos(-1.0);

typedef pair<ll, ll> LP;

typedef pair<ld, ld> LDP;

typedef unsigned long long ul;

int k, n;

ll t[1 << 17], d[1 << 17];



priority_queue<LP> q;

priority_queue<LP,vector<LP>,greater<LP>> qq;

int used[1 << 17];

bool vanish[1 << 17];

priority_queue<ll> v[1 << 17];



//100000

const int MAX_N = (1 << 17);

int nn;LP dat[2 * MAX_N - 1];

void init(int n_) {

	nn = 1;

	while (nn < n_)nn *= 2;

	rep(i, 2 * nn - 1)dat[i] = { INF,-1 };

}

void update(int k, ll a) {

	k += nn - 1;

	dat[k] = { a,k - nn + 1 };

	while (k > 0) {

		k = (k - 1) / 2;

		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);

	}

}

LP query(int a, int b, int k, int l, int r) {

	if (r <= a || b <= l)return { INF,-1 };

	if (a <= l && r <= b)return dat[k];

	else {

		LP vl = query(a, b, k * 2 + 1, l, (l + r) / 2);

		LP vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

		return min(vl, vr);

	}

}

int main() {

	cin >> n >> k; init(n+1);

	rep(i, n) {

		cin >> t[i] >> d[i];

		v[t[i]].push(d[i]);

	}

	ll sum = 0; ll num = 0;

	int cnt = 0;

	rep1(i, n) {

		if (!v[i].empty()) {

			ll val = v[i].top(); sum += val;

			qq.push({ val,i });

			v[i].pop();

			num++;

			update(i, val);

			used[i]++;

			while (!v[i].empty()) {

				val = v[i].top(); v[i].pop();

				q.push({ val,i });

			}

			cnt++;

		}

	}

	while (num > k) {

		LP x = qq.top(); qq.pop();

		sum -= x.first; vanish[x.second] = true;

		update(x.second, INF);

		used[x.second]--;

		num--;

		cnt--;

	}

	while (cnt < k) {

		LP x = q.top(); q.pop();

		sum += x.first;

		used[x.second]++;

		ll vval = dat[x.second + nn - 1].first;

		update(x.second, vval + x.first);

		cnt++;

	}

	ll ans = num * num + sum;

	for (ll i = num - 1; i > 0; i--) {

		LP x = query(0, n+1, 0, 0, nn);

		sum -= x.first; cnt -= used[x.second];

		vanish[x.second] = true; update(x.second, INF);

		//cout << cnt << endl;

		while (!q.empty() && cnt<k) {

			LP z = q.top(); q.pop();

			if (vanish[z.second])continue;

			sum += z.first; used[z.second]++;

			ll vval = dat[z.second + nn - 1].first;

			update(z.second, vval + z.first);

			cnt++;

		}

		//cout << sum << endl;

		ans = max(ans,i*i + sum);

	}

	cout << ans << endl;

	//stop

	return 0;

}
