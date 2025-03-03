#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef unsigned long long ull;

typedef pair<ll, ll> P;

typedef vector<ll> V;

typedef complex<double> Point;



#define PI acos(-1.0)

#define EPS 1e-10

const ll INF = 1e16;

const ll MOD = 1e9 + 7;



#define FOR(i,a,b) for(int i=(a);i<(b);i++)

#define rep(i,N) for(int i=0;i<(N);i++)

#define ALL(s) (s).begin(),(s).end()

#define EQ(a,b) (abs((a)-(b))<EPS)

#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )

#define fi first

#define se second

#define N_SIZE (1LL << 20)

#define NIL -1



ll mod_add(ll a, ll b) { return (a + b) % MOD; }

ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }

ll mod_mul(ll a, ll b) { return a*b % MOD; }





ll h,w;

vector<vector<ll>> s;

vector<P> sp;

set<P> gp;

ll gy,gx;

P table[2][9] = { {P(1,2),P(1,1),P(1,0),P(1,-1),P(1,-2),P(2,1),P(2,0),P(2,-1),P(3,0)},

                    {P(-1,2),P(-1,1),P(-1,0),P(-1,-1),P(-1,-2),P(-2,1),P(-2,0),P(-2,-1),P(-3,0)} };



vector<vector<ll>> d[2];



bool in(ll y,ll x){

    return y >= 0 && y < h && x >= 0 && x < w;

}



void dijkstra(){

    typedef pair<P,P> PP;

    priority_queue<PP, vector<PP>, greater<PP>> que;

    rep(i,h)rep(j,w){

        d[0][i][j] = INF;

        d[1][i][j] = INF;

    }



    rep(i,sp.size()){

        ll sy = sp[i].first;

        ll sx = sp[i].second;

        d[0][sy][sx] = 0;

        d[1][sy][sx] = 0;

        que.push(PP(P(0,0),P(sy,sx)));

        que.push(PP(P(0,1),P(sy,sx)));

    }



    while (!que.empty()){

        PP p = que.top();

        que.pop();

        ll cy = p.second.first;

        ll cx = p.second.second;

        ll cost = p.first.first;

        ll turn = p.first.second;

        if(gp.find(P(cy,cx)) != gp.end())continue;

        if(cost > d[turn][cy][cx])continue;

        // cout << "!" << cy << " " << cx << " " << cost << endl;

        rep(i,9){

            ll ny = cy + table[turn][i].second;

            ll nx = cx + table[turn][i].first;

            if(!in(ny,nx))continue;

            ll ncost = cost + s[ny][nx];

            if (d[!turn][ny][nx] > ncost){

                d[!turn][ny][nx] = ncost;

                que.push(PP(P(d[!turn][ny][nx],!turn),P(ny,nx)));

            }

        }

    }

}



int main(){

    while(cin >> w >> h&&h){

        s.clear();

        sp.clear();

        gp.clear();

        d[0].clear();

        d[1].clear();

        s.resize(h);

        d[0].resize(h);

        d[1].resize(h);

        rep(i,h){

            s[i].resize(w);

            d[0][i].resize(w);

            d[1][i].resize(w);

            rep(j,w){

                char c;

                cin >> c;

                if(c >= '0' && c <= '9')s[i][j] = c - '0';

                else{

                    s[i][j] = 0;

                    if(c == 'S')sp.push_back(P(i,j));

                    else if(c == 'T')gp.insert(P(i,j));

                    else s[i][j] = INF;

                } 

            }

        }

        dijkstra();

        ll ans = INF;

        rep(i,h){

            rep(j,w){

                if(gp.find(P(i,j)) != gp.end()){

                    // cout << i <<" " << j << endl;

                    ans = min(ans,d[0][i][j]);

                    ans = min(ans,d[1][i][j]);

                }

            }

        }

        if(ans == INF)cout << -1 << endl;

        else cout << ans << endl;

    }

}
