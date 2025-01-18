#define _CRT_SECURE_NO_WARNINGS

#include"stdc++.h"

#include<iostream>

#include<algorithm>

#include<iomanip>

#include<string>

#include<cmath>

#include<vector>

#include<set>

#include<queue>

#include<stack>

#include<fstream>

#include<map>

#include<bitset>

#include<unordered_map>

#include<cstring>

#include<cctype>

using namespace std;

#define  ll long long

#define  ull unsigned long long

#define  ul unsigned long

#define all(v) v.begin(),v.end()

#define sz(n) (int)n.size()

#define pb(s) push_back(s);

#define format(n) fixed<<setprecision(n)

#define finl "\n"

#define Mohammed_Atef_Hassan fast();

#define mod 1000000007

#define INF LLONG_MAX

#define PI acos(-1)

#define clr(dp,n) memset(dp,n,sizeof dp)

#define ex(n) return cout<<n<<finl,0;

int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

ll fix_mod(ll x, ll y)

{

	return (y + x % y) % y;

}

void fast() {

	std::ios_base::sync_with_stdio(false);

	cin.tie(nullptr); cout.tie(nullptr);





}

int n,c;

vector<ll>v;

ll mem[(int)1e5 + 10];

ll solve(int i)

{

	if (i == n-1)return 0;

	ll& ret = mem[i];

	if (~ret)return ret;

	ret = solve(i + 1) + abs(v[i + 1] - v[i]);

	for (int k = 2; k <= c; k++)

		if (k + i < n)ret = min(ret, solve(i + k) + abs(v[i + k] - v[i]));

	return ret;

}

int main()

{

	Mohammed_Atef_Hassan

		clr(mem, -1);

		cin >> n>>c;

	v = vector<ll>(n);

	for (int i = 0; i < n; i++)cin >> v[i];

	ex(solve(0));

}