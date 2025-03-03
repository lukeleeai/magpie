#include "stdc++.h"



#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)

#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)

#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)

#define setp(n) fixed << setprecision(n)



template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



#define ll long long

#define vll vector<ll>

#define vi vector<int>

#define pll pair<ll,ll>

#define pi pair<int,int>



#define all(a) (a.begin()),(a.end())

#define rall(a) (a.rbegin()),(a.rend())

#define fi first

#define se second

#define pb push_back

#define ins insert



#define debug(a) cerr<<(a)<<endl

#define dbrep(a,n) rep(_i,n) cerr<<(a[_i])<<" "; cerr<<endl

#define dbrep2(a,n,m) rep(_i,n){rep(_j,m) cerr<<(a[_i][_j])<<" "; cerr<<endl;}



using namespace std;



template<class A, class B>

ostream &operator<<(ostream &os, const pair<A,B> &p){return os<<"("<<p.fi<<","<<p.se<<")";}

template<class A, class B>

istream &operator>>(istream &is, pair<A,B> &p){return is>>p.fi>>p.se;}



/* Some Libraries */



//-------------------------------------------------



int main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    int N,K; cin>>N>>K;

    vi P(N);

    vll C(N);

    rep(i,N) cin>>P[i], P[i]--;

    rep(i,N) cin>>C[i];



    ll ans=(ll)-1e18;

    rep(i,N){

        ll cand=0;

        vll vec;

        vec.pb(C[i]);

        int cur=P[i];

        while(cur!=i){

            vec.pb(C[cur]);

            cur = P[cur];

        }

        int V = vec.size();

        vll sum(V+1);

        rep(i,V) sum[i+1]=sum[i]+vec[i];

        ll S = sum[V];

        rep(i,V-1) chmax(sum[i+2],sum[i+1]);

        if (S>0){

            // Max

            int t = K/V;

            cand = S*t + sum[K%V];

            // Max-1

            if (t>0){

                t = K/V-1;

                chmax(cand,S*t + sum[V]);

            }

        }else{

            cand = sum[min(K,V)];

        }

        chmax(ans,cand);

    }

    cout<<ans<<"\n";

    return 0;

}
