#include"stdc++.h"

using namespace std;

#define ALL(x) x.begin(),x.end()

#define rep(i,n) for(int i=0;i<n;i++)

#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 

#define INF 1000000000

#define mod 1000000007

using ll=long long;

const ll LINF = 1001002003004005006ll;

int dx[]={1,0,-1,0};

int dy[]={0,1,0,-1};

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n,k;

vector<ll> h;



inline ll cost(int a,int b){

    return (max(0ll,h[b]-h[a]));

}



signed main(){

    cin.tie(0);

    ios::sync_with_stdio(0);

    

    cin>>n>>k;

    h.resize(n+1);

    rep(i,n) cin>>h[i+1];

    h[0]=0;



    if(k>=n){

        cout<<0<<endl;

        return 0;

    }



    ll dp[n+1][k+1];

    rep(i,n+1){

        rep(j,k+1){

            dp[i][j]=INF*100ll;

        }

    }

    dp[0][0]=0;



    rep(j,k+1){

        rep(i,n){

            for(int l=0;l<=k and j-l>=0 and i-l>=0;l++){

                chmin(dp[i+1][j],dp[i-l][j-l]+cost(i-l,i+1));

            }

        }

    }

    // rep(j,k+1){

    //     rep(i,n+1){

    //         cout<<dp[i][j]<<"  ";

    //     }cout<<endl;

    // }

    ll ans=LINF;

    rep(i,k+1){

        chmin(ans,dp[n-i][k-i]);

    }

    cout<<ans<<endl;

    return 0;

}
