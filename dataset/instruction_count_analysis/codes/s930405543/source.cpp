#include "stdc++.h"

#include <unordered_map>

#include <unordered_set>

using namespace std;

#define endl "\n"

#define ll long long

#define sz(s) (int)(s.size())

#define INF 0x3f3f3f3f3f3f3f3fLL

#define all(v) v.begin(),v.end()

#define watch(x) cout<<(#x)<<" = "<<x<<endl

const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };

const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };

#if __cplusplus >= 201402L

template<typename T>

vector<T> create(size_t n) {

	return vector<T>(n);

}

template<typename T, typename ... Args>

auto create(size_t n, Args ... args) {

	return vector<decltype(create<T>(args...))>(n, create<T>(args...));

}

#endif

void run() {

	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

#ifdef EZZAT

	freopen("input.in", "r", stdin);

	//freopen("output.out", "w", stdout);

#else

#endif

}

struct edge {

	int from, to;

	ll a, b;

};



struct state {

	int cur;

	ll silver, time;

	int buyIdx;

	state(int cur, ll silver, ll time) :

			cur(cur), silver(silver), time(time) {

	}

	bool operator<(const state &o) const {

		return time > o.time;

	}

};



const int N = 51, MAX = 51 * 109;

vector<edge> adj[N];

pair<ll, ll> cost[N];

ll dis[N][MAX + 1];

int s;

void dijkstra() {

	memset(dis, INF, sizeof(dis));

	priority_queue<state> q;

	q.push(state(1, s, 0));

	dis[1][s] = 0;

	while (sz(q)) {

		int cur = q.top().cur;

		ll silver = q.top().silver;

		ll time = q.top().time;

		int buyIdx = q.top().buyIdx;

		q.pop();

		if (dis[cur][silver] < time)

			continue;

		ll nxtTime = (time + cost[cur].second);

		ll nxtSilver = min(1LL * MAX, silver + cost[cur].first);

		if (dis[cur][nxtSilver] > nxtTime) {

			dis[cur][nxtSilver] = nxtTime;

			q.push(state(cur, nxtSilver, nxtTime));

		}

		for (auto ch : adj[cur]) {

			ll nxtTime = (time + ch.b);

			ll nxtSilver = (silver - ch.a);

			if (nxtSilver < 0)

				continue;

			if (dis[ch.to][nxtSilver] > nxtTime) {

				dis[ch.to][nxtSilver] = nxtTime;

				q.push(state(ch.to, nxtSilver, nxtTime));

			}

		}

	}

}

int main() {

	run();

	int n, m;

	cin >> n >> m >> s;

	s = min(s, MAX);

	while (m--) {

		edge e;

		cin >> e.from >> e.to >> e.a >> e.b;

		adj[e.from].push_back(e);

		swap(e.from, e.to);

		adj[e.from].push_back(e);

	}

	for (int i = 1; i <= n; i++)

		cin >> cost[i].first >> cost[i].second;

	dijkstra();

	for (int i = 2; i <= n; i++) {

		ll mn = INF;

		for (int si = 0; si <= MAX; si++)

			mn = min(mn, dis[i][si]);

		cout << mn << "\n";

	}

}
