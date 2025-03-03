#include"stdc++.h"

using namespace std;

#define ll long long

const int maxn = 2e5 + 5;

int l[maxn] , h[maxn];

int main()

{

    ios::sync_with_stdio(false);

    ll n , q; cin >> n >> q;

    ll ans = (n - 2) * (n - 2) , maxl = n , maxh = n;

    for (int i = 2 ; i <= n ; i++){

        l[i] = n;

        h[i] = n;

    }

    while (q--){

        int op , x; cin >> op >> x;

        if (op == 1){

            if (x < maxl){

                for (int i = x ; i <= maxl - 1 ; i++) l[i] = maxh;

                maxl = x;

            }

            ans -= l[x] - 2;

        }else {

            if (x < maxh){

                for (int i = x ; i <= maxh - 1 ; i++) h[i] = maxl;

                maxh = x;

            }

            ans -= h[x] - 2;

        }

    }

    cout << ans << endl;

    return 0;

}
