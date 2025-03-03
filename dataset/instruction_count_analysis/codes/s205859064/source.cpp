#include "stdc++.h"

using namespace std;



#define int long long

#define fi first

#define se second

#define sz(x) (int)(x).size()

#define all(x) (x).begin(), (x).end()

#define yn(x) ((x) ? "YES" : "NO")



typedef pair <int, int> ii;

typedef pair <int, ii> iii;



const int siz = 3e5 + 10;

const int SIZ = 1e6 + 10;

const int mod = 1e9 + 7;

const int maxx = 2e9;

const int MAXX = 1e18;

const string file = "2";



int a[siz];

int mxl[siz], mnr[siz];



int32_t main() {

    ios::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);



//    freopen ((file + ".inp").c_str(), "r", stdin);

//    freopen ((file + ".out").c_str(), "w", stdout);



    int n;

    cin >> n;



    for (int i = 1; i <= 3 * n; i++) {

        cin >> a[i];

    }



    int suml = 0;

    priority_queue <int, vector <int>, greater <int> > pql;

    for (int i = 1; i <= n; i++) {

        suml += a[i];

        pql.push(a[i]);

    }



    mxl[n] = suml;

    for (int i = n + 1; i <= 2 * n; i++) {

        pql.push(a[i]);

        suml += a[i];

        suml -= pql.top();

        pql.pop();

        mxl[i] = suml;

    }



    int sumr = 0;

    priority_queue <int> pqr;

    for (int i = 2 * n + 1; i <= 3 * n; i++) {

        sumr += a[i];

        pqr.push(a[i]);

    }



    mnr[2 * n + 1] = sumr;

    for (int i = 2 * n; i >= n + 1; i--) {

        pqr.push(a[i]);

        sumr += a[i];

        sumr -= pqr.top();

        pqr.pop();

        mnr[i] = sumr;

    }



    int ans = -MAXX;

    for (int i = n; i <= 2 * n; i++) {

        ans = max(ans, mxl[i] - mnr[i + 1]);

    }



    cout << ans << "\n";



//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";



    return 0;

}
