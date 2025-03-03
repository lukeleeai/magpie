#include "stdc++.h"

//#define fastIO cin.tie(0);ios_base::sync_with_stdio(false)

#define N 10010

#define ll long long

#define INF 1000000000000000000

//min-cost flow problem

using namespace std;



struct edge {

  ll from, to, cap, flow, cost;

};



ll n, d[2 * N + 5], pre[2 * N + 5], Maxflow = 0, COST = 0;

bool inqueue[2 * N + 5];

vector<edge> Edge;     // store edges

vector<ll> G[2 * N + 10];



inline void addEdge( ll from, ll to, ll cap, ll cost )

{

    Edge.push_back( edge{from, to, cap, 0, cost} );

    Edge.push_back( edge{to, from, 0, 0, -cost} );



    G[from].push_back( Edge.size() - 2 );

    G[to].push_back( Edge.size() - 1 );

}



inline bool bfs( ll s, ll t )

{

    for ( int i = 0; i < 2 * N + 5; ++i )

        d[i] = INF;

    memset( inqueue, 0, sizeof( inqueue ) );



    queue<ll> q;

    q.push( s );



    d[s] = 0, inqueue[s] = true;



    ll now;

    while ( q.empty() == false ) {

        now = q.front();

        q.pop();

        inqueue[now]=false;

        for ( ll i = 0; i < G[now].size(); ++i ) {

            edge& tmp = Edge[G[now][i]];

            if ( tmp.cap > tmp.flow && d[now] + tmp.cost < d[tmp.to] ) {

                d[tmp.to] = d[now] + tmp.cost;

                pre[tmp.to] = G[now][i];



                if ( inqueue[tmp.to] == false ) {  //&& tmp.to!=t  not sure

                    inqueue[tmp.to] = true;

                    q.push( tmp.to );

                }

            }

        }

    }



    return d[t] != INF;

    /*

    if(d[t]==-INF)

        return false;

    else

        return true;

    */

}



inline void calc( ll s, ll t )

{

    ll minflow = INF;

    ll tmpu = t;

    while ( s != tmpu ) { //find minflow

        minflow = min( minflow, Edge[pre[tmpu]].cap - Edge[pre[tmpu]].flow );

        tmpu = Edge[pre[tmpu]].from;

    }



    Maxflow += minflow;

    COST += minflow * d[t];



    while ( s != t ) {

        Edge[pre[t]].flow += minflow;

        Edge[pre[t] ^ 1].flow -= minflow;

        t = Edge[pre[t]].from;

    }

}



inline void init()

{

    cin >> n;



    ll a, b, c;

    for ( int i = 1; i <= n; ++i ) {

        cin >> a >> b >> c;

        addEdge( 0, i, c, 0 );

        addEdge( i, 2 * n + 1, c, -a - b );

        addEdge( i, 2 * n + 2, c, a - b );

        addEdge( i, 2 * n + 3, c, -a + b );

        addEdge( i, 2 * n + 4, c, a + b );

    }

    for ( int i = 1; i <= n; ++i ) {

        cin >> a >> b >> c;

        addEdge( i + n, 2 * n + 5, c, 0 );

        addEdge( 2 * n + 1, i + n, c, a + b );

        addEdge( 2 * n + 2, i + n, c, -a + b );

        addEdge( 2 * n + 3, i + n, c, a - b );

        addEdge( 2 * n + 4, i + n, c, -a - b );

    }

}



inline void solve()

{

    ll s = 0, t = 2 * n + 5;



    while ( bfs( s, t ) == true ) {

        calc( s, t );  //update cost && Maxflow

    }

    cout << -COST << endl;

}



int main()

{

    init();

    solve();

}