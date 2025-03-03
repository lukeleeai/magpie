#include "stdc++.h"

using namespace std;

typedef long long ll;

#define i_7 (ll)(1E9+7)

#define i_5 (ll)(1E9+5)

ll mod(ll a){

    ll c=a%i_7;

    if(c>=0)return c;

    else return c+i_7;

}

typedef pair<int,int> i_i;

typedef pair<ll,ll> l_l;

ll inf=(ll)1E12;

#define rep(i,l,r) for(ll i=l;i<=r;i++)

#define pb push_back

ll max(ll a,ll b){if(a<b)return b;else return a;}

ll min(ll a,ll b){if(a>b)return b;else return a;}

void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);

void Min(ll * pos,ll val){*pos=min(*pos,val);}

void Add(ll * pos,ll val){*pos=mod(*pos+val);}

const long double EPS=1E-8;

////////////////////////////////////////





struct tower{

    ll w,s,v;

};

bool comp(tower t1,tower t2){

    if(t1.w+t1.s<t2.w+t2.s)return true;

    else return false;

}



int main(){

    ll n;cin>>n;

    tower t[n];

    rep(i,0,n-1){

        cin>>t[i].w>>t[i].s>>t[i].v;

    }

    sort(t,t+n,comp);

    ll N=30005;

    ll dp[n+1][N];

    memset(dp,0,sizeof(dp));

    rep(i,0,n-1){

        rep(j,0,N-1){

            dp[i+1][j]=dp[i][j];

            if(0<=j-t[i].w&&j-t[i].w<=t[i].s)Max(&dp[i+1][j],dp[i][j-t[i].w]+t[i].v);

        }

    }

    /*rep(i,0,n){

        rep(j,0,20){

            cout<<dp[i][j]<<" ";

        }cout<<endl;

    }*/

    ll ans=0;rep(i,0,N-1)Max(&ans,dp[n][i]);

    cout<<ans<<endl;

    return 0;

}








