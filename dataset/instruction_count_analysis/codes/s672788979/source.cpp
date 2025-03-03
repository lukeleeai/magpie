#include<iostream>

#include<algorithm>

#include<vector>

#include<queue>

#include<list>

#include<set>

#include<string>

using namespace std;

int gcd(int a, int b) {

	int c = a % b;

	while (c != 0) {

		a = b;

		b = c;

		c = a % b;

	}

	return b;

}

struct UnionFind {

	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2



	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化

		for (int i = 0; i < N; i++) par[i] = i;

	}



	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}

		if (par[x] == x) return x;

		return par[x] = root(par[x]);

	}



	void unite(int x, int y) { // xとyの木を併合

		int rx = root(x); //xの根をrx

		int ry = root(y); //yの根をry

		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける

	}



	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す

		int rx = root(x);

		int ry = root(y);

		return rx == ry;

	}

};

typedef long long ll;



const ll M = 1000000007;



vector<ll> fac(300001); //n!(mod M)

vector<ll> ifac(300001); //k!^{M-2} (mod M)



ll mpow(ll x, ll n) {

	ll ans = 1;

	while (n != 0) {

		if (n & 1) ans = ans * x % M;

		x = x * x % M;

		n = n >> 1;

	}

	return ans;

}

ll comb(ll a, ll b) {

	if (a == 0 && b == 0)return 1;

	if (a < b || a < 0)return 0;

	ll tmp = ifac[a - b] * ifac[b] % M;

	return tmp * fac[a] % M;

}

// mod. m での a の逆元 a^{-1} を計算する

long long modinv(long long a) {

	long long b = M, u = 1, v = 0;

	while (b) {

		long long t = a / b;

		a -= t * b; swap(a, b);

		u -= t * v; swap(u, v);

	}

	u %= M;

	if (u < 0) u += M;

	return u;

}

int main() {

	ll i, ans=0, count = 0;

	char s[222222];

	cin >> s;

	if (s[0] == 'A')

		count++;

	for (i = 1; s[i] != '\0'; i++) {

		if (s[i] == 'A')

			count++;

		if (s[i] == 'B') {

			if (s[i - 1] != 'A'||s[i+1]!='C')

				count = 0;

		}

		if (s[i] == 'C') {

			if (s[i - 1] == 'B') {

				ans += count;

				s[i] = 'A';

			}

			else

				count = 0;

		}

	}

	cout << ans << endl;

}