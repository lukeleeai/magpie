#include "stdc++.h"

#define ADD(a, b) a = (a + ll(b)) % mod

#define MUL(a, b) a = (a * ll(b)) % mod

#define MAX(a, b) a = max(a, b)

#define MIN(a, b) a = min(a, b)

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)

#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

#define all(a) (a).begin(), (a).end()

#define sz(v) (int)(v).size()

#define pb push_back

#define sec second

#define fst first

#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> pi;

typedef pair<ll, ll> pl;

typedef pair<int, pi> ppi;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef vector<vl> mat;

typedef complex<double> comp;

void Debug() {cout << '\n'; }

template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){

	cout<<arg<<" ";Debug(rest...);}

template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {

	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}

template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){

	out<<"("<<v.first<<", "<<v.second<<")";return out;}

const int MAX_N = 200010;

const int MAX_V = 100010;

const double eps = 1e-6;

const ll mod = 1000000007;

const int inf = 1 << 29;

const ll linf = 1LL << 60;

const double PI = 3.14159265358979323846;

///////////////////////////////////////////////////////////////////////////////////////////////////



int N, K;

ll powK[300010];

ll powS[300010];



void solve() {

	cin >> K >> N;

	if(K % 2 == 0) {

		cout << (K + 1) / 2 << " ";

		rep(i, 0, N - 1) {

			cout << K << " ";

		}

		return;

	}

	memset(powK, -1, sizeof(powK));

	memset(powS, -1, sizeof(powS));



	powK[0] = 1;

	powS[0] = 0;

	rep(i, 1, N + 1) {

		powK[i] = powK[i - 1] * K;

		powS[i] = powS[i - 1] + powK[i];

		if((powS[i] + 1) / 2 > N) break;

	}

	int at = 0, off = 0;

	while(powS[N - at] == -1) {

		cout << (K + 1) / 2 << " ";

		off += (N - at - 1) % 2;

		at++;

	}

	ll m = (powS[N - at] + 1) / 2 - 1 - off;

	while(true) {

		ll xnext = powS[N - at] / K;

		cout << (m / xnext) + 1 << " ";

		m %= xnext;

		if(m == 0) return;

		else m--;

		at++;

	}

}



int main() {

#ifndef LOCAL

	ios::sync_with_stdio(false);

    cin.tie(0);

#endif

    cout << fixed;

	cout.precision(20);

#ifdef LOCAL

    freopen("in.txt", "rt", stdin);

#endif	

	solve();

#ifdef LOCAL

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

#endif

	return 0;

}


