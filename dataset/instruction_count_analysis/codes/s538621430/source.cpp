#include <iostream>

#include<vector>

#include<algorithm>

#include<string>

#include<map>

#include<set>

#include<stack>

#include<queue>

#include<math.h>

using namespace std;

typedef long long ll;

#define int long long

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef vector<pii> VP;

typedef vector<string> VS;

typedef priority_queue<int> PQ;

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

#define fore(i,a) for(auto &i:a)

#define REP(i,n) for(int i=0;i<n;i++)

#define eREP(i,n) for(int i=0;i<=n;i++)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)

#define SORT(c) sort((c).begin(),(c).end())

#define rSORT(c) sort((c).rbegin(),(c).rend())

#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))

#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))

#define INF 1000000000

#define LLINF 9223372036854775807

#define mod 1000000007

//priority_queue<int,vector<int>, greater<int> > q2;







signed main() {

	cin.tie(0);

	ios::sync_with_stdio(false);

	

	int N; cin >> N;

	vector<VI>G(N);

	VI C(N);

	REP(i, N - 1) {

		int a, b; cin >> a >> b; a--; b--;

		G[a].push_back(b);

		G[b].push_back(a);

	}

	int sum = 0;

	REP(i, N) {

		cin >> C[i];

		sum += C[i];

	}

	rSORT(C);



	int a;

	REP(i, N)if (G[i].size() == 1) {

		a = i;

		break;

	}

	queue<int>Q;

	VI ans(N);

	Q.push(a);

	vector<bool>vis(N, false);

	vis[a] = 1;

	int k = 0;

	while (!Q.empty()) {

		int now = Q.front();

		Q.pop();

		ans[now] = C[k];

		k++;

		fore(to, G[now]) {

			if (!vis[to]) {

				vis[to] = 1;

				Q.push(to);

			}

		}



	}











	cout << sum - C[0] << endl;

	REP(i, N)cout << ans[i] << " ";

	cout << endl;

	return 0;

}


