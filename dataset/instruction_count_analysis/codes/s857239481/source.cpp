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



void fill() {

	rep (i, 0, 1000) {

		rep (j, 0, 1000) {

			val[i][j] = 10000000 + 7;

		}

	}

}

void clear() {

	rep (i, 0, 1000) {

		rep (j, 0, 1000) {

			visit[i][j] = 0;

		}

	}

}

struct Point {

	int x, y, d;

}; 





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

	fill();

	int step = 0;

	set<vector<int>> q;

	rep (i, 0, n) {

		rep (j, 0, m) {

			q.insert({inf, i, j}); 

		}

	}

	q.erase({inf, a, b});

	q.insert({0, a, b});

	val[a][b] = 0;

	//clear();

	while (!q.empty()) {

		vector<int> p = *q.begin();

		q.erase(q.begin());

		rep (i, max(0, p[1] - 2), min(n, p[1] + 3)) {

			rep (j, max(0, p[2] - 2), min(m, p[2] + 3)) {

				if (s[i][j] == '.') {

					int z = val[i][j];

					if ((abs(i - p[1]) == 1 && j == p[2]) || (abs(j - p[2]) == 1 && i == p[1])) {

						val[i][j] = min(val[i][j], val[p[1]][p[2]]);

					}else {

						val[i][j] = min(val[i][j], val[p[1]][p[2]] + 1);

					} 

					if (val[i][j] < z) {

						q.erase({z, i, j});

						q.insert({val[i][j], i, j});

					}

				}

			}

		} 

		step++;

	}

	//rep (i, 0, n) {

		//rep (j, 0, m) {

			//cout << val[i][j] << "  ";

		//}

		//cout << endl;

	//}

	debug(step);

	if (val[x][y] >= inf) {

		cout << -1;

	}else {

		cout << val[x][y];

	}

}	














































