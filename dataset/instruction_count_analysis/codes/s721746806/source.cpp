#include "bits/stdc++.h"



using namespace std;

using ll = long long;

const double pi = acos(-1);

#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)

#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)

#define REP(i,n) FOR(i,0,n)

#define RREP(i,n) RFOR(i,0,n)

#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME

#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)

#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {

	REP(i, v.size()) { if (i)os << " "; os << v[i]; }return os;

}

template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {

	REP(i, v.size()) { if (i)os << endl; os << v[i]; }return os;

}



const ll INF = 1LL << 60;

ll MOD = 1000000007;

ll _MOD = 1000000009;

double EPS = 1e-10;



#define int long long



inline void my_io() {



	std::ios::sync_with_stdio(false);



	std::cin.tie(0);



	cout << fixed << setprecision(10);



}



signed main() {

	ll n, k, ans;

	ll sum = 0;

	

	cin >> n >> k;



	vector<pair<ll, ll>> v(n, make_pair((ll)0, (ll)0));

	set<ll> s;

	stack<ll> st;



	REP(i, n) {

		cin >> v[i].second >> v[i].first;

	}



	sort(v.begin(), v.end(), greater<pair<ll,ll>>());



	REP(i, k) {

		sum += v[i].first;

		if (s.count(v[i].second)) {

			st.push(v[i].first);

		}

		s.insert(v[i].second);

	}



	ans += sum + s.size() * s.size();



	FOR(i, k, n) {

		if (st.empty()) {

			break;

		}

		if (s.count(v[i].second)) {

			continue;

		}

		sum -= st.top();

		sum += v[i].first;

		s.insert(v[i].second);

		ans = max(ans, sum + (ll)s.size() * (ll)s.size());

		st.pop();

	}



	cout << ans << endl;

}
