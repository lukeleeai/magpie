// #define _CRT_SECURE_NO_WARNINGS

// #define _USE_MATH_DEFINES	// M_PI=3.1415...

#include <iostream>

#include <cstdio>

#include <algorithm>

#include <string>

#include <vector>

#include <map>

#include <set>

#include <stack>

#include <cmath>

#include <cstdlib>

#include <functional>

#include <locale>

#include <cctype>

#include <sstream>

#include <iomanip>	// 20桁出力 cout << setprecision(20) << double;

#include <queue>

#include <bitset>	// bitset<8> bs1(131uL); // 10000011 bs1[0]は1 01stringからビット集合生成可

#include <numeric>

#include <random>

#include <climits>  // A/Bを計算するときA==LLONG_MIN && B==-1のみ(1ull<<63)で代用

using namespace std;



typedef long long LL;

typedef vector<LL> VL;

typedef vector<VL> VVL;				// VVL v(100,VL(100,0));

typedef pair<LL, LL> P;

typedef vector<P> VP;

typedef vector<VP> VVP;

typedef vector<string> VS;

typedef map<LL, LL> MLL;

typedef pair<LL, pair<P, P> > PP;



#define INF 999999999999999997		// 少し加算したらオーバーフローする

#define MP make_pair

#define FAST_IO  cin.tie(0); ios::sync_with_stdio(false);

#define FOR(i,a,b) for(LL i=(a);i<(b);i++)

#define FOR_REV(i,a,b) for(int i=(a);i>=(b);i--)

#define FOR_ITR(d) for(auto itr=d.begin(),d_end=d.end();itr!=d_end;++itr)

#define O(s) cout<<s<<endl;

#define SORTVL(v) sort(v.begin(), v.end());

#define SORTVL_GR(v) sort(v.begin(), v.end(), greater<LL>());



#define DUMP_VVI(b) if(dbgF){FOR(i,0,b.size()){FOR(j,0,b[i].size())printf("%d ",b[i][j]);puts("");}}

#define D_OUT(str,value) if(dbgF){cout<<str<<" : "<<value<<endl;}



template<class T>T IN() { T d; cin >> d; return d; }



// 最大公約数（Greatest Common Divisor）

LL gcd(LL a, LL b) { return (b > 0) ? gcd(b, a % b) : a; }

// 最小公倍数（Least Common Multiple）

LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }

// うるう年判定

bool uruu(LL Y) { return (((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0) ? true : false); }

// 

string Replace(string S, string from, string to) { auto p = S.find(from); while (p != string::npos) { S.replace(p, from.size(), to); p = S.find(from, p + to.size()); }return S; }

// 桁和

LL Ketawa_s(string s) { LL a = 0; FOR(i, 0, s.length())a += s[i] - '0'; return a; }

// 末尾数字で切り上げ

LL CeilLastNumber(LL n) { return ((n + (10 - 1)) / 10) * 10; }

// (x,y)がそれぞれ0以上で高さh,幅wに収まるか x,yは0-indexed、h,wは1-indexed

bool InMap(LL x, LL y, LL h, LL w) { if (x >= 0 && x < h && y >= 0 && y < w)return true; return false; }

bool InMap(P p, LL h, LL w) { return InMap(p.first, p.second, h, w); }

// 二項係数 nCk mod pを求める

const LL MAX = 510000, p = 998244353; LL fac[MAX], finv[MAX], inv[MAX];

/* 前処理 */void COM_init() { fac[0] = fac[1] = 1; finv[0] = finv[1] = 1; inv[1] = 1; FOR(i, 2, MAX) { fac[i] = fac[i - 1] * i % p; inv[i] = p - inv[p % i] * (p / i) % p; finv[i] = finv[i - 1] * inv[i] % p; } }

/* 主処理 */LL COM(int n, int k) { if (n < k) return 0; if (n < 0 || k < 0) return 0; return fac[n] * (finv[k] * finv[n - k] % p) % p; }



int dx[4] = { 0,1,0,-1 };

int dy[4] = { 1,0,-1,0 };

int dxx[8] = { 0,1,1,1,0,-1,-1,-1 };

int dyy[8] = { 1,1,0,-1,-1,-1,0,1 };



// -------------------------------------------------------------------------------



int main() {

	FAST_IO;

	bool dbgF = true; // for D_OUT(str, value)  ... cout<< str <<" : "<< value <<endl;



	LL N, X, Y;

	cin >> N >> X >> Y;



	// 隣接リスト形式グラフ

	// Pは(接続先頂点, コスト)

	VVP graph(N);



	FOR(i, 0, N - 1) {

		graph[i].push_back(MP(i + 1, 1));

		graph[i + 1].push_back(MP(i, 1));

	}

	graph[X - 1].push_back(MP(Y - 1, 1));

	graph[Y - 1].push_back(MP(X - 1, 1));



	// [i][j]の値は頂点iからjまでのコスト

	VVL distance(N, VL(N, INF));



	// 頂点iをスタートとしたダイクストラ

	// コストが確定した頂点のうち最小コストのものを選ぶ、を繰り返す

	FOR(i, 0, N) {

		// Pは現在見ている確定済み頂点の(コスト, 頂点番号)

		priority_queue<P, VP, greater<P>> q;



		distance[i][i] = 0;

		q.push(MP(0, i));



		while (!q.empty()) {

			P nowVertex = q.top();

			q.pop();

			LL nowVertexNumber = nowVertex.second;

			LL nowVertexCost = nowVertex.first;



			// 接続している頂点

			FOR(j, 0, graph[nowVertexNumber].size()) {

				LL nextVertexNumber = graph[nowVertexNumber][j].first;

				// 現在の頂点から次の頂点へ伸びる辺のコスト

				LL fromNowToNextCost = graph[nowVertexNumber][j].second;



				if (distance[i][nextVertexNumber] > distance[i][nowVertexNumber] + fromNowToNextCost) {

					// コスト確定

					distance[i][nextVertexNumber] = distance[i][nowVertexNumber] + fromNowToNextCost;

					q.push(MP(distance[i][nextVertexNumber], nextVertexNumber));

				}

			}

		}

	}



	// 出力

	VL ans(2 * pow(10, 3) + 1, 0);

	FOR(i, 0, distance.size()) {

		FOR(j, i + 1, distance[i].size()) {

			ans[distance[i][j]]++;

		}

	}



	FOR(i, 0, N - 1) {

		O(ans[i + 1]);

	}



	return 0;

}