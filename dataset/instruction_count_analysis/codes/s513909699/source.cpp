#include "stdc++.h"



using namespace std;



#define pb push_back

#define eb emplace_back

#define ll long long

#define pii pair < int, int >

#define fr first

#define sc second

#define mk make_pair

#define sz(s) (int)s.size()

#define all(s) s.begin(), s.end()

#define ok puts("ok");

#define whatis(x) cerr << #x << " = " << x << endl;

#define pause system("pause");

#define random rand() ^ (rand() << 5)



const int N = (int)1e5 + 7;

const int inf = (int)1e9 + 7;



int n, u, v;

vector < int > gr[N];

int h[N], p[N], is[N], v1;

int cnt = 1;

vector < int > ans, vec[2];



void dfs(int v, int pr = 0) {

	p[v] = pr;

	for (int to : gr[v]) {

		if (to == pr) continue;

		h[to] = h[v] + 1;

		dfs(to, v);

		is[v] = is[to];

	}

}



void no() {

	puts("-1");

	exit(0);

}



void dfs1(int v, int pr = 0) {

	if (is[v]) {

		h[v] = 0;

		int c = 1;

		for (int to : gr[v]) {

			if (to == pr || is[to]) continue;

			ans.pb(cnt + c);

			c++;

		}

		ans.pb(cnt);

		cnt += c;

	} else if (h[v] > 1) {

		no();

	}

	for (int to : gr[v]) {

		if (to == pr) continue;

		h[to] = h[v] + 1;		

		dfs1(to, v);

		

	}

}



main() {

	scanf("%d", &n);

	for (int i = 1; i < n; i++) {

		scanf("%d %d", &u, &v);

		gr[u].pb(v);

		gr[v].pb(u);

	}

	dfs(1);

	int mx = 0;

	int v = -1;

	int v2;

	for (int i = 1; i <= n; i++) {

		if (h[i] > mx) {

			mx = h[i];

			v = i;

		}

	}

	h[v] = 0;

	dfs(v);

	v2 = v;

	v = -1;

	mx = 0;

	for (int i = 1; i <= n; i++) {

		if (h[i] > mx) {

			mx = h[i];

			v = i;

		}

	}

	int v1 = v;

	while (v != 0) {

		is[v] = 1;

		v = p[v];

	}

	dfs1(v1);

	vec[0] = ans;

	cnt = 1;

	ans.clear();

	dfs1(v2);

	vec[1] = ans;

	int fl = 0;

	for (int i = 1; i <= n; i++) {

		if (vec[0][i - 1] == vec[1][i - 1]) continue;		

		if (vec[0][i - 1] > vec[1][i - 1]) {

			fl = 1;

		}

		break;

	}

	for (int to : vec[fl]) {

		printf("%d ", to);

	}

}