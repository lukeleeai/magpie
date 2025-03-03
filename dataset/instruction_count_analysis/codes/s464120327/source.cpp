/*** author: yuji9511 ***/

#include "stdc++.h"

using namespace std;

using ll = long long;

using lpair = pair<ll, ll>;

const ll MOD = 1e9+7;

const ll INF = 1e18;

#define rep(i,m,n) for(ll i=(m);i<(n);i++)

#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)

#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

void print() {}

template <class H,class... T>

void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll H,W;

    cin >> H >> W;

    string S[22];

    rep(i,0,H) cin >> S[i];

    ll dist[410][410] = {};

    ll sz = H*W;

    rep(i,0,sz){

        rep(j,0,sz){

            if(i == j) dist[i][j] = 0;

            else dist[i][j] = INF;

        }

    }

    ll dh[4] = {0,0,1,-1};

    ll dw[4] = {1,-1,0,0};

    rep(i,0,H){

        rep(j,0,W){

            if(S[i][j] == '#') continue;

            rep(k,0,4){

                ll hh = i + dh[k];

                ll ww = j + dw[k];

                if(hh >= 0 && hh < H && ww >= 0 && ww < W){

                    if(S[hh][ww] == '.'){

                        ll from = i * W + j;

                        ll to = hh * W + ww;

                        dist[from][to] = 1;

                        dist[to][from] = 1;

                    }



                }

            }



        }

    }

    rep(k,0,sz){

        rep(i,0,sz){

            rep(j,0,sz){

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

            }

        }

    }

    ll ans = 0;

    rep(i,0,sz){

        rep(j,0,sz){

            if(dist[i][j] == INF) continue;

            ans = max(ans,dist[i][j]);

        }

    }

    print(ans);

    



}