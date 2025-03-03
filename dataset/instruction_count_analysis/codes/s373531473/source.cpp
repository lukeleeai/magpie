#include "stdc++.h"

using namespace std;



#define rep(i,n) for(i = 0;i < n;++i)

#define all(v) v.begin(), v.end()

using ll = long long;



int main()

{

    ll i,j;

    ll n,x,m;

    cin >> n >> x >> m;

    vector<vector<ll>> dub(m, vector<ll>(40, -1));

    vector<vector<ll>> dubsum(m, vector<ll>(40, 0));

    rep(i, m){

        dub[i][0] = i*i%m;

    }

    rep(i, 39){

        rep(j,m){

            dub[j][i + 1] = dub[dub[j][i]][i];

        }

    }

    rep(i,m){

        dubsum[i][0] = i;

    }

    rep(i,39){

        rep(j,m){

            dubsum[j][i+1] = dubsum[j][i] + dubsum[dub[j][i]][i];

        }

    }

    ll ans = 0;

    ll bit = 0;

    ll now = x;

    while(n){

        if(n & 1){

            ans += dubsum[now][bit];

            now = dub[now][bit];

        }

        ++bit;

        n >>= 1;

    }

    cout << ans << endl;



    return 0;

}