#include"stdc++.h"

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;



vector<ll> a(200000);



int main(void){

    ll n, k;

    cin >> n >> k;

    rep(i, n) cin >> a[i];

    ll l = 1, h = *max_element(a.begin(), a.begin() + n);

    while(l < h){

        ll mid = (l + h) / 2, cnt = 0;

        rep(i, n){

            cnt += a[i] / mid;

            if(a[i] % mid == 0) --cnt;

        }

        if(cnt <= k) h = mid;

        else l = mid + 1;

    }

    cout << h << endl;

    return 0;

}