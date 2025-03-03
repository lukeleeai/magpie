

#include"stdc++.h"





using namespace std;



using ll   = long long;

using ii   = pair < int , int >;

using i3   = pair < int , ii >;

using li   = pair < ll , int >;

using lii  = pair <  ll,  ii >;

using vi   = vector < int >;

using vl   = vector < ll >;

using vli  = vector < li >;

using vii  = vector < ii >;

using vi3  = vector < i3 >;

using vlii = vector < lii >;



const int N = 2e5 + 5;

const ll INF = 1e17;

const double eps = 1e-12 , PI = acos(-1);



int n , m;



vi adj[N];



int start = 0;



vector < vi > ans;

int p[N];

bool vis[N];



void getCyc(int u){

    vi tmp;



    while( true ){

            tmp.push_back(u);

            if(u == start)break;

            u = p[u];

    }



    reverse(tmp.begin() , tmp.end());

    ans.push_back(tmp);

}



void bfs(int u){

    memset(vis , 0 , sizeof vis);



    queue < int > q;

    p[u] = u;

    vis[u] = 1;

    q.push(u);



    while( !q.empty() ){

            u = q.front();

            q.pop();



            for(int v : adj[u]){

                    if(v == start){

                            getCyc(u);

                            return;

                    }

            }



            for(int v : adj[u]){

                    if(vis[v])continue;

                    vis[v] = 1;

                    p[v] = u;

                    q.push(v);

            }

    }

}



void solve(int cs){

    scanf("%d %d" , &n , &m);



    for(int i = 0 ; i < m ; i ++){

            int u , v;

            scanf("%d %d" , &u , &v);

            adj[u].push_back(v);

    }



    for(int i = 1 ; i <= n ; i ++){

            start = i;

            bfs(i);

    }



    int sz = ans.size();

    if(sz == 0){

            printf("-1\n");

            return;

    }



    int mn = 10000 , dx = 0;

    for(int i = 0 ; i < sz ; i ++){

            if(ans[i].size() < mn){

                    mn = ans[i].size();

                    dx = i;

            }

    }



    printf("%d\n" , ans[dx].size());

    for(int A : ans[dx]){

            printf("%d\n" , A);

    }

}



main(){

    int t = 1;



    for(int cs = 1 ; t -- ; cs ++){

        solve(cs);

    }



    return 0;

}


