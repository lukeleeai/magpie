#include "stdc++.h"



using namespace std;



//#define _FILES

#define PB push_back

#define MP make_pair

#define X first

#define Y second

const int MAXN = 2005;



int f[MAXN][MAXN], h[MAXN][MAXN], v[MAXN][MAXN], c[MAXN][MAXN];



int main()

{

    ios_base::sync_with_stdio(false);



    #ifdef _FILES

        freopen("","r",stdin);

        freopen("","w",stdout);

    #endif // _FILES

    int n, m, q;

    cin >> n >> m >> q;

    for (int i=1;i<=n;i++)

    {

        string s;

        cin >> s;

        for (int j=0;j<m;j++)

        {

            if (s[j] == '1')

            {

                f[i][j+1] = 1;

            }

        }

    }



    for (int i=n;i>=1;i--)

    {

        for (int j=m;j>=1;j--)

        {

            c[i][j] = c[i+1][j] + c[i][j+1] - c[i+1][j+1];



            if (f[i][j])

            {

                c[i][j]++;

                if (f[i+1][j])

                {

                    c[i][j]--;

                }



                if (f[i][j+1])

                {

                    c[i][j]--;

                }

            }



            v[i][j] = v[i+1][j];

            if ((f[i][j]) && (f[i][j+1]))

            {

                v[i][j]++;

            }



            h[i][j] = h[i][j+1];

            if ((f[i][j]) && (f[i+1][j]))

            {

                h[i][j]++;

            }

        }

    }



    for (int i=0;i<q;i++)

    {

        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int ans = c[x1][y1] + h[x2][y1] - h[x2][y2+1] + v[x1][y2] - v[x2+1][y2] - c[x2+1][y1] - c[x1][y2+1] + c[x2+1][y2+1];

        cout << ans << "\n";

    }

    return 0;

}


