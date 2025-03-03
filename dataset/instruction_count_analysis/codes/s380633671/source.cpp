#include"stdc++.h"

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;

//#define eps 1e-8

//#define eq(x,y) (fabs((x)-(y)) < eps)

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<int,int>pii;

const ll mod = 998244353;

long double PI = acosl(-1);

const ll infl = 3e18+10;

const int inf = 1e9+10;

const int nmax = 2e5+5;

const int MAXLG = log2(nmax)+1;

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;



vector<int>g[nmax];

bool vis[nmax];

vector<int>serial;



void dfs(int u){

    if(vis[u]) return;

    vis[u] = true;

    serial.push_back(u);

    dfs(g[u][0]);

}



int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



    int n;

    cin>>n;

    vector<int>v(n);

    vector<int>dif(n);

    for(int &x : v) cin>>x;

    for(int i=1; i<n; i++) dif[i] = v[i] - v[i-1];

    int m;

    ll k;

    cin>>m>>k;

    vector<int>permu(n);

    for(int i=1; i<n; i++) permu[i] = i;

    for(int i=1; i<=m; i++){

        int pos;

        cin>>pos;

        swap(permu[pos], permu[pos-1]);

    }

    for(int i=1; i<n; i++){

        g[ permu[i] ].push_back(i);

    }

    vector<int>koigese(n);

    for(int i=1; i<n; i++){

        if(!vis[i]){

            dfs(i);

            int sz = serial.size();

            for(int j=0; j<sz; j++){

                int u = serial[j];

                koigese[u] = serial[ (k+j)%sz ];

            }

            serial.clear();

        }

    }

    vector<int>dif2(n);

    for(int i=1; i<n; i++) dif2[ koigese[i] ] = dif[i];



    vector<ll>ans = {v[0]};

    for(int i=1; i<n; i++) ans.push_back(ans.back() + dif2[i]);



    for(auto z : ans)

        cout<<z<<"\n";



}

/*

*/
