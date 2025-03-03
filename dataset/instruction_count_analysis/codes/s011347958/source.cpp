#include <iostream>

#include <vector>

#include <deque>

#include <math.h>

#include <set>

#include <iomanip>

#include <time.h>

#include <list>

#include <stdio.h>

#include <queue>

#include <map>

#include <algorithm>

#include <assert.h>

#include <memory.h>



#define mk make_pair

#define sc second

#define fr first

#define pb push_back

#define sz(s) ( (int)s.size() )

#define all(s) s.begin(), s.end()



using namespace std;



const int N = 1e5 + 5;



int n, m, ar[N], cur[N], ans, mx[N], cnt, sum;



vector <int> g[N], V;



vector <pair <int, int> > vec;



main ()

{

    cin >> n >> m;

    for (int i = 1; i <=n; i++)

    {

        scanf("%d", &ar[i]), cur[ ar[i] % m ]++;



        g[ ar[i] % m ].pb( ar[i] );

    }



    ans = cur[0] >> 1;



    for (int i = 1; i < (m + 1) / 2; i++)

    {

        if (cur[i] >= cur[m - i])

        {

            ans += cur[m - i];

            vec.pb( mk( cur[i] - cur[m - i], i ) );

        }

        else

        {

            ans += cur[i];

            vec.pb( mk( cur[m - i] - cur[i], m - i ) );

        }

    }

    if (m % 2 == 0)

        ans += cur[m / 2] >> 1;



    for (auto x : vec)

    {

//        V.clear();



        sum = 0;

        cnt = 1;



        int v = x.sc, col = x.fr;



        sort(all(g[v]));



        for (int j = 1; j < sz(g[v]); j++)

        {

            if ( g[v][j] == g[v][j - 1] )

                cnt++;

            else

            {

                sum += (cnt - (cnt % 2));

//                V.pb(cnt - (cnt % 2) );

                cnt = 1;

            }

        }

        sum += (cnt - (cnt % 2));

//        V.pb( cnt - (cnt % 2) );

//        sort( all(V), greater<int>() );

        ans += min( sum, col ) / 2;

    }



    cout << ans << endl;

}
