#include "stdc++.h"



#define f first

#define s second

#define pb push_back

#define mp make_pair



using namespace std;



typedef long long ll;

typedef pair<int, int> pii;

typedef pair<long long, long long> pll;



const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;

const ll INF = 1e18;



vector< int > g[N], ans;

int n, m;

bool used[N];



int main()

{                         

	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; i++){

		int v, u;

		scanf("%d%d", &v, &u);

		g[v].pb(u);

		g[u].pb(v);

		if(i == 0){

			ans.pb(v);

			ans.pb(u);

		}

	}           

	used[ans[0]] = 1;

	used[ans[1]] = 1;

	                        

	while(true){

		int v = ans.back();

		while(!g[v].empty() && used[g[v].back()])

			g[v].pop_back();

		if(g[v].size() == 0)

			break;

		ans.pb(g[v].back());	

		used[g[v].back()] = 1;

	}

	reverse(ans.begin(), ans.end());



	while(true){

		int v = ans.back();

		while(!g[v].empty() && used[g[v].back()])

			g[v].pop_back();

		if(g[v].size() == 0)

			break;

		ans.pb(g[v].back());	

		used[g[v].back()] = 1;

	}

	printf("%d\n", ans.size());

	for(auto it : ans)

		printf("%d ", it);

	return 0;

}
