#include"stdc++.h"

using namespace std;

const int MAXQ = 1e7 + 5;

const int MAXN = 1e3 + 5;

const int MAXP = 5e3 + 5;

const int INF = 1e9;

const long long INFLL = 1e18;

typedef long long ll;

typedef long double ld;

typedef unsigned long long ull;

template < typename T > void chkmax( T& x, T y ) { x = max( x, y ); }

template < typename T > void chkmin( T& x, T y ) { x = min( x, y ); }

template < typename T > void read( T& x )

{

    x = 0;

    int f = 1;

    char c = getchar();

    for ( ; !isdigit( c ); c = getchar() ) if ( c == '-' ) f = -f;

    for ( ; isdigit( c ); c = getchar() ) x = x * 10 + c - '0';

    x *= f;

}

template < typename T > void write( T x )

{

    if ( x < 0 ) x = -x, putchar( '-' );

    if ( x > 9 ) write( x / 10 );

    putchar( x % 10 + '0' );

}

template < typename T > void writeln( T x )

{

    write( x );

    puts( "" );

}

struct edge { int dest, flow, pos, cost; };

vector<edge> a[MAXP];

int s, t, tot, flow;

ll cost;

ll dist[MAXP];

int path[MAXP], home[MAXP];

void FlowPath()

{

    int p = t, ans = INF;

    while ( p != s ) {

        ans = min( ans, a[path[p]][home[p]].flow );

        p = path[p];

    }

    flow += ans;

    cost += ans * dist[t];

    p = t;

    while ( p != s ) {

        a[path[p]][home[p]].flow -= ans;

        a[p][a[path[p]][home[p]].pos].flow += ans;

        p = path[p];

    }

}

bool spfa()

{

    static int q[MAXQ];

    static bool inq[MAXP];

    static int l = 0, r = 0;

    for ( int i = 0; i <= r; i++ )

        dist[q[i]] = -INFLL;

    dist[t] = -INFLL;

    q[l = r = 0] = s, dist[s] = 0, inq[s] = true;

    while ( l <= r ) {

        int tmp = q[l];

        for ( unsigned i = 0; i < a[tmp].size(); i++ )

            if ( a[tmp][i].flow != 0 && dist[tmp] + a[tmp][i].cost > dist[a[tmp][i].dest] ) {

                dist[a[tmp][i].dest] = dist[tmp] + a[tmp][i].cost;

                path[a[tmp][i].dest] = tmp;

                home[a[tmp][i].dest] = i;

                if ( !inq[a[tmp][i].dest] && a[tmp][i].dest != t ) {

                    q[++r] = a[tmp][i].dest;

                    inq[q[r]] = true;

                }

            }

        l++, inq[tmp] = false;

    }

    return dist[t] != -INFLL;

}

void addedge( int x, int y, int z, int c )

{

    a[x].push_back( (edge) {y, z, a[y].size(), c} );

    a[y].push_back( (edge) {x, 0, a[x].size() - 1, -c} );

}

int n, mid[4], cntx[MAXN], cnty[MAXN];

pair<int, int> posx[MAXN], posy[MAXN];

int main()

{

    read( n ), tot = 2 * n;

    s = ++tot, t = ++tot;

    for ( int i = 0; i <= 3; i++ )

        mid[i] = ++tot;

    for ( int i = 1; i <= n; i++ ) {

        read( posx[i].first ), read( posx[i].second ), read( cntx[i] );

        addedge( s, i, cntx[i], 0 );

        addedge( i, mid[0], INF, -posx[i].first - posx[i].second );

        addedge( i, mid[1], INF, posx[i].first - posx[i].second );

        addedge( i, mid[2], INF, -posx[i].first + posx[i].second );

        addedge( i, mid[3], INF, posx[i].first + posx[i].second );

    }

    for ( int i = 1; i <= n; i++ ) {

        read( posy[i].first ), read( posy[i].second ), read( cnty[i] );

        addedge( n + i, t, cnty[i], 0 );

        addedge( mid[0], n + i, INF, posy[i].first + posy[i].second );

        addedge( mid[1], n + i, INF, -posy[i].first + posy[i].second );

        addedge( mid[2], n + i, INF, posy[i].first - posy[i].second );

        addedge( mid[3], n + i, INF, -posy[i].first - posy[i].second );

    }

    for ( int i = 1; i <= tot; i++ )

        dist[i] = -INFLL;

    while ( spfa() ) FlowPath();

    writeln( cost );

    return 0;

}
