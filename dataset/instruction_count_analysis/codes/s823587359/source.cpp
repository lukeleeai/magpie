#include "stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

#define VL vector<ll>

#define VS vector<string>

#define VB vector<bool>

#define VP vector<pair<ll,ll>>

#define VVL vector<vector<ll>>

#define VVP vector<vector<pair<ll,ll>>>

#define PL pair<ll,ll>

#define ALL(v) (v).begin(), (v).end()

ll d1[4] = {1, -1, 0, 0};

ll d2[4] = {0, 0, 1, -1};



int main(){

    ll n, k;

    cin >> n >> k;

    vector<ll> a(n);

    rep(i, 0, n) cin >> a[i];



    ll itr = 0;

    bool exi = true;

    while(itr < k && exi){

        bool f = false;

        vector<ll> imos(n+1, 0);

        rep(i, 0, n){

            if(a[i] != n) f = true;

            imos[max(0LL, i - a[i])]++;

            imos[min(n, i + a[i] + 1)]--;

        }

        ll acc = 0;

        rep(i, 0, n){

            acc += imos[i];

            a[i] = acc;

        }

        exi = f;

        itr++;

    }



    rep(i, 0, n-1) cout << a[i] << " ";

    cout << a[n-1] << endl;

    return 0;

}