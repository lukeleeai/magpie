#include "stdc++.h"



using namespace std;

#define all(a)a.begin(),a.end()

using ll=long long;

const int INF = 1<<30;

const ll INFll =1LL<<62;

const int mod = int(1e9)+7;

using P = pair<ll,ll>;

using ld=long double;



int main(){

    ll U=3010;

    ll MOD=998244353;

    ll n,s;cin >>n>>s;

    vector<ll>a(n);

    for (int i = 0; i < n; ++i) {

        cin >>a[i];

    }

    vector<vector<ll>>dp(n+1,vector<ll>(U+1,0));

    dp[0][0]=1;

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < U; ++j) {

            dp[i+1][j]+=dp[i][j]*2%MOD;

            dp[i+1][j]%=MOD;

            if(j+a[i]>U)continue;

            dp[i+1][j+a[i]]+=dp[i][j];

            dp[i+1][j+a[i]]%=MOD;

        }

    }

    cout <<dp[n][s]<<endl;

    return 0;

}