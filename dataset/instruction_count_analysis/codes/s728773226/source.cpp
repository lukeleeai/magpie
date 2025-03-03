#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)

long long mo = 1e9 + 7;

typedef long long ll;

typedef long double ld;

typedef pair<int,int> Pii;

typedef pair<ll,ll> Pll;

template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }

template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

ld PI=3.14159265358979323846;



int main(){

    ll N,D,A;

    cin >> N >> D >> A;

    vector<Pll> P(N);

    rep(i,N){

        cin >> P[i].first >> P[i].second;

    }

    sort(P.begin(), P.end());

    queue<Pll> que;

    ll Ac = 0;

    ll ans = 0;

    rep(i,N){

        ll X = P[i].first;

        ll H = P[i].second;

        while(!que.empty() && X >= que.front().first){

            Ac -= A*que.front().second;

            que.pop();

        }

        if(H > Ac){

            ll n = ((H-Ac)+A-1)/A;

            que.push(Pll(X+2*D+1, n));

            Ac += A*n;

            ans += n;

        }else{

            continue;

        }

    }

    cout << ans << endl;

}