#include "stdc++.h"

#define mp make_pair

#define X first

#define Y second

#define pii pair<ll,ll>

#define x1 dlfjl

#define x2 dkfj

#define x3 dflgkg

#define y1 dskgj

#define y2 dskfj

#define y3 dfhgdh

#define SQ 320

#define PI 3.14159265359

#define MOD 1000000007

typedef int ll;

using namespace std;

ll n,i,j,k,z,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;

ll a[100500], cnt[100500], col[100500];

ll dp[105][105][105];

void ass(ll i, ll j, ll k, ll val) {

    dp[i][j][k] = dp[i][k][j] = dp[j][i][k] = dp[j][k][i] = dp[k][i][j] = dp[k][j][i] = val;

}

bool ss(ll x, ll y) {

    if (min(x,y) == 0 && (x != 0 || y != 0))

        return false;

    return true;

}

int main() {

    //freopen("input.txt","r",stdin);

    cin >> n;

    for (int i = 0; i < n; i++)

        cin >> a[i];

    sort(a, a+n);

    reverse(a, a+n);

    int i = 0, j = 0;

    while (i+1 < n && j+1 < a[i+1])

        i++, j++;

        ll x = a[i]-j;

        ll y = 0;

        while (i+1 < n && j < a[i+1])

            y++, i++;

        //cout << x << " " << y << endl;

        if (x%2 && y % 2 == 0)

            cout << "Second" << endl;

        else

            cout << "First" << endl;

    return 0;

}
