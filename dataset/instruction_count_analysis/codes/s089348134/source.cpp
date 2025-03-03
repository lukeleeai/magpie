#include<iostream>

#include"stdc++.h"

#include <stdio.h>

#include<unordered_map>

#define Amr_Abdelazim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long

#define ld long double

#define pll pair<ll,ll>

#define vll vector<ll>

#define vvll vector<vector<ll> >

#define vpll vector<pair<ll,ll> >

#define P complex<ld>

#define X real()

#define Y imag()

#define all(v) v.begin(),v.end()

#define rall(v) v.rbegin(),v.rend()

#define rep(i,n)   for(int i=0;i<n;i++)

#define repp(i,s,n)   for(int i=s;i<=n;i++)

#define print(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}

#define mkp make_pair

#define clr(ar,v) memset(ar,v,sizeof(ar));

#define TC ll amr_abdelazim;cin>>amr_abdelazim;while(amr_abdelazim--)

#define popcnt(x) __builtin_popcount(x)

#define EPS 1e-9

#define INF 1000000000000000009

using namespace std;

//freopen("output.txt", "w", stdout);

//freopen("input.txt", "r", stdin);

const int mod = 1000000007;

const int N = 2 * 100000 + 9;

const double pi = acos(-1);

class cmp{

public:

	bool operator() (ll &A, ll &B){

		return A > B;

	}

};

bool by_sec(const pll &a, const pll &b){

	if ((abs(a.first) == abs(b.first)))

		return (abs(a.second) < abs(b.second));

	return (abs(a.first) < abs(b.first));

}

bool byth(const tuple<ll, ll, ld>& a, const tuple<ll, ll, ld>& b){

	return (get<2>(a) < get<2>(b));

}

ld dist(P a, P b){

	return (ld)abs(a - b);

}

ll fact[1000009], inv[1000009];

ll fp(ll a, ll b){

	if (b == 0)

		return 1;

	ll ans = fp(a, b / 2);

	ans = (ans * ans) % mod;

	if (b % 2 != 0)

		ans = (ans * (a % mod)) % mod;

	return ans;

}

void FacInv(ll n){

	fact[0] = inv[0] = 1;

	for (ll i = 1; i <= n; i++)

	{

		fact[i] = ((i%mod) * fact[i - 1] % mod) % mod;

		inv[i] = fp(fact[i], mod - 2);

	}

}

ll ncr(ll n, ll r){

	return (((fact[n] * inv[r]) % mod) * inv[n - r]) % mod;

}

ll gcd(ll a, ll b){

	if (b == 0)return a;

	return gcd(b, a%b);

}

ll max(ll a, ll b){

	if (a >= b)return a;

	else return b;

}

ll min(ll a, ll b){

	if (a <= b)return a;

	else return b;

}



vvll gr(N);

bool vis[N][4];

vll en;

void dfs(ll n, ll c){

	vis[n][c] = 1;

	if (c == 0){

		if (!vis[n][3]){

			vis[n][3] = 1;

			en.push_back(n);

		}

		return;

	}

	for (auto i : gr[n]){

		if (!vis[i][c-1])

		dfs(i, c - 1);

	}

}



int main()

{

	Amr_Abdelazim



		ll x, y, a, b;

	cin >> x >> y >> a >> b;

	ll dx = a - x, dy = b - y;

	cout << a - dy << " " << b + dx << " ";

	cout << x - dy << " " << y + dx << "\n";

	return 0;

}