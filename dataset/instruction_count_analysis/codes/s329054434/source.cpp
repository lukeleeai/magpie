#include <iostream>

#include <set>

#include <vector>

#include <string>

#include <algorithm>

#include <cmath>

using namespace std;

using ll=long long;

#define rep(i,a,b) for(ll i=a;i<ll(b);i++)

#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)

#define endl "\n"

#define ALL(x) x.begin(),x.end()

#define ALLR(x) x.rbegin(),x.rend()

#define INF 1e9

#define DEBUG(x) cout<<"debug: "<<x<<endl



vector<bool> seen(200001);

set<int> graph[200001];



int surch(const set<int> g){

    int succ = 0;

    for(auto x : g){

        if(seen[x]) continue;

        seen[x] = true;

        succ++;

        succ += surch(graph[x]);

    }

    return succ;

}



int n, m;

int main() {

    cin >> n >> m;



    rep(_, 0, m){

        int a, b; cin >> a >> b;

        a--;b--;

        graph[a].insert(b);

        graph[b].insert(a);

    }



    int ans = 1;

    rep(i, 0, n){

        if(seen[i]) continue;

        int tmp = surch(graph[i]);

        ans = max(ans, tmp);

    }



    cout << ans << endl;

    return 0;

}
