

#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<queue>

#include<map>

#include<math.h>

#include<iomanip>

#include<set>

#include<numeric>

#include<cstring>

#include<cstdio>

#include<functional>



#define REP(i, n) for(int i = 0;i < n;i++)

#define REPR(i, n) for(int i = n;i >= 0;i--)

#define FOR(i, m, n) for(int i = m;i < n;i++)

#define FORR(i, m, n) for(int i = m;i >= n;i--)

#define SORT(v, n) sort(v, v+n);

#define VSORT(v) sort(v.begin(), v.end());

#define REVERSE(v,n) reverse(v,v+n);

#define VREVERSE(v) reverse(v.begin(), v.end());

#define ll long long

#define pb(a) push_back(a)

#define INF 1010101010

#define m0(x) memset(x,0,sizeof(x))

#define fill(x,y) memset(x,y,sizeof(x))

#define mp make_pair



using namespace std;











int dy[4] = { 0,0,1,-1 };

int dx[4] = { 1,-1,0,0 };

int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };

int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };





ll m = 1000000007;



const int MOD = 1000000007;



ll gcd(ll x, ll y) {

	ll m = max(x, y), n = min(x, y);

	if (m%n == 0)return n;

	else return gcd(m%n, n);

}





ll myPow(ll x, ll n, ll m) {

	if (n == 0)

		return 1;

	if (n % 2 == 0)

		return myPow(x * x % m, n / 2, m);

	else

		return x * myPow(x, n - 1, m) % m;

}







long long nCr(int n, int r) {

	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)

	long long ans = 1;

	int i;



	for (i = 1; i <= r; i++) {

		ans *= n - r + i;

		ans /= i;

	}



	return ans;

}







ll B[2010], A[2010], C[2010];

ll dist[1010];

bool negative[1010];

int main() {

	fill(dist, INF);

	m0(negative);

	dist[0] = 0;

	ll N, M; cin >> N >> M;

	REP(i, M) {

		ll a, b, c;

		cin >> a >> b >> c;

		a--; b--; c = c * (-1);//コストの符号を逆にする

		A[i] = a; B[i] = b; C[i] = c;

	}

	//一回の更でパスの長さを1増やすことになり、(閉路がない限り)パスは最長でN-1なので(N-1)回繰り返せば十分

	REP(j, N) {

		REP(i, M) {

			dist[B[i]] = min(dist[B[i]], dist[A[i]] + C[i]);

		}

		//オーバーフロー対策

		if (dist[N] < -111100000000000) {

			cout << "inf" << endl;

			return 0;

		}

	}



	//もう一度だけ更新してみて、もし距離が変わるなら(長さをいくらでも小さくできるような)閉路があるということ

	REP(i, M) {

		if (dist[B[i]] > dist[A[i]] + C[i]) {

			dist[B[i]] = min(dist[B[i]], dist[A[i]] + C[i]);

			negative[B[i]] = true;

		}

	}



	if (dist[N] < -111100000000000) {

		cout << "inf" << endl;

		return 0;

	}



	if (negative[N - 1]) {

		cout << "inf" << endl;

	}

	else {

		cout << dist[N - 1] * (-1) << endl;

	}

}
