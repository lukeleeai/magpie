#include"stdc++.h"

#define rep(i,a,b) for(int i=a;i<b;i++)

#define rrep(i,a,b) for(int i=a;i>=b;i--)

#define fore(i,a) for(auto &i:a)

#define all(x) (x).begin(),(x).end()

//#pragma GCC optimize ("-O3")

using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

void _main()

{

    int A, B;

    cin >> A >> B;



    --A;

    --B;



    vector<string> table(100);

    rep(i, 0, 100)

    {

        table[i] = string(100, i < 50 ? '.' : '#');

    }



    {

        int r = 51;

        int c = 0;

        while (A > 0)

        {

            table[r][c] = '.';

            c += 2;

            if (c >= 100)

            {

                r += 2;

                c = 0;

            }

            --A;

        }

    }



    {

        int r = 1;

        int c = 0;

        while (B > 0)

        {

            table[r][c] = '#';

            c += 2;

            if (c >= 100)

            {

                r += 2;

                c = 0;

            }

            --B;

        }

    }



    cout << "100 100" << endl;

    for (const string& s : table)

    {

        cout << s << endl;

    }

}
