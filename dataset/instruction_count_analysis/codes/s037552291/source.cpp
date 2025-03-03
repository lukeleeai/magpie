#include <iostream>

#include <vector>

#include <deque>

#include <algorithm>

#include <numeric>

#include <string>

#include <cstring>

#include <list>

#include <unordered_set>

#include <tuple>

#include <cmath>

#include <limits>

#include <type_traits>

#include <iomanip>

#include <map>

#include <unordered_map>

#include <queue>

#include <stack>

#include <set>

#include <bitset>

#include <complex>

#include <regex>

#include <random>

using namespace std;



#define rep(i,n)	for(lint i = 0; i < n; i++)

#define repr(i,n)	for(lint i = n - 1; i >= 0; i--)

#define repi(i,ini,n)	for(lint i = ini; i < n; i++)

#define repir(i,ini,n)	for(lint i = n-1; i >= ini; i--)

#define repb(i,start,end)	for(lint i = start; i <= end; i++)

#define repbr(i,start,end)	for(lint i = end; i >= start; i--)



#define bit(n)				(1LL << (n))



#define all(v) v.begin(),v.end()

#define rall(v) v.rbegin(),v.rend()

#define rg(v, ini, end) v.begin() + ini, v.begin()+end



#define ret return 0;

#define chmax(a, b) a=max(a,b)

#define chmin(a, b) a=min(a,b)



using lint = long long;

using ulint = unsigned long long;

using ld = long double;

struct xy {

	lint x, y;

	xy() :x(0), y(0) {}

	xy(lint _x, lint _y) : x(_x), y(_y) {}

	xy operator+(const xy& p) const { return xy(x + p.x, y + p.y); }

	bool operator<(xy p) const { return y == p.y ? x < p.x : y < p.y; }

	bool operator==(xy p) const { return y == p.y && x == p.x; }

};

struct xyd {

	ld x, y;

	xyd() :x(0), y(0) {}

	xyd(long double _x, long double _y) : x(_x), y(_y) {}

};

using vec = vector<lint>;

using vecd = vector<ld>;

using vecs = vector<string>;

using vecp = vector<xy>;

template<class T> using vect = vector<T>;

class vec2 : public vector<vector<lint>>

{

public:

	vec2() {}

	vec2(lint n) : vector(n) {}

	vec2(lint h, lint w) : vector(h, vector<lint>(w)) {}

	vec2(lint h, lint w, lint v) : vector(h, vector<lint>(w, v)) {}

};



template<class T> using priq = priority_queue<T>;

template<class T> using rpriq = priority_queue<T, vector<T>, greater<T>>;

template<class Key, class Val> using hashmap = unordered_map<Key, Val>;

template<class Key> using hashset = unordered_set<Key>;



template<class It>

constexpr typename It::value_type rmax(It begin, It end) {

	return *max_element(begin, end);

}



template<class T1, class T2>

constexpr auto mmax(T1 arg1, T2 arg2) {

	using T = decltype(arg1 + arg2);

	return max(T(arg1), T(arg2));

}



template<class T, class ...Types>

constexpr auto mmax(T arg0, Types ...args) {

	return mmax(arg0, mmax(args...));

}



template<class It>

constexpr typename It::value_type rmin(It begin, It end) {

	return *min_element(begin, end);

}



template<class T1, class T2>

constexpr auto mmin(T1 arg1, T2 arg2) {

	using T = decltype(arg1 + arg2);

	return min(T(arg1), T(arg2));

}



template<class T, class ...Types>

constexpr auto mmin(T arg0, Types ...args) {

	return mmin(arg0, mmin(args...));

}



mt19937 mtrand((random_device())());



const double pi = 3.141592653589793238462;

const lint intmax = 9223372036854775807;

const lint inf = 1100100100100100100LL;



constexpr lint div2(lint p, lint q) {

	return (p + q - 1) / q;

}



#if(__cplusplus < 201703L)

lint gcd(lint a, lint b) {

	while (1) {

		if (a < b) swap(a, b);

		if (!b) break;

		a %= b;

	}

	return a;

}

lint lcm(lint a, lint b) {

	return a / gcd(a, b) * b;

}

#endif



template<class T>

struct nval {

	lint n;		// counts

	T val;

	nval() : n(0) {};

	nval(lint _n, T _val) : n(_n), val(_val) {};

};



template<class It, class It2>

auto spacel(It i, It2 end) {

	return i + 1 == end ? '\n' : ' ';

}



ostream& setp(ostream& ost) {

	cout << setprecision(60) << fixed;

	return ost;

}



//const ulint mod = 1000000007;

const ulint mod = 998244353;

const ld eps = 0.0000001;



struct mint

{

	lint n;

	mint() :n(0) {}

	mint(lint a) { n = (a < 0) ? (mod - ((-a) % mod)) : (a % mod); }

	mint& operator+=(mint a) { (n += a.n) %= mod;			return *this; }

	mint& operator-=(mint a) { ((n += mod) -= a.n) %= mod;	return *this; }

	mint& operator*=(mint a) { (n *= a.n) %= mod;			return *this; }

	mint& operator%=(mint a) { n %= a.n;					return *this; }

	mint& operator++() { (n += 1) %= mod;				return *this; }

	mint& operator--() { (n += (mod - 1)) %= mod;		return *this; }

};



mint operator+(mint a, mint b) { return a += b; }

mint operator-(mint a, mint b) { return a -= b; }

mint operator*(mint a, mint b) { return a *= b; }



vector<mint> invtbl, finvtbl, facttbl;



mint factMod(lint n) {

	if (n == 0) { return 1; }

	mint ans = 1;

	while (n > 1) { ans *= n; n--; }

	return ans;

}

mint powMod(mint x, lint y) {

	if (x.n <= 1) { return x; }

	mint tmp = y > 1 ? powMod(x, y / 2) : 1;

	return tmp * tmp * ((y % 2 == 0) ? 1 : (x));

}

mint modinv(mint n) { return powMod(n, mod - 2); }

void preCalcInv(lint up) {

	invtbl.resize(up + 1);	invtbl[1] = 1;

	repb(a, 2, up)

		invtbl[a] = invtbl[a] = mod - invtbl[mod % a] * (mod / a);

}



mint& operator/=(mint& a, mint b) { a *= (b.n < invtbl.size()) ? invtbl[b.n] : modinv(b); return a; }

mint operator/(mint a, mint b) { return a /= b; }



mint dp[400010], dps[400010];



lint solve() {

	

	lint n, k;

	cin >> n >> k;



	vec l(k), r(k);

	rep(i, k)

		cin >> l[i] >> r[i];



	dp[n + 1] = 1;



	repb(i, 2, n) {

		dps[n + i] = dps[n + i - 1] + dp[n + i - 1];

		rep(j, k) {

			dp[n + i] += dps[n + i - l[j] + 1] - dps[n + i - r[j]];

		}

	}



	cout << dp[n + n].n << endl;



	ret;

}



int main()

{

	lint _ = 1;

	//cin >> _;

	rep(i, _)

		solve();

	return 0;

}
