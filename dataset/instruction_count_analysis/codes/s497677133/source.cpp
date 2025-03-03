#include <iostream>

#include <string>

#include <algorithm>

#include <vector>

#include <math.h>

#include <complex>

#include <queue>

#include <deque>

#include <stack>

#include <map>

#include <set>

#include <bitset>

#include <assert.h>

#include <numeric>

#include <iomanip>

#define rep(i, a, b) for (int(i) = (a); i < (b); i++)

using namespace std;



using ll = long long;



typedef pair<int, int> P;



const int INF = 100000000;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const ll MOD = 1000000007;



ll pow_mod(ll x, ll y, ll mod)

{

	ll ans=1;

	for(;y>0;y>>=1){

		if(y&1)(ans*=x)%=mod;

		(x*=x)%=mod;

	}

	return ans;

}



ll n, m;

ll s , t;

int d[300000];



vector<int> vv[300000];



void dijkstra(int s)

{

	priority_queue<P, vector<P>, greater<P>> que;

	fill(d, d + 3 * n, INF);

	d[s] = 0;

	que.push(P(0, s));



	while (!que.empty())

	{

		P p = que.top();

		que.pop();

		int v = p.second;

		if(d[v]<p.first){

			continue;

		}

		for (int i = 0; i < vv[v].size();i++){

			int u = vv[v][i];

			if(d[u]>d[v]+1){

				d[u] = d[v] + 1;

				que.push(P(d[u], u));

			}

		}

	}

}



int main()

{

	cin.tie(0);

	ios::sync_with_stdio(false);

	//問題文中の添え字が0-indexか1-indexか確認!

	cin >> n >> m;



	rep(i,0,m){

		int a, b;

		cin >> a >> b;

		a--;

		b--;

		vv[a].push_back(n + b);

		vv[n + a].push_back(n * 2 + b);

		vv[n * 2 + a].push_back(b);

	}



	cin >> s >> t;

	s--;

	t--;



	dijkstra(s);

	if(d[t]!=INF){

		cout << d[t]/3;

	}else{

		cout << -1;

	}

	return 0;

}