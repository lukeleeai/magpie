#include"stdc++.h"

#define god dimasi5eks

#pragma GCC optimize("O3")

#define fi first

#define se second

#define pb push_back

#define pf push_front

#define mod 1000000007

#define dancila 3.14159265359

#define eps 1e-9



using namespace std;



typedef long long ll;



int h, w, n;

set<int> s[200002];



int main()

{



    // ifstream cin("a.in");

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    cin >> h >> w >> n;

    for(int i = 1; i <= n; ++i)

    {

        int a, b;

        cin >> a >> b;

        s[b].insert(a);

    }

    for(int i = 1; i <= w; ++i)

        s[i].insert(h+1);

    int ans = (1<<20);

    int col = 1;

    for(int i = 1; i <= h; ++i)

    {

        ans = min(ans, (*s[col].lower_bound(i+1)) - 1);

        if(col < w && *s[col+1].lower_bound(i+1) != i+1)

            ++col;

    }

    cout << ans << '\n';

    return 0;

}
