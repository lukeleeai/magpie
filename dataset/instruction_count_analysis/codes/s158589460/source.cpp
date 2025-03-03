#include"stdc++.h"

#define taskname "test1"

#define int long long

using namespace std;



main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);   cout.tie(nullptr);

    if (ifstream("test.inp"))

    {

        freopen("test.inp", "r", stdin);

        #ifdef CHECKING

            freopen(taskname".out", "w", stdout);

        #else

            freopen("test.out", "w", stdout);

        #endif //CHECKING

    }

    else if (ifstream(taskname".inp"))

    {

        freopen(taskname".inp", "r", stdin);

        freopen(taskname".out", "w", stdout);

    }



    int n, m;   cin >> n >> m;

    vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= m; ++j)

        {

            char c; cin >> c;

            s[i][j] = c == '#';

            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

        }

    for (int i = 1; i <= n; ++i)

    {

        bool ok = false;

        for (int j = 1; j <= m; ++j)

            if (s[i][m] - s[i - 1][m] && s[n][j] - s[n][j - 1])

            {

                ok = true;

                int x = s[i][j] - s[i - 1][j] - s[i][j - 1] + s[i - 1][j - 1];

                if (x) cout << '#';

                else cout << '.';

            }

        if (ok) cout << '\n';

    }

}
