#include "stdc++.h"

using namespace std;

#define maxx 100010

#define mp make_pair

typedef pair<int,int> ii;

int ans[maxx],visitado[maxx];

vector < ii > ladj[maxx];

map <int, int> dicio;

int n,m,p = 0;

int nos = 0;

vector < int > dist;



void dfs(int x){

	visitado[x] = 1;

	for(auto e: ladj[x]){

		if(visitado[e.second] == 0) dfs(e.second);

	}

}



const int INF = -1e9;

bool spfa(int s) {

    int N = n+1;

    dist.assign(N, INF);

    vector < int > cnt(N, 0);

    vector < bool > inqueue(N, false);

    queue < int > q;

	N = nos;

	

    dist[s] = 0;

    q.push(s);

    inqueue[s] = true;

	while (!q.empty()) {

  

		int atual = q.front();

       	

        q.pop();

    	inqueue[atual] = false;

        for (auto edge : ladj[atual]) {

                int peso = edge.first - p;

		int next = edge.second;



                if (dist[atual] + peso > dist[next] && ans[next] == 1) {

                       dist[next] = dist[atual] + peso;



                       if (!inqueue[next]) {

                              q.push(next);

                              inqueue[next] = true;

                              cnt[next]++;

                    if (cnt[next] > N)

                        return false;  // negative cycle

                }

            }

        }

    }

    return true;

}

vector < int > help; 



int main() {

	cin >> n >> m >> p;

	

	int a,b,w;

	for(int i = 1; i <= m; i++){

		cin >> a >> b >> w;

		ladj[a].push_back(mp(w,b));



	}

	dfs(1);

	bool c = true;

	if(visitado[n] == 1){

		ans[1] = 1;

		nos++;

		for(int i = 2; i <= n;i++){

			for(int j = 1; j <= n+1; j++)visitado[j] = 0;

			dfs(i);

			if(visitado[1] == 1 || visitado[n] == 1){nos++;ans[i] = 1;}



		}

		c = spfa(1);

	}	



	if(c == true) cout << max(0,dist[n]) << endl;

	else cout << -1 << endl;

	return 0;

}
