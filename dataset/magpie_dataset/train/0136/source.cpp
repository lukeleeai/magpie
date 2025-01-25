#include "bits/stdc++.h"

using namespace std;

#define ll long long int

#define rep(i,n) for( int i = 0; i < n; i++ )

#define REP(i,s,t) for( int i = s; i <= t; i++ )

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define INF 2000000000

#define mod 1000000007

#define INF2 1000000000000000000



int kk[1100001];

int n, m;



int binary_search(int x) {

    if (x <= 0) return 0;

    int l = 0, r = n * n;

    //dump(r - l);

    int i = 0;

    while(r - l >= 1) {

        i = (l + r) / 2;

        if (kk[i] == x) return i;

        else if (kk[i] < x) l = i + 1;

        else r = i;

    }

    while(kk[i] > x) i--;

    return i;

}



int main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    while(true){

        cin >> n >> m;

        if(n == 0 && m == 0) return 0;

        int k[n+1];

        k[0] = 0;

        rep(i, n) cin >> k[i+1];

        rep(k, 1100001) kk[k] = 0;

        rep(c, n+1) {

            rep(d, n+1) {

                kk[c * n + d] = k[c] + k[d];

            }

        }



        sort(kk, kk + (n+1) * (n+1));

        int ans = 0;

        rep(a, n+1) {

            rep(b, n+1) {

                int index = binary_search(m - k[a] - k[b]);

                int tmp = kk[index] + k[a] + k[b];

                if(tmp <= m) ans = max(ans, tmp);

                tmp = kk[index+1] + k[a] + k[b];

                if(tmp <= m) ans = max(ans, tmp);



            }

        }

        cout << ans << endl;

    }



    return 0;

}


