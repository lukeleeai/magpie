#include"stdc++.h"

#define rep(i,N) for(int i=0;i<(N);i++)

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

const long long MOD = 1e9 + 7;

const long long INF = 1e12;

const int inf = 1e9;

typedef long long ll;

typedef pair<ll,int> P;

typedef set<int> S;

int main(){

    int n,k;

    cin>>n>>k;

    set<ll> sll;

    vector<ll> v(200010,0);

    rep(i,200010){

        v[i+1]=v[i]+i+1;

    }

    //ll left = MOD+1;

    //ll right = 0;

    ll ans = 0;

    for(int i=k;i<=n;i++){

        ll ans1=0,ans2=0;

        ans1 = v[i-1];

        ans2 = v[n]-v[n-i];

        /*cout<<i<<endl;

        cout<<v[i-1]<<" "<<v[n]<<" "<<v[n-i]<<endl;

        cout<<ans1<<" "<<ans2<<endl;*/

        ans=(ans+ans2-ans1+1)%MOD;

        //cout<<ans<<endl<<endl;

    }

    cout<<ans+1<<endl;

    return 0;

}