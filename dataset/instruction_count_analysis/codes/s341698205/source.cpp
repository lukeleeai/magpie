#include "bits/stdc++.h"

//#include "stdc++.h"

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#include <iostream>

#include <stdio.h>

#include <algorithm>

#include <math.h>

#include <vector>

using namespace std;

typedef long long ll;

typedef pair <ll, ll > pll;



bool comp(const pll& a, const pll& b) {

	return a.first < b.first;

}

std::vector<int> enum_div(int n)//nの約数を列挙

{

	std::vector<int> ret;

	for (int i = 1; i * i <= n; ++i)

	{

		if (n % i == 0)

		{

			ret.push_back(i);

			if (i != 1 && i * i != n)

			{

				ret.push_back(n / i);

			}

		}

	}

	return ret;

}

const int mod = 1000000007;

struct mint {

	ll x; // typedef long long ll;

	mint(ll x = 0) :x((x% mod + mod) % mod) {}

	mint& operator+=(const mint a) {

		if ((x += a.x) >= mod) x -= mod;

		return *this;

	}

	mint& operator-=(const mint a) {

		if ((x += mod - a.x) >= mod) x -= mod;

		return *this;

	}

	mint& operator*=(const mint a) {

		(x *= a.x) %= mod;

		return *this;

	}

	mint operator+(const mint a) const {

		mint res(*this);

		return res += a;

	}

	mint operator-(const mint a) const {

		mint res(*this);

		return res -= a;

	}

	mint operator*(const mint a) const {

		mint res(*this);

		return res *= a;

	}

	mint pow(ll t) const {

		if (!t) return 1;

		mint a = pow(t >> 1);

		a *= a;

		if (t & 1) a *= *this;

		return a;

	}



	// for prime mod

	mint inv() const {

		return pow(mod - 2);

	}

	mint& operator/=(const mint a) {

		return (*this) *= a.inv();

	}

	mint operator/(const mint a) const {

		mint res(*this);

		return res /= a;

	}

};



mint choose(int n, int a)

{

	mint x = 1, y = 1;

	for (int i = 0; i < a; i++)

	{

		x *= n - i;

		y *= i + 1;

	}

	return x / y;

}



struct combination {

	vector<mint> fact, ifact;

	combination(int n) :fact(n + 1), ifact(n + 1) {

		assert(n < mod);

		fact[0] = 1;

		for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;

		ifact[n] = fact[n].inv();

		for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;

	}

	mint operator()(int n, int k) {

		if (k < 0 || k > n) return 0;

		return fact[n] * ifact[k] * ifact[n - k];

	}

};



template<int N>

int factorial() {

	return factorial<N - 1>() * N;

}

ll nCr(ll n, ll r);//コンビネーション

int permutation(int n, int r);//nPk パーミュテーション

int factorial(int k);//階乗



template<>  /// 特殊化：factorial<N=”1”>だったら，値を返す

int factorial<1>() {

	return 1;

}



#define MAX_N 100005

int par[MAX_N] = {};

int rank1[MAX_N] = {};

void init(int n)

{

	for (int i = 1; i <= n; i++)

	{

		par[i] = i;

		rank1[i] = 0;

	}

}

int root(int x)

{

	return par[x] == x ? x : par[x] = root(par[x]);

}

bool same(int x, int y)

{

	return root(x) == root(y);

}

void unite(int x, int y)

{

	x = root(x); y = root(y);

	if (x == y) return;

	if (rank1[x] < rank1[y])

	{

		par[x] = y;

	}

	else

	{

		par[y] = x;

		if (rank1[x] == rank1[y]) rank1[x]++;

	}

}



int main()

{

	//priority_queue<int> q;

	long double h = 0, w = 0, k = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, ans = 0;

	ll x[200005] = {};

	ll y[200005] = {};

	ll z[100005] = {};

	//std::vector<string> data;

	//sort(data.begin(), data.end());//昇順ソート

	string s;

	cin >> a;

	cin >> b;

	for (int i = 0; i < a; i++)

	{

		cin >> x[i];

		c += x[i];

	}

	for (int i = 0; i < a; i++)

	{

		if (x[i] >= c / 4 / b)

		{

			ans++;

		}

	}

	if (b <= ans)

	{

		cout << "Yes" << endl;

	}

	else

	{

		cout << "No" << endl;

	}









	//cout << c * c + a * a + b * b - 2 * a * c - 2 * b * c - 2 * a * b << endl;



//cout <<  << endl;







//cout << (ans - tmp1 - tmp2) << endl;

//cout << (ans.x) << endl;

//cout << (tmp1.x) << endl;



//return 0;



/*cout << c << endl;

cout << b << endl;*/

//cout << fixed << setprecision(10) <<tmp << endl;

//cout<<factorial<10><<endl;

	return 0;

}

//2つの組の数をソートしたりするやつ

//vector<pair<ll, ll> > hoges(a);

//for (int i = 1; i <= a; i++)

//{

//	cin >> h;

//	hoges[i - 1] = make_pair(h, i);

//}

//sort(hoges.begin(), hoges.end(), comp);

//for (int i = 0; i < a; i++)

//{

//	cout << hoges[i].second << endl;

//}



int permutation(int n, int r) {

	int n_sum, r_sum;

	int i;

	r = n - r;

	n_sum = factorial(n);

	r_sum = factorial(r);

	return n_sum / r_sum;

}



ll nCr(ll n, ll r) {

	ll ans = 1;

	for (ll i = n; i > n - r; --i) {

		ans = ans * i;

	}

	for (ll i = 1; i < r + 1; ++i) {

		ans = ans / i;

	}

	return ans;

}

int factorial(int k) {

	int sum = 1;

	for (int i = 1; i <= k; ++i)

	{

		sum *= i;

	}

	return sum;

}
