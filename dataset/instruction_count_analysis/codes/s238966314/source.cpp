#include <iostream>

#include <algorithm>

#include <vector>

#include <map>

#include <set>

//#include <numeric> //iota

//#include <sstream>

#include <cstring>

//#include <tuple>

//#include <random>

//#include <string>

//#include <unordered_set>

//#include <bitset>

//#include <unordered_map>

//#include <stack>

//#include <cmath>

//#include <deque>

#include <queue>

//#include <list>

#include <array>

using namespace std;

#define endl "\n"

#define all(x) (x).begin(), (x).end()

#define vec vector

#define pb push_back

#define pp pop_back

#define fi first

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define se second

#define un_map unordered_map

#define rep(i,a,n) for (int i = a; i < n; ++i) 

#define inc_rep(i,a,n,inc) for (int i = a; i < n; i += inc) 

#define couts(x) cout << x << "\n" 

#define watch(x) cout << #x << " : " << x << endl;

typedef long long ll;

typedef pair<int,int> PII;

typedef pair<long long, long long>  PLII;

template<typename T>

void print(vector<T>& v) {rep(i, 0, (int)v.size()) cout << v[i] << " ";cout << endl;}

int nxt() {int x;cin >> x;return x;}

ll nxtl() {ll x;cin >> x;return x;}

string nxts() {string x;cin >> x;return x;}

double nxtd() {double x; cin >> x; return x;}



void __print(int x) {cerr << x;}

void __print(long x) {cerr << x;}

void __print(long long x) {cerr << x;}

void __print(unsigned x) {cerr << x;}

void __print(unsigned long x) {cerr << x;}

void __print(unsigned long long x) {cerr << x;}

void __print(float x) {cerr << x;}

void __print(double x) {cerr << x;}

void __print(long double x) {cerr << x;}

void __print(char x) {cerr << '\'' << x << '\'';}

void __print(const char *x) {cerr << '\"' << x << '\"';}

void __print(const string &x) {cerr << '\"' << x << '\"';}

void __print(bool x) {cerr << (x ? "true" : "false");}



template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}



#ifndef ONLINE_JUDGE

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

#else

#define debug(x...)

#endif



int val[1001][1001];

int visit[1001][1001];



int main() {

	IOS;

	int n, m;

	cin >> n >> m;

	int a, b , x, y;

	cin >> a >> b >> x >> y;

	a--;b--;x--;y--;

	vector<string> s(n);

	rep (i, 0, n) {

		cin >> s[i];

	}

	int inf = 1e7 + 7;

	deque<pair<int,int>> d;

	rep (i, 0, n) {

		rep (j, 0, m) {

			val[i][j] = inf;

		}

	}

	d.push_front({a, b});

	val[a][b] = 0;

	while (!d.empty()) {

		pair<int,int> p = d.front();

		d.pop_front();

		int x_x = p.first;

		int y_y = p.second; 

		rep (i, max(0, x_x - 2), min(n, x_x + 3)) {

			rep (j, max(0, y_y - 2), min(m, y_y + 3)) {

				if (s[i][j] == '.') {

					int z = val[i][j];

					if ((abs(i - x_x) == 1 && j == y_y) || (abs(j - y_y) == 1 && i == x_x)) {

						val[i][j] = min(val[i][j], val[x_x][y_y]);

					}else {

						val[i][j] = min(val[i][j], val[x_x][y_y] + 1);

					} 

					if (val[i][j] != z) {

						if (val[i][j] == val[x_x][y_y]) {

							d.push_front({i, j});

						}else if (val[i][j] == val[x_x][y_y] + 1){

							d.push_back({i, j});

						}

					}

				}

			}

		} 

	}

	if (val[x][y] >= inf) {

		cout << -1;

	}else {

		cout << val[x][y];

	}

}	














































