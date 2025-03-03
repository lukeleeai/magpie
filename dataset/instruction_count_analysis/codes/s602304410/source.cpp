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

//typedef pair<int, int> pii;

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

//vector<vector<int> > dp;

//vector<vector<vector<int> > > vvvi;

//dp=vector<vector<int> >(N, vector<int>(M,0));

//vector<pair<int,int> > v;

//v.push_back(make_pair(x,y));

//priority_queue<int,vector<int>, greater<int> > q2;



#define ma 100010



vector<VI> to(ma);

vector<pair<int, int> >ans, in;

VI cost;

int N;

VI out(ma);

VI si(ma);





void bfs() {

	queue<int> Q;

	int co = 0;

	Q.push(0);

	int cnt = 0;

	while (!Q.empty()) {

		//cout << "K" << endl;

		//cout << cnt << endl;

		if (out[Q.front()] == LLINF) {

			out[Q.front()] = cost[co];

			cnt++;

			co++;

		}

		if (cnt == N)return;

		

		int i = 0;

		while (i < to[Q.front()].size()) {

			if(out[to[Q.front()][i]]==LLINF)Q.push(to[Q.front()][i]);

			i++;

		}

		Q.pop();

	}

}









signed main(){

cin.tie(0);

ios::sync_with_stdio(false);



	cin >> N;

	REP(i, N) {

		out[i] = LLINF;

	}

	REP(i, N-1) {

		int a, b;

		cin >> a >> b;

		a--;

		b--;

		to[a].push_back(b);

		to[b].push_back(a);

		in.push_back(make_pair(a, b));

	}



	REP(i, N) {

		int a;

		cin >> a;

		cost.push_back(a);

	}

	rSORT(cost);

	

	REP(i, N) {

		si[i] = to[i].size();

	}



	REP(i, N) {

		int a = si[i], b = i;

		ans.push_back(make_pair(a, b));

	}

	rSORT(ans);

	REP(i, N) {

		//cout << ans[i].first<<" "<<ans[i].second << endl;

	}

	//cout << endl;



	REP(i, N) {

		//out[ans[i].second] = cost[i];

	}



	bfs();



	int sum = 0;

	REP(i, N - 1) {

		sum += min(out[in[i].first], out[in[i].second]);

	}



	cout << sum << endl;

	FOR(i,0, N-1) {

		//cout << to[i][0] << endl;

		cout << out[i] <<" ";

	}

	cout << out[N - 1] << endl;

	return 0;

}


