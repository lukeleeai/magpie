#include <stdio.h>

#include<vector>

#include<deque>



using namespace std;

#define mygc(c) (c)=getchar_unlocked()

#define mypc(c) putchar_unlocked(c)

inline void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }

inline void writer(int x, char c) { int s = 0, m = 0; char f[7]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }

template<class T> void writerLn(T x) { writer(x, '\n'); }

#define rep(i,n)for(int i=0;i<n;i++)

vector<int>E[100000];

int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;

char b[200000], ok[100000];

deque<int>que;



void bfs(int u, int t) {

	que.emplace_back(u);

	while (!que.empty()) {

		int p = que.front(); que.pop_front();

		for (int v : E[p]) {

			if (t) {

				if (d[v] > d[p] && !ok[v]) {

					ok[v] = 1; cnt++; que.emplace_back(v);

				}

			}

			else if (!d[v]) {

				d[v] = d[p] + 1; que.emplace_back(v);

			}

		}

	}

}

int main() {

	ok[0] = d[0] = 1;

	int n, m, q; reader(n); reader(m); reader(q);

	rep(i, m) {

		reader(u[i]); reader(v[i]);

		u[i]--; v[i]--;

		E[u[i]].emplace_back(v[i]); E[v[i]].emplace_back(u[i]);

	}

	bfs(0, 0);

	rep(i, m) {

		if (d[u[i]] > d[v[i]])swap(u[i], v[i]);

	}

	rep(i, n)E[i].clear();

	rep(i, q) {

		reader(r[i]); r[i]--;

		b[r[i]] = 1;

	}

	rep(i, m) {

		if (!b[i]) {

			if (d[v[i]] > d[u[i]]) {

				E[u[i]].emplace_back(v[i]);

			}

		}

	}

	bfs(0, 1);

	for (int i = q - 1; i >= 0; i--) {

		ans[i] = n - cnt;

		if (d[v[r[i]]] > d[u[r[i]]] && !ok[v[r[i]]]) {

			E[u[r[i]]].emplace_back(v[r[i]]);

			if (ok[u[r[i]]]) {

				cnt++; ok[v[r[i]]] = 1;

				bfs(v[r[i]], 1);

			}

		}

	}

	rep(i, q)writerLn(ans[i]);

}