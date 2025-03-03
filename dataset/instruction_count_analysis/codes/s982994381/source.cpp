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

    ll N, M;

    cin >> N >> M;

    vector<ll> A(N-1+M), B(N-1+M), niv(N), S;

    vector<vector<ll>> G(N), H(N);

    rep(i,N-1+M){

        cin >> A[i] >> B[i];

        A[i]--;B[i]--;

        G[A[i]].push_back(B[i]);

        H[B[i]].push_back(A[i]);

    }

    rep(i,N-1+M){

        niv[B[i]]++;

    }

    queue<ll> que;

    vector<ll> memo(N);

    rep(i,N){

        if(niv[i] == 0){

            que.push(i);

            S.push_back(i);

            memo[i] = 1;

        }

    }

    //PR(S,S.size());

    while(!que.empty()){

        ll v = que.front();

        que.pop();

        S.push_back(v);

        for(auto& u:G[v]){

            niv[u]--;

            if(niv[u] == 0){

                que.push(u);

            }

        }

    }

    //PR(S,N);

    vector<ll> note(N);

    rep(i,N){

        note[S[i]] = i;

    }

    vector<ll> ans(N);

    rep(i,N){

        ll Mv = -1;

        ll u = -1;

        for(auto& v:H[i]){

            if(Mv < note[v]){

                Mv = note[v];

                u = v;

            }

        }

        ans[i] = u+1;

    }

    rep(i,N){

        cout << ans[i] << endl;

    }

}