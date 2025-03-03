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

ll a[100500], cnt[100500];

int main() {

    //freopen("input.txt","r",stdin);

    cin >> n >> k;

    for (int i = 0; i < n; i++)

        cin >> a[i];

    for (int i = 0; i+1 < n; i++) {

        if (a[i] + a[i+1] >= k) {

            cout << "Possible" << endl;

            for (int j = 0; j < i; j++)

                cout << j+1 << endl;

            for (int j = n-2; j > i; j--)

                cout << j+1 << endl;

            cout << i+1 << endl;

            return 0;

        }

    }

    cout << "Impossible" << endl;

    return 0;

}
