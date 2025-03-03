#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)

#define fi first

#define se second

long long mo = 1000000007;

typedef long long ll;

typedef long double ld;

typedef pair<int,int> Pii;

typedef pair<ll,ll> Pll;

typedef pair<ll,Pll> PlP;

template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }

template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

ld PI=3.14159265358979323846;



int main(){

    ll N,u,v;

    cin >> N >> u >> v;

    u--;v--;

    vector<ll> A(N-1), B(N-1);

    vector<vector<ll>> G(N);

    rep(i,N-1){

        cin >> A[i] >> B[i];

        A[i]--;B[i]--;

        G[A[i]].push_back(B[i]);

        G[B[i]].push_back(A[i]);

    }

    queue<ll> que;

    vector<ll> du(N,1e18), dv(N,1e18);

    que.push(u);

    du[u] = 0;

    while(!que.empty()){

        ll a = que.front();

        que.pop();

        for(auto& b:G[a]){

            if(du[b] != 1e18) continue;

            du[b] = du[a] + 1;

            que.push(b);

        }

    }

    que.push(v);

    dv[v] = 0;

    while(!que.empty()){

        ll a = que.front();

        que.pop();

        for(auto& b:G[a]){

            if(dv[b] != 1e18) continue;

            dv[b] = dv[a] + 1;

            que.push(b);

        }

    }

    ll dis = du[v];

    ll M = 0;

    ll id = 0;

    rep(i,N){

        if(dv[i] - du[i] > 0){

            if(M <= dv[i]){

                M = dv[i];

                id = i;

            }

        }

    }

    //cout << M << " " << id << endl;

    //ll ans = M + (dv[id] - du[id] - 1);// + ll(dis-1);

    ll ans = M-1;

    cout << ans << endl;

}