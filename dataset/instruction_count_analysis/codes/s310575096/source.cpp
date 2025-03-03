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

    vector<ll> spare(m, -1);

    ll now = x;

    /**

    if(n <= 1e7){

        ll ans = 0;

        ll now = x;

        rep(i,n){

            ans += now;

            now = now*now%m;

        }

        cout << ans << endl;

        return 0;

    }**/

    rep(i,m){

        if(spare[now] != -1) break;

        else{

            spare[now] = i;

            now = now*now%m; 

        }

    }

    ll start = spare[now];

    ll end = i;

    ll shuuki = end-start;

    now = x;

    ll ans = 0;

    for(i = 0;i < start;++i){

        ans += now;

        now = now*now%m;

        --n;

        if(n == 0){

            cout << ans << endl;

            return 0;

        }

    }

    ll kurikaesi = 0;

    for(i = start;i < end;++i){

        kurikaesi += now;

        now = now*now % m;

    }

    ans += n/shuuki*kurikaesi;

    n %= shuuki;

    while(n){

        ans += now;

        now = now*now%m;

        --n;

    }

    cout << ans << endl;



    return 0;

}
