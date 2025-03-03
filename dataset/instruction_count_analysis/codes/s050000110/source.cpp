#include "stdc++.h"



using namespace std;



#define fi first

#define se second

#define pb push_back

#define mp make_pair



typedef pair<long long, long long> ii;

vector<ii> vec;

long long a[100005], n, dp[100005];

vector<int> graph[100005];



int main() {

    cin.tie(0), ios::sync_with_stdio(0);

    cin >> n;

    for(int i = 1; i <= n; i++){

        cin >> a[i];

        vec.pb(mp(a[i], i));

    }

    for(int i = 1; i <= n - 1; i++){

        int u, v;

        cin >> u >> v;

        graph[u].pb(v);

        graph[v].pb(u);

    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++){

        if(dp[vec[i].se] == 0){

            for(int j = 0; j < graph[vec[i].se].size(); j++){

                int v = graph[vec[i].se][j];

                if(a[v] > a[vec[i].se])

                    dp[v] = 1;

            }

        }

    }

    for(int i = 1; i <= n; i++){

        if(dp[i])

            cout << i << " ";

    }

}
