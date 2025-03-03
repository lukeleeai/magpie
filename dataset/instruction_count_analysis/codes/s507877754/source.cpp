#include "stdc++.h"

#define INF 1e18

#define int long long

#define Rep(i, a, n) for (int i = (a); i < (n); i++)

#define rep(i, n) Rep(i, 0, n)

#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> P;

typedef pair<int, P> PP;

const int mod = 1000000007;



signed main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);



    int b;

    while (cin >> b, b)

    {

        int ans1, ans2;

        for (int i = 1; i * (i + 1) / 2 <= b; i++)

        {

            //s * i + i * (i - 1) / 2 = b

            if ((2 * b - i * (i - 1)) % (2 * i) == 0)

            {

                ans1 = ((2 * b - i * (i - 1)) / (2 * i));

                ans2 = i;

            }

        }

        cout << ans1 << " " << ans2 << endl;

    }

}
